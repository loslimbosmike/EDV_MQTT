#include <Arduino.h>
#include <MQTT.h>
#include <alerter.h>

char msg [5];

MQTT mqtt;
alerter alert;
 
void setup() {
  mqtt.start();
  alert.start();
}

void loop() {
  mqtt.readMSG(msg);
  alert.alertMsg(msg);
}