#include <Arduino.h>
#include <MQTT.h>
#include <alerter.h>
#include <communicator.h>

char msg [5];

MQTT mqtt;
alerter alert;

void communicator::startCommunicator(){
    Serial.begin(115200);
    Serial.println("Starting communications");
    mqtt.start();
    alert.start();
}

void communicator::updateCommunicator(){
    Serial.println("Updating communications");
    mqtt.readMSG(msg);
    alert.alertMsg(msg);
}
