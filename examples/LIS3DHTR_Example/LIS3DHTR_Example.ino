#include "LIS3DHTR.h"

// if you use the software I2C to drive the sensor, you can uncommnet the define SOFTWAREWIRE which in LIS3DHTR.h. 
#ifdef SOFTWAREWIRE
  #include <SoftwareWire.h>
  SoftwareWire myWire(3, 2);
  LIS3DHTR<SoftwareWire> LIS(0);
  #define WIRE myWire
#else   
  #include <Wire.h>
  // LIS3DHTR<TwoWire> LIS(0);//I2C
  LIS3DHTR<TwoWire> LIS(1);//SPI
   #define WIRE Wire
#endif


void setup()
{
  Serial.begin(115200);
  while(!Serial){};
  // LIS.begin(WIRE,0x19);//IIC address
  LIS.begin(10);          //SPI SS
  // LIS.openTemp();
  LIS.closeTemp();//default
  delay(100);
  // LIS.setFullScaleRange(LIS3DHTR_RANGE_2G);
  //LIS.setFullScaleRange(LIS3DHTR_RANGE_4G);
  //LIS.setFullScaleRange(LIS3DHTR_RANGE_8G);
  //LIS.setFullScaleRange(LIS3DHTR_RANGE_16G);
  //LIS.setOutputDataRate(LIS3DHTR_DATARATE_1HZ);
  //LIS.setOutputDataRate(LIS3DHTR_DATARATE_10HZ);
  // LIS.setOutputDataRate(LIS3DHTR_DATARATE_25HZ);
  // LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
  //LIS.setOutputDataRate(LIS3DHTR_DATARATE_100HZ);
  // LIS.setOutputDataRate(LIS3DHTR_DATARATE_200HZ);
  //LIS.setOutputDataRate(LIS3DHTR_DATARATE_1_6KHZ);
  // LIS.setOutputDataRate(LIS3DHTR_DATARATE_5KHZ);
}
void loop()
{
  if(!LIS){
    Serial.println("LIS3DHTR didn't connect.");
    while(1);
    return;
  }
  Serial.print("x:");Serial.print(LIS.getAccelerationX());Serial.print("  ");
  Serial.print("y:");Serial.print(LIS.getAccelerationY());Serial.print("  ");
  Serial.print("z:");Serial.println(LIS.getAccelerationZ());

  // Serial.print("adc1:");Serial.println(LIS.readbitADC1());
  // Serial.print("adc2:");Serial.println(LIS.readbitADC2());
  // Serial.print("adc3:");Serial.println(LIS.readbitADC3());

  // Serial.print("temp:");Serial.println(LIS.getTemperature());
  delay(500);
}
