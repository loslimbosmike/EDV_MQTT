#include <alerter.h>

byte alertStatus;
byte ledState = 0;
byte ledPin = 5;
long currTime;
long prvTime;
long eventTime = 600;

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
void alerter::start()
{
    pinMode(ledPin, OUTPUT);
}
void alerter::alertMsg(char *msg)
{
    char _msg = msg[0];

    if (_msg == '0' || _msg == '1')
    {
        alertStatus = (_msg == '1') ? 1 : 0;
        alert();
    }
    else
    {
        Serial.println("No valid message");
    }
}
