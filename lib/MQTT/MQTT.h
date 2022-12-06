#ifndef MQTT_h
#define MQTT_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class MQTT
{
public:
    void start();
    void readMSG(char *msg);
};

#endif