#pragma once

#include "mbed.h"

class AirQualitySensor 
{

public:

  enum Status { READY, MEASURING, STOPPED, DONE };
  
  AirQualitySensor(PinName out1, PinName out2);

  void start();
  void stop();
  bool isMeasuring();
  bool isReady();
  bool isDone();
  Status getStatus();

  int getPM10();
  int getPM2_5();

 private:
  int pm10_count;
  int pm2_5_count;

  Status status;

  InterruptIn _out1;
  InterruptIn _out2;
  Timeout timer;

  static const float MEASUREMENT_TIME = 20.0;

  void countPM10();
  void countPM2_5();

  void reset();
  void done();

};