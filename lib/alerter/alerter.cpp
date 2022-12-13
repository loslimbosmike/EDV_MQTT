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
    Serial.println(ledState);
    digitalWrite(ledPin, ledState);
}
void alerter::start()
{
    pinMode(ledPin, OUTPUT);
}
void alerter::alertMsg(char* msg)
{
    char _msg = msg[0];
    Serial.print("MSG: ");
        Serial.println(_msg);
    delay(2000);

    if (_msg == '0' || _msg == '1')
    {
        alertStatus = (byte)_msg;
        alert();
    }
    else
    {
        Serial.println("No valid message");
    }
}
