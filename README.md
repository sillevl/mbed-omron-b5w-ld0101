# mbed-omron-b5w-ld0101

mbed library for the Omron B5W-LD0101 air quality sensor.

More information about this sensor is found in the [datasheet](https://omronfs.omron.com/en_US/ecb/products/pdf/en_b5w-ld0101-1_2.pdf)



## Getting started

Create a new mbed app:

```
mbed new myapp
```

Add the library as a dependency

```
mbed add https://github.com/sillevl/mbed-omron-b5w-ld0101
```

## Example

```cpp
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
```