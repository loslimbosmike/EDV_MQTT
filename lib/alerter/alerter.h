#ifndef alerter_h
#define alerter_h

#include <Arduino.h>

class alerter
{
    public:
    void start ();
    void alertMsg (char* msg);
};

#endif