void loop() 
{
  boolean teleInfoReceived;

  // we parse the teleInfo frame
  teleInfoReceived = myTeleInfo->readTeleInfo(ethernetIsConnected);
  // If the frame was correctly reveived, we display it in
  // the console (only if debug)
  if(teleInfoReceived)
  {
    myTeleInfo->displayTeleInfo();
    // If Internet connexion is OK we sent the data over Internet
    if(ethernetIsConnected)
      ethernetIsConnected = myTeleInfo->recordTeleInfoOnMySQLServer();
    else
      ethernetIsConnected = internetConnect();
  }
}








