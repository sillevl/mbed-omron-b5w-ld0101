#include "AirQualitySensor.h"

AirQualitySensor::AirQualitySensor(PinName out1, PinName out2)
  : _out1(out1), _out2(out2) 
{
  reset();
  _out1.rise(mbed::callback(this, &AirQualitySensor::countPM10));
  _out2.rise(mbed::callback(this, &AirQualitySensor::countPM2_5));
}

void AirQualitySensor::reset(){
  _out1.disable_irq();
  _out2.disable_irq();
  pm10_count = 0;
  pm2_5_count = 0;
  status = READY;
}

void AirQualitySensor::start(){
  reset();
  _out1.enable_irq();
  _out2.enable_irq();
  timer.attach(mbed::callback(this, &AirQualitySensor::done), MEASUREMENT_TIME);
  status = MEASURING;
}

void AirQualitySensor::stop(){
  timer.detach();
  status = STOPPED;
}

void AirQualitySensor::done(){
  stop();
  status = DONE;
}

void AirQualitySensor::countPM10(){
  pm10_count++;
}

void AirQualitySensor::countPM2_5(){
  pm2_5_count++;
}

AirQualitySensor::Status AirQualitySensor::getStatus(){
  return status;
}

int AirQualitySensor::getPM10(){
  return pm10_count;
}

int AirQualitySensor::getPM2_5(){
  return pm2_5_count;
}

bool AirQualitySensor::isMeasuring(){
  return status == MEASURING;
}

bool AirQualitySensor::isDone(){
  return status == DONE;
}

bool AirQualitySensor::isReady(){
  return status == READY;
}