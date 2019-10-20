/*=======================================================================================================================
                                                        my_teleinfo
=========================================================================================================================
                                                 (c) 2012-2013 by P. CARDON
                                                  Script name : my_teleinfo
=========================================================================================================================
 Usage :                                                                                   
     + Arduino Teleinfo report program
     + This program receives data frames from the EDF counter teleinfo port, it parse it,
       validate each data group by verfying the checksum, stores it in local variables, 
       displays the actual counter, consumption ...
       Frame content is sent to a remote PHP server, thru Internet. The remote PHP
       server records the received data in a MySQL data base.                                                           
     + Runs on a Leonardo, RX on PIN 0
                                                                                                                         */
char version[17] = "TeleInfo  V 1.00";
/*________________________________________________________________________________________________________________________	  
                VERSIONS HISTORY                                                        | Program space | Dynamic memory |
                                                                                        |  used / total | used  / total  |
========================================================================================|---------------|----------------|
	Version 1.00	30/11/2013	+ Original version                              | 23474 /28672  | 790 used /8192 |
=====================================================================================*/
/* PIN USED :
  PIN A0  : LedPin frame received (Blue LED)
  PIN A1  : LCD Display enable
  PIN A2  : LCD Display rs
  PIN A3  : clockPin  Pin connected to SH_CP of 74HC595 pin 11
  PIN A4  : latchPin  Pin connected to ST_CP of 74HC595 pin 12  
  PIN A5  : dataPin   Pin connected to DS    of 74HC595 pin 14

  PIN 16  : Serial TX2
  PIN 17  : Serial RX2
  PIN 2  : Interrupt 0, button
  PIN 3  : LCD light
  PIN 4  : LCD Display data 7
  PIN 5  : LCD Display data 6
  PIN 6  : LCD Display data 5
  PIN 7  : LCD Display data 4
  PIN 8  : Not used ...
  PIN 9  : Not used ...                       
  PIN 10 : ETH, SS
  PIN 11 : ETH, SPI bus MOSI
  PIN 12 : ETH, SPI bus MISO
  PIN 13 : ETH, SPI bus SCK
  
Heures pleines/Heures creuses :
ADCO 270622224349 B
OPTARIF HC.. <
ISOUSC 30 9
HCHC 014460852 $
HCHP 012506372 -
PTEC HP..  
IINST 002 Y
IMAX 035 G
PAPP 00520 (
HHPHC C .
MOTDETAT 000000 B
=====================================================================================*/
/* to do list
  + retrieve tomorrow color from server if available and update LED accordingly
  + integrate the circuits in a box, then install it in the communication box
  + add resetable sound alarm when RED day
  + add resetable sound alarm when current is higher than subscript power
  + add a setup display, where we can select options : alarm, no alarm, eco mode or not
*/
