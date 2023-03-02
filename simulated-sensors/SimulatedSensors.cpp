#include "SimulatedSensors.hpp"


static constexpr auto kSensorEmitFrequencyHz = 13;
static constexpr auto kSensorEmitInterval = chrono::duration<double>(double(1.0f/kSensorEmitFrequencyHz)) ;
static constexpr auto kSensorShutDownTimeS = 1.5s;
static constexpr auto kReceiverShutDownTimeS = 200ms;

static optional<double> measurements[2] = {};

static const auto start_time = chrono::steady_clock::now();

double time_variant_signal(double t_s, int modifier){
    return -(1.0f/16)*(t_s-30+modifier)*sin(t_s)+1;
}

void EmitMeasurement(int sensor_number){

    chrono::time_point sensor_timeout_time = start_time + kSensorShutDownTimeS;
    while (true) {
        unique_lock lk(measurement_sent_mutex);
        if (cond_var.wait_for(lk,kSensorEmitInterval) == cv_status::timeout){
            if(chrono::steady_clock::now() < sensor_timeout_time)
            {
                auto time = double(chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start_time).count())/1000000;
                measurements[sensor_number] = time_variant_signal(time,sensor_number);
            }else
            {
                cout << "Sensor thread done" << endl;
                break;
            }
            lk.unlock();
            cond_var.notify_all();
        }
    }
}

void ReceiveMeasurement(){

    optional<double> readings_in_order[2];
    int readings_index = 0;
    while(true){
        unique_lock lk(measurement_sent_mutex);
        if (cond_var.wait_for(lk,kReceiverShutDownTimeS,[&readings_in_order, &readings_index](){
            return any_of(begin(measurements), end(measurements), [&readings_in_order, &readings_index](optional<double> &measurement)
            {if(measurement.has_value()){
                readings_in_order[readings_index] = measurement;
                readings_index++;
                measurement.reset();
                return true;
            }return false;}
            );})){

            if(all_of(begin(readings_in_order), end(readings_in_order), [](optional<double> reading)
                      {return reading.has_value();}))
            {
                auto value_difference = readings_in_order[1].value() - readings_in_order[0].value();
                const auto time_elapsed = chrono::duration_cast<chrono::microseconds>(
                chrono::steady_clock::now() - start_time );
                cout << "Got measurements [t= " <<  double(time_elapsed.count())/1000 <<  "ms] with difference " << value_difference << endl;
                for_each(begin(readings_in_order), end(readings_in_order), [](optional<double> &reading){ reading.reset();});
                readings_index = 0;
            }

            lk.unlock();
            cond_var.notify_all();
        }else{
            cout << "Receiver thread timed out, shutting down " << endl;
            break;
        }
    }
}

