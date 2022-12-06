#include <alerter.h>

byte alertStatus;
byte ledPin;
long currTime;
long prvTime;
long eventTime = 1000;

void alert();
void start();
void alertMsg(char *msg);