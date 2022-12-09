#include <Arduino.h>
#include <communicator.h>

communicator comm;
 
void setup() {
    comm.startCommunicator();
}

void loop() {
    comm.updateCommunicator();
}