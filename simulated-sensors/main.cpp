#include "SimulatedSensors.hpp"

int main(){
    thread sensor_0(EmitMeasurement, 0);
    thread sensor_1(EmitMeasurement, 1);
    thread receiver(ReceiveMeasurement);
    sensor_0.join();
    sensor_1.join();
    receiver.join();
    cond_var.notify_all();
}