void setup() 
{
  Serial.begin(115200);
  Serial.println(F("\nStarting ..."));
  delay(1000);
//  ethernetIsConnected = internetConnect();
  // starting TeleInfo capture
  myTeleInfo = new TeleInfo(version);
}

boolean internetConnect()
{
  // Starting Ethernet
    Serial.print(F("Ethernet connexion "));
  boolean ethernetIsConnected = (Ethernet.begin(mac) == 1);
  if(!ethernetIsConnected)
    Serial.print(F("failed !\n"));
  else
    Serial.print(F("is OK\n"));
  delay(1000);
  return ethernetIsConnected;
}
