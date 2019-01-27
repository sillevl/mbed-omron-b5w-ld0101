#include "mbed.h"
#include "AirQualitySensor.h"

Serial pc(USBTX, USBRX);

int main()
{
  AirQualitySensor sensor(D6, D7);
  while(true){
    pc.printf("Starting measurement...\r\n");
    sensor.start();
    while(sensor.isMeasuring()){
      wait_ms(100);
    }
    pc.printf("Sensor Ready\r\n");
    pc.printf(" PM10:  %d\r\n", sensor.getPM10());
    pc.printf(" PM2.5: %d\r\n", sensor.getPM2_5());
  }
}