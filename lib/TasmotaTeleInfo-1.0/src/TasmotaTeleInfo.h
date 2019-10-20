#define debug

#include "Arduino.h"
#include <SPI.h>
#include <TasmotaSerial.h>

class TeleInfo
{
public:
  TeleInfo(String version);
  void displayTeleInfo();

private:
  char HHPHC;

  int ISOUSC;             // intensité souscrite  
  int IINST;              // intensité instantanée en A
  int IMAX;               // intensité maxi en A
  int PAPP;               // puissance apparente en VA
  unsigned long HCHC;     // compteur Heures Creuses en W
  unsigned long HCHP;     // compteur Heures Pleines en W
  String PTEC;            // Régime actuel : HPJB, HCJB, HPJW, HCJW, HPJR, HCJR
  String ADCO;            // adresse compteur
  String OPTARIF;         // option tarifaire
  String MOTDETAT;        // status word
  String pgmVersion;      // TeleInfo program version
  
  char chksum(char *buff, uint8_t len);
  boolean handleBuffer(char *bufferTeleinfo, int sequenceNumnber);
  TasmotaSerial swSerial(uint8_t rxPin, uint8_t rxPin);
};


