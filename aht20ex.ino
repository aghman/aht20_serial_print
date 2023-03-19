#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_BusIO_Register.h>

#include <Adafruit_AHTX0.h>
 
Adafruit_AHTX0 aht;
 
void setup() {
  Serial.begin(115200);
  Serial.println("AHT20=START");
 
  if (! aht.begin()) {
    Serial.println("AHT20=FALSE");
    while (1) delay(10);
  }
  Serial.println("AHT20=TRUE");
}
 
void loop() {
  sensors_event_t humidity, temp;
  float tempF = 0;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  tempF = (temp.temperature*1.8)+32;
  Serial.print("TC="); 
  Serial.print(temp.temperature); 
  Serial.print(" TF="); 
  Serial.print(tempF); 
  Serial.print(" HM="); 
  Serial.print(humidity.relative_humidity);
  Serial.println("");
 
  delay(5000);
}
