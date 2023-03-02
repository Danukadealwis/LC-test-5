#pragma once

#include <chrono>
#include <thread>
#include <mutex>
#include <ctime>
#include <condition_variable>
#include <iostream>
#include <optional>
#include <cmath>

using namespace std;

static mutex measurement_sent_mutex;
static condition_variable cond_var;

void ReceiveMeasurement();
void EmitMeasurement(int sensor_number);