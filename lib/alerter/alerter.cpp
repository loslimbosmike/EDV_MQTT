#include <alerter.h>

byte alertStatus;
byte ledState = 0;
byte ledPin;
long currTime;
long prvTime;
long eventTime = 1000;

void alert()
{
    if (alertStatus == 1)
    {
        currTime = millis();
        if (currTime - prvTime >= eventTime)
        {
            ledState = !ledState;
            prvTime = currTime;
        }
    }
    else if (alertStatus == 0)
    {
        ledState = alertStatus;
    }
    digitalWrite(ledPin, ledState);
}
void start()
{
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
}
void alertMsg(char *msg)
{
    if (*msg == '0' || *msg == '1')
    {
        alertStatus = (byte)*msg;
        alert();
    }
    else
    {
        Serial.println("No valid message");
    }
}
