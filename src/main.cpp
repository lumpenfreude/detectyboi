#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"
#include <MQ2.h>
#include "MQ7.h"
#include <GP2YDustSensor.h> 

#define LEDPIN 2
#define BEEPER 0
int mq2_analog = 33;
int mq7_analog = 34;
const uint8_t SHARP_LED_PIN = 4;
const uint8_t SHARP_VO_PIN = 35;

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP3XX bmp;
MQ2 mq2(mq2_analog);
MQ7 mq7(mq7_analog,5.0);
GP2YDustSensor dustSensor(GP2YDustSensorType::GP2Y1010AU0F, SHARP_LED_PIN, SHARP_VO_PIN);

void setup() {
  Serial.begin(115200);
  dustSensor.begin();
  mq2.begin();
  bmp.begin_I2C();
  bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
  bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
  bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
  bmp.setOutputDataRate(BMP3_ODR_50_HZ);
}

void loop() {
  Serial.print("Dust density: ");
  Serial.print(dustSensor.getDustDensity());
  Serial.println(" ppm");
  delay(500);
  Serial.print("Carbon Monoxide: ");
  Serial.print(mq7.getPPM());
  Serial.println(" ppm");
  delay(500);
  Serial.print("LPG: ");
  Serial.print(mq2.readLPG());
  Serial.println(" ppm");
  delay(500);
  Serial.print("Smoke: ");
  Serial.print(mq2.readSmoke());
  Serial.println(" ppm");
  delay(500);
  Serial.print("Temperature: ");
  Serial.print(bmp.temperature);
  Serial.println("°C");
  delay(500);
  Serial.print("Barometric Pressure: ");
  Serial.print(bmp.pressure / 100.0);
  Serial.println(" hPa");
  delay(500);
}
