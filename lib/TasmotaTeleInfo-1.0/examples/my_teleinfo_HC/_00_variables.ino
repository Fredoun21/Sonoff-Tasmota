#include "_04_Headers.h"
#include "Arduino.h"
#include <SPI.h>
#include <Ethernet.h>

boolean ethernetIsConnected = false;

byte mac[] = {
  0x90, 0xA2, 0xDA, 0x0E, 0xC2, 0xBD};

TeleInfo* myTeleInfo;
