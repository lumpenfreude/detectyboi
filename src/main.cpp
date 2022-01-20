#include <Arduino.h>

#define MQ7_PINA 34
#define MQ7_PIND 27
#define MQ7_ELED 0
#define MQ2_PINA 35
#define MQ2_PIND 32
#define MQ2_ELED 2
int MQ2limit;
int MQ2value;
int MQ7limit;
int MQ7value;

void setup() {
  Serial.begin(115200);
  pinMode(MQ7_PINA, INPUT);
  pinMode(MQ7_PIND, INPUT);
  pinMode(MQ7_ELED, OUTPUT);
  pinMode(MQ7_PINA, INPUT);
  pinMode(MQ7_PIND, INPUT);
  pinMode(MQ7_ELED, OUTPUT);
}

void loop() {
  MQ2limit = digitalRead(MQ2_PIND);
  MQ2value = analogRead(MQ2_PINA);
  MQ7limit = digitalRead(MQ7_PIND);
  MQ7value = analogRead(MQ7_PINA);
  Serial.print("MQ2 Value: ");
  Serial.println(MQ2limit, MQ2value);
  delay(250);
  Serial.print("MQ7 Value: ");
  Serial.println(MQ7limit, MQ7value);
  delay(250);
}
