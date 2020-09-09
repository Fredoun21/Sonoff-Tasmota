/*
  user_config_override.h - user configuration overrides my_user_config.h for Sonoff-Tasmota

  Copyright (C) 2019  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *         ie2 : enable in file platformio.ini "build_flags = -Wl,-Tesp8266.flash.1m0.ld -DUSE_CONFIG_OVERRIDE"
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS   MY_IP                  // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY      MY_GW                  // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS          MY_DNS                 // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

*/

// -- Project -------------------------------------
#undef  PROJECT
#define PROJECT                "sonoff"          // PROJECT is used as the default topic delimiter

// -- Wifi ----------------------------------------
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS        "192.168.1.52"    // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY           "192.168.1.254"     // [IpAddress2] If not using DHCP set Gateway IP address
#undef  WIFI_SUBNETMASK
#define WIFI_SUBNETMASK        "255.255.255.0"   // [IpAddress3] If not using DHCP set Network mask
#undef  WIFI_DNS
#define WIFI_DNS               "192.168.1.254"     // [IpAddress4] If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)

#undef  STA_SSID1
#define STA_SSID1              "Bbox-39156D4C"    // [Ssid1] Wifi SSID
#undef  STA_PASS1
#define STA_PASS1              "16D2DD9977F12A97AAAD2C11ED59E2"    // [Password1] Wifi password

#undef  WIFI_CONFIG_TOOL
#define WIFI_CONFIG_TOOL       WIFI_RETRY        // [WifiConfig] Default tool if wifi fails to connect (default option: 4 - WIFI_RETRY)
                                                 // (WIFI_RESTART, WIFI_SMARTCONFIG, WIFI_MANAGER, WIFI_WPSCONFIG, WIFI_RETRY, WIFI_WAIT, WIFI_SERIAL, WIFI_MANAGER_RESET_ONLY)
                                                 // The configuration can be changed after first setup using WifiConfig 0, 1, 2, 3, 4, 5, 6 and 7.
#undef  WIFI_CONFIG_NO_SSID
#define WIFI_CONFIG_NO_SSID    WIFI_WPSCONFIG    // Default tool if wifi fails to connect and no SSID is configured
                                                 //   (WIFI_SMARTCONFIG, WIFI_MANAGER, WIFI_WPSCONFIG, WIFI_SERIAL)
                                                 //   *** NOTE: When WPS is disabled by USE_WPS below, WIFI_WPSCONFIG will execute WIFI_MANAGER ***
                                                 //   *** NOTE: When WIFI_MANAGER is disabled by USE_WEBSERVER below, WIFI_MANAGER will execute WIFI_SMARTCONFIG ***
                                                 //   *** NOTE: When WIFI_SMARTCONFIG is disabled by USE_SMARTCONFIG below, WIFI_SMARTCONFIG will execute WIFI_SERIAL ***
// -- MQTT ----------------------------------------
#undef  MQTT_USE
#define MQTT_USE               1                 // [SetOption3] Select default MQTT use (0 = Off, 1 = On)

#undef  MQTT_HOST
#define MQTT_HOST              "192.168.1.100"   // [MqttHost]
#undef  MQTT_FINGERPRINT1
#define MQTT_FINGERPRINT1      "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"  // [MqttFingerprint1]
#undef  MQTT_FINGERPRINT2
#define MQTT_FINGERPRINT2      "A5 02 FF 13 99 9F 8B 39 8E F1 83 4F 11 23 65 0B 32 36 FC 07"  // [MqttFingerprint2]
#undef  MQTT_PORT
#define MQTT_PORT              1883              // [MqttPort] MQTT port (10123 on CloudMQTT)
#undef  MQTT_USER
#define MQTT_USER              "DVES_USER"       // [MqttUser] MQTT user
#undef  MQTT_PASS
#define MQTT_PASS              "DVES_PASS"       // [MqttPassword] MQTT password

#undef  MQTT_BUTTON_RETAIN
#define MQTT_BUTTON_RETAIN     0                 // [ButtonRetain] Button may send retain flag (0 = off, 1 = on)
#undef  MQTT_POWER_RETAIN
#define MQTT_POWER_RETAIN      0                 // [PowerRetain] Power status message may send retain flag (0 = off, 1 = on)
#undef  MQTT_SWITCH_RETAIN
#define MQTT_SWITCH_RETAIN     0                 // [SwitchRetain] Switch may send retain flag (0 = off, 1 = on)
#undef  MQTT_BUTTON_SWITCH_FORCE_LOCAL
#define MQTT_BUTTON_SWITCH_FORCE_LOCAL     0     // [SetOption61] Force local operation when button/switch topic is set (0 = off, 1 = on)

#undef  MQTT_STATUS_OFF
#define MQTT_STATUS_OFF        "OFF"             // [StateText1] Command or Status result when turned off (needs to be a string like "0" or "Off")
#undef  MQTT_STATUS_ON
#define MQTT_STATUS_ON         "ON"              // [StateText2] Command or Status result when turned on (needs to be a string like "1" or "On")
#undef  MQTT_CMND_TOGGLE
#define MQTT_CMND_TOGGLE       "TOGGLE"          // [StateText3] Command to send when toggling (needs to be a string like "2" or "Toggle")
#undef  MQTT_CMND_HOLD
#define MQTT_CMND_HOLD         "HOLD"            // [StateText4] Command to send when button is kept down for over KEY_HOLD_TIME * 0.1 seconds (needs to be a string like "HOLD")

// -- MQTT topics ---------------------------------
  // Example "tasmota/bedroom/%topic%/%prefix%/" up to 80 characers
#undef  MQTT_FULLTOPIC
#define MQTT_FULLTOPIC         "%prefix%/%topic%/" // [FullTopic] Subscribe and Publish full topic name - Legacy topic

// %prefix% token options
#undef  SUB_PREFIX
#define SUB_PREFIX             "cmnd"            // [Prefix1] Sonoff devices subscribe to %prefix%/%topic% being SUB_PREFIX/MQTT_TOPIC and SUB_PREFIX/MQTT_GRPTOPIC
#undef  PUB_PREFIX
#define PUB_PREFIX             "stat"            // [Prefix2] Sonoff devices publish to %prefix%/%topic% being PUB_PREFIX/MQTT_TOPIC
#undef  PUB_PREFIX2
#define PUB_PREFIX2            "tele"            // [Prefix3] Sonoff devices publish telemetry data to %prefix%/%topic% being PUB_PREFIX2/MQTT_TOPIC/UPTIME, POWER and TIME
                                                 //   May be named the same as PUB_PREFIX
// %topic% token options (also ButtonTopic and SwitchTopic)
#undef  MQTT_TOPIC
#define MQTT_TOPIC             PROJECT           // [Topic] (unique) MQTT device topic, set to 'PROJECT "_%06X"' for unique topic including device MAC address
#undef  MQTT_GRPTOPIC
#define MQTT_GRPTOPIC          "sonoffs"         // [GroupTopic] MQTT Group topic
#undef  MQTT_BUTTON_TOPIC
#define MQTT_BUTTON_TOPIC      "0"               // [ButtonTopic] MQTT button topic, "0" = same as MQTT_TOPIC, set to 'PROJECT "_BTN_%06X"' for unique topic including device MAC address
#undef  MQTT_SWITCH_TOPIC
#define MQTT_SWITCH_TOPIC      "0"               // [SwitchTopic] MQTT button topic, "0" = same as MQTT_TOPIC, set to 'PROJECT "_SW_%06X"' for unique topic including device MAC address
#undef  MQTT_CLIENT_ID
#define MQTT_CLIENT_ID         "DVES_%06X"       // [MqttClient] Also fall back topic using Chip Id = last 6 characters of MAC address

// -- MQTT - Telemetry ----------------------------
#undef  TELE_PERIOD
#define TELE_PERIOD            300               // [TelePeriod] Telemetry (0 = disable, 10 - 3600 seconds)
#undef  TELE_ON_POWER
#define TELE_ON_POWER          0                 // [SetOption59] send tele/STATE together with stat/RESULT (0 = Disable, 1 = Enable)

// -- MQTT - Domoticz -----------------------------
#undef  DOMOTICZ_UPDATE_TIMER
#define DOMOTICZ_UPDATE_TIMER  0                 // [DomoticzUpdateTimer] Send relay status (0 = disable, 1 - 3600 seconds)

// -- MQTT - Home Assistant Discovery -------------
#undef  HOME_ASSISTANT_DISCOVERY_ENABLE
#define HOME_ASSISTANT_DISCOVERY_ENABLE   0      // [SetOption19] Home Assistant Discovery (0 = Disable, 1 = Enable)

// -- HTTP ----------------------------------------
#undef  WEB_SERVER
#define WEB_SERVER             1                 // [WebServer] Web server (0 = Off, 1 = Start as User, 2 = Start as Admin)
#undef  WEB_PASSWORD
#define WEB_PASSWORD           "210804"          // [WebPassword] Web server Admin mode Password for WEB_USERNAME (empty string = Disable)
#undef  FRIENDLY_NAME
#define FRIENDLY_NAME          "Sonoff"          // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
#undef  EMULATION
#define EMULATION              EMUL_NONE         // [Emulation] Select Belkin WeMo (single relay/light) or Hue Bridge emulation (multi relay/light) (EMUL_NONE, EMUL_WEMO or EMUL_HUE)

// -- mDNS ----------------------------------------
#undef  MDNS_ENABLED
#define MDNS_ENABLED           0                 // [SetOption55] Use mDNS (0 = Disable, 1 = Enable)

// -- Location ------------------------------------
#undef  LATITUDE
#define LATITUDE               50.4826           // [Latitude] Your location to be used with sunrise and sunset
#undef  LONGITUDE
#define LONGITUDE              1.63094           // [Longitude] Your location to be used with sunrise and sunset

// -- Application ---------------------------------
#undef  APP_TIMEZONE
#define APP_TIMEZONE           1                 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)
#undef  APP_LEDSTATE
#define APP_LEDSTATE           LED_POWER         // [LedState] Function of led
                                                 //   (LED_OFF, LED_POWER, LED_MQTTSUB, LED_POWER_MQTTSUB, LED_MQTTPUB, LED_POWER_MQTTPUB, LED_MQTT, LED_POWER_MQTT)
#undef  APP_LEDMASK
#define APP_LEDMASK            0xFFFF            // [LedMask] Assign Relay to Power led (0xFFFF is default)
#undef  APP_PULSETIME
#define APP_PULSETIME          0                 // [PulseTime] Time in 0.1 Sec to turn off power for relay 1 (0 = disabled)
#undef  APP_POWERON_STATE
#define APP_POWERON_STATE      POWER_ALL_SAVED   // [PowerOnState] Power On Relay state
                                                 //   (POWER_ALL_OFF, POWER_ALL_ON, POWER_ALL_SAVED_TOGGLE, POWER_ALL_SAVED, POWER_ALL_ALWAYS_ON, POWER_ALL_OFF_PULSETIME_ON)
#undef  APP_BLINKTIME
#define APP_BLINKTIME          10                // [BlinkTime] Time in 0.1 Sec to blink/toggle power for relay 1
#undef  APP_BLINKCOUNT
#define APP_BLINKCOUNT         10                // [BlinkCount] Number of blinks (0 = 32000)
#undef  APP_SLEEP
#define APP_SLEEP              0                 // [Sleep] Sleep time to lower energy consumption (0 = Off, 1 - 250 mSec)

#undef  KEY_DEBOUNCE_TIME
#define KEY_DEBOUNCE_TIME      50                // [ButtonDebounce] Number of mSeconds button press debounce time
#undef  KEY_HOLD_TIME
#define KEY_HOLD_TIME          40                // [SetOption32] Number of 0.1 seconds to hold Button or external Pushbutton before sending HOLD message
#undef  SWITCH_DEBOUNCE_TIME
#define SWITCH_DEBOUNCE_TIME   50                // [SwitchDebounce] Number of mSeconds switch press debounce time
#undef  SWITCH_MODE
#define SWITCH_MODE            TOGGLE            // [SwitchMode] TOGGLE, FOLLOW, FOLLOW_INV, PUSHBUTTON, PUSHBUTTON_INV, PUSHBUTTONHOLD, PUSHBUTTONHOLD_INV, PUSHBUTTON_TOGGLE (the wall switch state)
#undef  WS2812_LEDS
#define WS2812_LEDS            8                // [Pixels] Number of WS2812 LEDs to start with (max is 512)

#undef  TEMP_CONVERSION
#define TEMP_CONVERSION        0                 // [SetOption8] Return temperature in (0 = Celsius or 1 = Fahrenheit)
#undef  PRESSURE_CONVERSION
#define PRESSURE_CONVERSION    0                 // [SetOption24] Return pressure in (0 = hPa or 1 = mmHg)
#undef  TEMP_RESOLUTION
#define TEMP_RESOLUTION        1                 // [TempRes] Maximum number of decimals (0 - 3) showing sensor Temperature
#undef  HUMIDITY_RESOLUTION
#define HUMIDITY_RESOLUTION    1                 // [HumRes] Maximum number of decimals (0 - 3) showing sensor Humidity
#undef  PRESSURE_RESOLUTION
#define PRESSURE_RESOLUTION    1                 // [PressRes] Maximum number of decimals (0 - 3) showing sensor Pressure
#undef  ENERGY_RESOLUTION
#define ENERGY_RESOLUTION      3                 // [EnergyRes] Maximum number of decimals (0 - 5) showing energy usage in kWh
#undef  CALC_RESOLUTION
#define CALC_RESOLUTION        3                 // [CalcRes] Maximum number of decimals (0 - 7) used in commands ADD, SUB, MULT and SCALE

/*********************************************************************************************\
 * END OF SECTION 1
 *
 * SECTION 2
 * - Enable a feature by removing both // in front of it
 * - Disable a feature by preceding it with //
\*********************************************************************************************/

// -- Localization --------------------------------
  // If non selected the default en-GB will be used
//#define MY_LANGUAGE            bg-BG           // Bulgarian in Bulgaria
//#define MY_LANGUAGE            cs-CZ           // Czech in Czech
//#define MY_LANGUAGE            de-DE           // German in Germany
//#define MY_LANGUAGE            el-GR           // Greek in Greece
//#define MY_LANGUAGE            en-GB           // English in Great Britain. Enabled by Default
//#define MY_LANGUAGE            es-ES           // Spanish in Spain
#undef  MY_LANGUAGE
#define MY_LANGUAGE            fr-FR           // French in France
//#define MY_LANGUAGE            he-HE           // Hebrew in Israel
//#define MY_LANGUAGE            hu-HU           // Hungarian in Hungary
//#define MY_LANGUAGE            it-IT           // Italian in Italy
//#define MY_LANGUAGE            ko-KO           // Korean in Korea
//#define MY_LANGUAGE            nl-NL           // Dutch in the Netherlands
//#define MY_LANGUAGE            pl-PL           // Polish in Poland
//#define MY_LANGUAGE            pt-BR           // Portuguese in Brazil
//#define MY_LANGUAGE            pt-PT           // Portuguese in Portugal
//#define MY_LANGUAGE            ru-RU           // Russian in Russia
//#define MY_LANGUAGE            sk-SK           // Slovak in Slovakia
//#define MY_LANGUAGE            sv-SE           // Swedish in Sweden
//#define MY_LANGUAGE            tr-TR           // Turkish in Turkey
//#define MY_LANGUAGE            uk-UK           // Ukrainian in Ukraine
//#define MY_LANGUAGE            zh-CN           // Chinese (Simplified) in China
//#define MY_LANGUAGE            zh-TW           // Chinese (Traditional) in Taiwan

// -- Wifi Config tools ---------------------------
#undef  WIFI_SOFT_AP_CHANNEL
#define WIFI_SOFT_AP_CHANNEL   1                 // Soft Access Point Channel number between 1 and 13 as used by Wifi Manager web GUI
#undef  USE_WPS
//#define USE_WPS                                  // Add support for WPS as initial wifi configuration tool (+33k code, 1k mem (5k mem with core v2.4.2+))
#undef  USE_SMARTCONFIG
//#define USE_SMARTCONFIG                          // Add support for Wifi SmartConfig as initial wifi configuration tool (+23k code, +0.6k mem)

// -- OTA -----------------------------------------
#undef  USE_ARDUINO_OTA
#define USE_ARDUINO_OTA                          // Add optional support for Arduino OTA (+13k code)

// -- MQTT ----------------------------------------
#undef  MQTT_TELE_RETAIN
#define MQTT_TELE_RETAIN     0                   // Tele messages may send retain flag (0 = off, 1 = on)

// -- MQTT - Domoticz -----------------------------
#undef  USE_DOMOTICZ
#define USE_DOMOTICZ                             // Enable Domoticz (+6k code, +0.3k mem)
  #undef  DOMOTICZ_IN_TOPIC
  #define DOMOTICZ_IN_TOPIC    "domoticz/in"     // Domoticz Input Topic
  #undef  DOMOTICZ_OUT_TOPIC
  #define DOMOTICZ_OUT_TOPIC   "domoticz/out"    // Domoticz Output Topic

// -- MQTT - Home Assistant Discovery -------------
#undef  USE_HOME_ASSISTANT
// #define USE_HOME_ASSISTANT                       // Enable Home Assistant Discovery Support (+7k code)
  #undef  HOME_ASSISTANT_DISCOVERY_PREFIX
  // #define HOME_ASSISTANT_DISCOVERY_PREFIX "homeassistant"  // Home Assistant discovery prefix

// -- MQTT - TLS - AWS IoT ------------------------
// Using TLS starting with version v6.5.0.16 compilation will only work using Core 2.4.2 and 2.5.2. No longer supported: 2.3.0
#undef  USE_MQTT_TLS
//#define USE_MQTT_TLS                             // Use TLS for MQTT connection (+34.5k code, +7.0k mem and +4.8k additional during connection handshake)
  #undef  USE_MQTT_TLS_CA_CERT
//  #define USE_MQTT_TLS_CA_CERT                   // Force full CA validation instead of fingerprints, slower, but simpler to use (+2.2k code, +1.9k mem during connection handshake)
  #undef  USE_MQTT_TLS_FORCE_EC_CIPHER
//  #define USE_MQTT_TLS_FORCE_EC_CIPHER           // Force Elliptic Curve cipher (higher security) required by some servers (automatically enabled with USE_MQTT_AWS_IOT) (+11.4k code, +0.4k mem)
  #undef  USE_MQTT_AWS_IOT
//  #define USE_MQTT_AWS_IOT                       // Enable MQTT for AWS IoT - requires a private key (+11.9k code, +0.4k mem)
                                                 //   Note: you need to generate a private key + certificate per device and update 'sonoff/sonoff_aws_iot.cpp'
                                                 //   Full documentation here: https://github.com/arendst/Sonoff-Tasmota/wiki/AWS-IoT
// -- KNX IP Protocol -----------------------------
#undef  USE_KNX
//#define USE_KNX                                  // Enable KNX IP Protocol Support (+9.4k code, +3k7 mem)
  #undef  USE_KNX_WEB_MENU
  // #define USE_KNX_WEB_MENU                       // Enable KNX WEB MENU (+8.3k code, +144 mem)

// -- HTTP ----------------------------------------
#undef  USE_WEBSERVER
#define USE_WEBSERVER                            // Enable web server and Wifi Manager (+66k code, +8k mem)
  #undef  WEB_PORT
  #define WEB_PORT             80                // Web server Port for User and Admin mode
  #undef  WEB_USERNAME
  #define WEB_USERNAME         "admin"           // Web server Admin mode user name
#undef  USE_JAVASCRIPT_ES6
//  #define USE_JAVASCRIPT_ES6                     // Enable ECMAScript6 syntax using less JavaScript code bytes (fails on IE11)
#undef  USE_WEBSEND_RESPONSE
//  #define USE_WEBSEND_RESPONSE                   // Enable command WebSend response message (+1k code)
  #undef  USE_EMULATION_HUE
  // #define USE_EMULATION_HUE                      // Enable Hue Bridge emulation for Alexa (+14k code, +2k mem common)
  #undef  USE_EMULATION_WEMO
  // #define USE_EMULATION_WEMO                     // Enable Belkin WeMo emulation for Alexa (+6k code, +2k mem common)

// -- mDNS ----------------------------------------
#undef  USE_DISCOVERY
#define USE_DISCOVERY                            // Enable mDNS for the following services (+8k code or +23.5k code with core 2_5_x, +0.3k mem)
  #undef  WEBSERVER_ADVERTISE
  #define WEBSERVER_ADVERTISE                    // Provide access to webserver by name <Hostname>.local/
  #undef  MQTT_HOST_DISCOVERY
  #define MQTT_HOST_DISCOVERY                    // Find MQTT host server (overrides MQTT_HOST if found)

// -- Time ----------------------------------------
#undef  USE_TIMERS
// #define USE_TIMERS                               // Add support for up to 16 timers (+2k2 code)
  #undef  USE_TIMERS_WEB
  // #define USE_TIMERS_WEB                         // Add timer webpage support (+4k5 code)
  #undef  USE_SUNRISE
  // #define USE_SUNRISE                            // Add support for Sunrise and sunset tools (+16k)
    #undef  SUNRISE_DAWN_ANGLE
    // #define SUNRISE_DAWN_ANGLE DAWN_NORMAL       // Select desired Dawn Angle from (DAWN_NORMAL, DAWN_CIVIL, DAWN_NAUTIC, DAWN_ASTRONOMIC)

// -- Rules or Script  ----------------------------
// Select none or only one of the below defines
#undef  USE_RULES
// #define USE_RULES                                // Add support for rules (+8k code)
#undef  USE_SCRIPT
// #define USE_SCRIPT                               // Add support for script (+17k code)
  #undef  USE_SCRIPT_FATFS
  //  #define USE_SCRIPT_FATFS 4                     // Script: Add FAT FileSystem Support

#undef  USE_EXPRESSION
//  #define USE_EXPRESSION                         // Add support for expression evaluation in rules (+3k2 code, +64 bytes mem)
#undef  SUPPORT_IF_STATEMENT
//    #define SUPPORT_IF_STATEMENT                 // Add support for IF statement in rules (+4k2 code, -332 bytes mem)
#undef  SUPPORT_MQTT_EVENT
//  #define SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+3k5 code)

// -- Optional modules ----------------------------
#undef  ROTARY_V1
//#define ROTARY_V1                                // Add support for MI Desk Lamp
#undef  USE_SONOFF_RF
// #define USE_SONOFF_RF                            // Add support for Sonoff Rf Bridge (+3k2 code)
#undef  USE_RF_FLASH
//   #define USE_RF_FLASH                           // Add support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB (+2k7 code)
#undef  USE_SONOFF_SC
// #define USE_SONOFF_SC                            // Add support for Sonoff Sc (+1k1 code)
#undef  USE_TUYA_MCU
// #define USE_TUYA_MCU                             // Add support for Tuya Serial MCU
#undef  TUYA_DIMMER_ID
//   #define TUYA_DIMMER_ID       0                 // Default dimmer Id
#undef  USE_ARMTRONIX_DIMMERS
// #define USE_ARMTRONIX_DIMMERS                    // Add support for Armtronix Dimmers (+1k4 code)
#undef  USE_PS_16_DZ
// #define USE_PS_16_DZ                             // Add support for PS-16-DZ Dimmer (+2k code)
#undef  USE_SONOFF_IFAN
// #define USE_SONOFF_IFAN                          // Add support for Sonoff iFan02 and iFan03 (+2k code)
#undef  USE_BUZZER
// #define USE_BUZZER                               // Add support for a buzzer (+0k6 code)
#undef  USE_ARILUX_RF
// #define USE_ARILUX_RF                            // Add support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))
#undef  USE_SHUTTER
//#define USE_SHUTTER                              // Add Shutter support for up to 4 shutter with different motortypes (+6k code)
#undef  USE_DEEPSLEEP
//#define USE_DEEPSLEEP                            // Add support for deepsleep (+1k code)

// -- Optional light modules ----------------------
#undef  USE_WS2812
// #define USE_WS2812                               // WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
#undef  USE_WS2812_DMA
//  #define USE_WS2812_DMA                         // DMA supports only GPIO03 (= Serial RXD) (+1k mem). When USE_WS2812_DMA is enabled expect Exceptions on Pow
#undef  USE_WS2812_HARDWARE
//   #define USE_WS2812_HARDWARE  NEO_HW_WS2812     // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106)
#undef  USE_WS2812_CTYPE
//   #define USE_WS2812_CTYPE     NEO_GRB           // Color type (NEO_RGB, NEO_GRB, NEO_BRG, NEO_RBG, NEO_RGBW, NEO_GRBW)
#undef  USE_MY92X1
// #define USE_MY92X1                               // Add support for MY92X1 RGBCW led controller as used in Sonoff B1, Ailight and Lohas
#undef  USE_SM16716
// #define USE_SM16716                              // Add support for SM16716 RGB LED controller (+0k7 code)
#undef  USE_SM2135
// #define USE_SM2135                               // Add support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
#undef  USE_SONOFF_L1
// #define USE_SONOFF_L1                            // Add support for Sonoff L1 led control

// -- Counter input -------------------------------
#undef  USE_COUNTER
// #define USE_COUNTER                              // Enable inputs as counter (+0k8 code)

// -- Internal Analog input -----------------------
#undef  USE_ADC_VCC
//#define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices

// -- One wire sensors ----------------------------
#undef  USE_DS18x20
#define USE_DS18x20                              // Add support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)
  #undef  W1_PARASITE_POWER
  // #define W1_PARASITE_POWER                      // Optimize for parasite powered sensors
  #undef  DS18B20_INTERNAL_PULLUP
  // #define DS18B20_INTERNAL_PULLUP                // Use INPUT_PULLUP internal pullup resistor

// -- I2C sensors ---------------------------------
#undef  USE_I2C
#define USE_I2C                                  // I2C using library wire (+10k code, 0k2 mem, 124 iram)

#ifdef USE_I2C
  #undef  USE_SHT
  // #define USE_SHT                                // Enable SHT1X sensor (+1k4 code)
  #undef  USE_HTU
  // #define USE_HTU                                // Enable HTU21/SI7013/SI7020/SI7021 sensor (I2C address 0x40) (+1k5 code)
  #undef  USE_BMP
  #define USE_BMP                                // Enable BMP085/BMP180/BMP280/BME280 sensors (I2C addresses 0x76 and 0x77) (+4k4 code)
  #undef  USE_BME680
  //  #define USE_BME680                           // Enable support for BME680 sensor using Bosch BME680 library (+4k code)
  #undef  USE_BH1750
  //  #define USE_BH1750                             // Enable BH1750 sensor (I2C address 0x23 or 0x5C) (+0k5 code)
  #undef  USE_VEML6070
  //  #define USE_VEML6070                           // Enable VEML6070 sensor (I2C addresses 0x38 and 0x39) (+1k5 code)
    #undef  USE_VEML6070_RSET
    //  #define USE_VEML6070_RSET    270000          // VEML6070, Rset in Ohm used on PCB board, default 270K = 270000ohm, range for this sensor: 220K ... 1Meg
    #undef  USE_VEML6070_SHOW_RAW
    //  #define USE_VEML6070_SHOW_RAW                // VEML6070, shows the raw value of UV-A
  #undef  USE_ADS1115
  //  #define USE_ADS1115                            // Enable ADS1115 16 bit A/D converter (I2C address 0x48, 0x49, 0x4A or 0x4B) based on Adafruit ADS1x15 library (no library needed) (+0k7 code)
    #undef  USE_ADS1115_I2CDEV
    //  #define USE_ADS1115_I2CDEV                     // Enable ADS1115 16 bit A/D converter (I2C address 0x48, 0x49, 0x4A or 0x4B) using library i2cdevlib-Core and i2cdevlib-ADS1115 (+2k code)
  #undef  USE_INA219
  //  #define USE_INA219                             // Enable INA219 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+1k code)
  #undef  USE_INA226
  //  #define USE_INA226                             // Enable INA226 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+2k3 code)
  #undef  USE_SHT3X
  // #define USE_SHT3X                              // Enable SHT3x (I2C address 0x44 or 0x45) or SHTC3 (I2C address 0x70) sensor (+0k7 code)
  #undef  USE_TSL2561
  #define USE_TSL2561                            // Enable TSL2561 sensor (I2C address 0x29, 0x39 or 0x49) using library Joba_Tsl2561 (+2k3 code)
  #undef  USE_MGS
  //  #define USE_MGS                                // Enable Xadow and Grove Mutichannel Gas sensor using library Multichannel_Gas_Sensor (+10k code)
    #undef  MGS_SENSOR_ADDR
    // #define MGS_SENSOR_ADDR    0x04              // Default Mutichannel Gas sensor i2c address
  #undef  USE_SGP30
  //  #define USE_SGP30                              // Enable SGP30 sensor (I2C address 0x58) (+1k1 code)
  #undef  USE_SI1145
  //  #define USE_SI1145                             // Enable SI1145/46/47 sensor (I2C address 0x60) (+1k code)
  #undef  USE_LM75AD
    // #define USE_LM75AD                             // Enable LM75AD sensor (I2C addresses 0x48 - 0x4F) (+0k5 code)
  #undef  USE_APDS9960
  //  #define USE_APDS9960                           // Enable APDS9960 Proximity Sensor (I2C address 0x39). Disables SHT and VEML6070 (+4k7 code)
  #undef  USE_MCP230xx
  //  #define USE_MCP230xx                           // Enable MCP23008/MCP23017 - Must define I2C Address in #define USE_MCP230xx_ADDR below - range 0x20 - 0x27 (+4k7 code)
    #undef  USE_MCP230xx_ADDR
    //  #define USE_MCP230xx_ADDR 0x20               // Enable MCP23008/MCP23017 I2C Address to use (Must be within range 0x20 through 0x27 - set according to your wired setup)
    #undef  USE_MCP230xx_OUTPUT
    //  #define USE_MCP230xx_OUTPUT                  // Enable MCP23008/MCP23017 OUTPUT support through sensor29 commands (+1k5 code)
    #undef  USE_MCP230xx_DISPLAYOUTPUT
    //  #define USE_MCP230xx_DISPLAYOUTPUT           // Enable MCP23008/MCP23017 to display state of OUTPUT pins on Web UI (+0k2 code)
  #undef  USE_PCA9685
  //  #define USE_PCA9685                            // Enable PCA9685 I2C HW PWM Driver - Must define I2C Address in #define USE_PCA9685_ADDR below - range 0x40 - 0x47 (+1k4 code)
    #undef  USE_PCA9685_ADDR
    //  #define USE_PCA9685_ADDR 0x40                // Enable PCA9685 I2C Address to use (Must be within range 0x40 through 0x47 - set according to your wired setup)
    #undef  USE_PCA9685_FREQ
    //  #define USE_PCA9685_FREQ 50                  // Define default PWM frequency in Hz to be used (must be within 24 to 1526) - If other value is used, it will rever to 50Hz
  #undef  USE_MPR121
  //  #define USE_MPR121                             // Enable MPR121 controller (I2C addresses 0x5A, 0x5B, 0x5C and 0x5D) in input mode for touch buttons (+1k3 code)
  #undef  USE_CCS811
  //  #define USE_CCS811                             // Enable CCS811 sensor (I2C address 0x5A) (+2k2 code)
  #undef  USE_MPU6050
  //  #define USE_MPU6050                            // Enable MPU6050 sensor (I2C address 0x68 AD0 low or 0x69 AD0 high) (+3K3 of code and 188 Bytes of RAM)
    #undef  USE_MPU6050_DMP
    //  #define USE_MPU6050_DMP                      // Enable in MPU6050 to use the DMP on the chip, should create better results (+8k6 of code)
  #undef  USE_DS3231
  //  #define USE_DS3231                             // Enable DS3231 external RTC in case no Wifi is avaliable. See docs in the source file (+1k2 code)
  #undef  USE_RTC_ADDR
  //    #define USE_RTC_ADDR  0x68                   // Default I2C address 0x68
  #undef  USE_MGC3130
  //  #define USE_MGC3130                            // Enable MGC3130 Electric Field Effect Sensor (I2C address 0x42) (+2k7 code, 0k3 mem)
  #undef  USE_MAX44009
  //  #define USE_MAX44009                           // Enable MAX44009 Ambient Light sensor (I2C addresses 0x4A and 0x4B) (+0k8 code)
  #undef  USE_SCD30
  //  #define USE_SCD30                              // Enable Sensiron SCd30 CO2 sensor (I2C address 0x61) (+3k3 code)
  #undef  USE_SPS30
  //  #define USE_SPS30                              // Enable Sensiron SPS30 particle sensor (I2C address 0x69) (+1.7 code)
  #undef  USE_ADE7953
  //  #define USE_ADE7953                            // Enable ADE7953 Energy monitor as used on Shelly 2.5 (I2C address 0x38) (+1k5)
  #undef  USE_VL53L0X
  //  #define USE_VL53L0X                            // Enable VL53L0x time of flight sensor (I2C address 0x29) (+4k code)
  #undef  USE_MLX90614
  //  #define USE_MLX90614                           // Enable MLX90614 ir temp sensor (I2C address 0x5a) (+0.6k code)
  #undef  USE_CHIRP
  //  #define USE_CHIRP                              // Enable CHIRP soil moisture sensor (variable I2C address, default 0x20)
  #undef  USE_PAJ7620
  //  #define USE_PAJ7620                            // Enable PAJ7620 gesture sensor (I2C address 0x73) (+2.5k code)
  #undef  USE_PCF8574
  #define USE_PCF8574                            // Enable PCF8574 I/O Expander (I2C addresses 0x20 - 0x27 and 0x38 - 0x3F) (+1k9 code)

#undef  USE_DISPLAY
//  #define USE_DISPLAY                            // Add I2C Display Support (+2k code)
  #undef  USE_DISPLAY_MODES1TO5
    // #define USE_DISPLAY_MODES1TO5                // Enable display mode 1 to 5 in addition to mode 0
  #undef  USE_DISPLAY_LCD
    // #define USE_DISPLAY_LCD                      // [DisplayModel 1] Enable Lcd display (I2C addresses 0x27 and 0x3F) (+6k code)
  #undef  USE_DISPLAY_SSD1306
    // #define USE_DISPLAY_SSD1306                  // [DisplayModel 2] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
  #undef  USE_DISPLAY_MATRIX
    // #define USE_DISPLAY_MATRIX                   // [DisplayModel 3] Enable 8x8 Matrix display (I2C adresseses see below) (+11k code)
    #undef  MTX_ADDRESS1
    //   #define MTX_ADDRESS1     0x71              // [DisplayAddress1] I2C address of first 8x8 matrix module
    #undef  MTX_ADDRESS2
    //   #define MTX_ADDRESS2     0x74              // [DisplayAddress2] I2C address of second 8x8 matrix module
    #undef  MTX_ADDRESS3
    //   #define MTX_ADDRESS3     0x75              // [DisplayAddress3] I2C address of third 8x8 matrix module
    #undef  MTX_ADDRESS4
    //   #define MTX_ADDRESS4     0x72              // [DisplayAddress4] I2C address of fourth 8x8 matrix module
    #undef  MTX_ADDRESS5
    //   #define MTX_ADDRESS5     0x73              // [DisplayAddress5] I2C address of fifth 8x8 matrix module
    #undef  MTX_ADDRESS6
    //   #define MTX_ADDRESS6     0x76              // [DisplayAddress6] I2C address of sixth 8x8 matrix module
    #undef  MTX_ADDRESS7
    //   #define MTX_ADDRESS7     0x00              // [DisplayAddress7] I2C address of seventh 8x8 matrix module
    #undef  MTX_ADDRESS8
    //   #define MTX_ADDRESS8     0x00              // [DisplayAddress8] I2C address of eigth 8x8 matrix module
  #undef  USE_DISPLAY_SH1106
  //  #define USE_DISPLAY_SH1106                    // [DisplayModel 7] Enable SH1106 Oled 128x64 display (I2C addresses 0x3C and 0x3D)
#endif  // USE_I2C

// -- SPI sensors ---------------------------------
#undef  USE_SPI
//#define USE_SPI                                 // Hardware SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)

#ifdef USE_SPI
  #ifndef USE_DISPLAY
  #define USE_DISPLAY                             // Add SPI Display support for 320x240 and 480x320 TFT
  #endif
  #undef  USE_DISPLAY_ILI9341
  #define USE_DISPLAY_ILI9341                     // [DisplayModel 4] Enable ILI9341 Tft 480x320 display (+19k code)
  #undef  USE_DISPLAY_EPAPER_29
  //  #define USE_DISPLAY_EPAPER_29                // [DisplayModel 5] Enable e-paper 2.9 inch display (+19k code)
  #undef  USE_DISPLAY_EPAPER_42
  //  #define USE_DISPLAY_EPAPER_42                // [DisplayModel 6] Enable e-paper 4.2 inch display
  #undef  USE_DISPLAY_ILI9488
  //  #define USE_DISPLAY_ILI9488                  // [DisplayModel 8]
  #undef  USE_DISPLAY_SSD1351
  //  #define USE_DISPLAY_SSD1351                  // [DisplayModel 9]
  #undef  USE_DISPLAY_RA8876
  //  #define USE_DISPLAY_RA8876                   // [DisplayModel 10]
#endif  // USE_SPI

// -- Serial sensors ------------------------------
#undef  USE_MHZ19
// #define USE_MHZ19                                // Add support for MH-Z19 CO2 sensor (+2k code)
#undef  USE_SENSEAIR
// #define USE_SENSEAIR                             // Add support for SenseAir K30, K70 and S8 CO2 sensor (+2k3 code)
  #undef  CO2_LOW
  // #define CO2_LOW              800               // Below this CO2 value show green light (needs PWM or WS2812 RG(B) led and enable with SetOption18 1)
  #undef  CO2_HIGH
  // #define CO2_HIGH             1200              // Above this CO2 value show red light (needs PWM or WS2812 RG(B) led and enable with SetOption18 1)
#undef  USE_PMS5003
// #define USE_PMS5003                              // Add support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
#undef  PMS_MODEL_PMS3003
// #define PMS_MODEL_PMS3003                      // Enable support of PMS3003 instead of PMS5003/PMS7003 (needs the USE_PMS5003 above)
#undef  USE_NOVA_SDS
// #define USE_NOVA_SDS                             // Add support for SDS011 and SDS021 particle concentration sensor (+1k5 code)
  #undef  STARTING_OFFSET
  //  #define STARTING_OFFSET      30                // Turn on NovaSDS XX-seconds before tele_period is reached
#undef  USE_SERIAL_BRIDGE
// #define USE_SERIAL_BRIDGE                        // Add support for software Serial Bridge (+0k8 code)
#undef  USE_MP3_PLAYER
// #define USE_MP3_PLAYER                           // Use of the DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
  #undef  MP3_VOLUME
  // #define MP3_VOLUME           10                // Set the startup volume on init, the range can be 0..30(max)
#undef  USE_AZ7798
// #define USE_AZ7798                               // Add support for AZ-Instrument 7798 CO2 datalogger (+1k6 code)
#undef  USE_PN532_HSU
// #define USE_PN532_HSU                            // Add support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
  #undef  USE_PN532_CAUSE_EVENTS
  // #define USE_PN532_CAUSE_EVENTS                 // Cause event execution for PN532_UID= and PN532_DATA=[if defined] (+ 30 bytes code)
  #undef  USE_PN532_DATA_FUNCTION
  // #define USE_PN532_DATA_FUNCTION                // Add sensor40 command support for erase, setting data block content (+1k7 code, 388 bytes mem)
  #undef  USE_PN532_DATA_RAW
  // #define USE_PN532_DATA_RAW                     // Allow DATA block to be used by non-alpha-numberic data (+ 80 bytes code, 48 bytes ram)
#undef  USE_RDM6300
// #define USE_RDM6300                              // Add support for RDM6300 125kHz RFID Reader (+0k8)
#undef  USE_IBEACON
// #define USE_IBEACON                              // Add support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)

// -- Power monitoring sensors --------------------
#undef  USE_ENERGY_MARGIN_DETECTION
// #define USE_ENERGY_MARGIN_DETECTION              // Add support for Energy Margin detection (+1k6 code)
#undef  USE_ENERGY_POWER_LIMIT
//   #define USE_ENERGY_POWER_LIMIT                 // Add additional support for Energy Power Limit detection (+1k2 code)
#undef  USE_PZEM004T
// #define USE_PZEM004T                             // Add support for PZEM004T Energy monitor (+2k code)
#undef  USE_PZEM_AC
// #define USE_PZEM_AC                              // Add support for PZEM014,016 Energy monitor (+1k1 code)
#undef  USE_PZEM_DC
// #define USE_PZEM_DC                              // Add support for PZEM003,017 Energy monitor (+1k1 code)
#undef  USE_MCP39F501
// #define USE_MCP39F501                            // Add support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)
#undef  USE_SDM120_2
// #define USE_SDM120_2                             // Add support for Eastron SDM120-Modbus energy monitor (+1k1 code)
  #undef  SDM120_SPEED
  // #define SDM120_SPEED         2400              // SDM120-Modbus RS485 serial speed (default: 2400 baud)
#undef  USE_SDM630_2
//#define USE_SDM630_2                             // Add support for Eastron SDM630-Modbus energy monitor (+0k6 code)
  #undef  SDM630_SPEED
  // #define SDM630_SPEED         9600              // SDM630-Modbus RS485 serial speed (default: 9600 baud)
#undef  USE_DDS2382
// #define USE_DDS2382                              // Add support for Hiking DDS2382 Modbus energy monitor (+0k6 code)
  #undef  DDS2382_SPEED
  // #define DDS2382_SPEED        9600              // Hiking DDS2382 Modbus RS485 serial speed (default: 9600 baud)
#undef  USE_DDSU666
// #define USE_DDSU666                              // Add support for Chint DDSU666 Modbus energy monitor (+0k6 code)
  #undef  DDSU666_SPEED
  // #define DDSU666_SPEED        9600              // Chint DDSU666 Modbus RS485 serial speed (default: 9600 baud)
#undef  USE_SOLAX_X1
// #define USE_SOLAX_X1                             // Add support for Solax X1 series Modbus log info (+3k1 code)
  #undef  SOLAXX1_SPEED
  // #define SOLAXX1_SPEED        9600              // Solax X1 Modbus RS485 serial speed (default: 9600 baud)
  #undef  SOLAXX1_PV2
  // #define SOLAXX1_PV2                            // Solax X1 using second PV
#undef  USE_SDM120
// #define USE_SDM120                               // Add support for Eastron SDM120-Modbus energy meter (+2k4 code)
  #undef  SDM120_SPEED
  // #define SDM120_SPEED         2400              // SDM120-Modbus RS485 serial speed (default: 2400 baud)
#undef  USE_SDM220
  // #define USE_SDM220                             // Add extra parameters for SDM220 (+0k1 code)
#undef  USE_SDM630
// #define USE_SDM630                               // Add support for Eastron SDM630-Modbus energy meter (+2k code)
  #undef  SDM630_SPEED
  // #define SDM630_SPEED         9600              // SDM630-Modbus RS485 serial speed (default: 9600 baud)
#undef USE_SFH620A
// #define USE_SFH620A                                 // Add support for teleinfo service counter EDF
  #undef SFH620A_SPEED
  // #define SFH620A_SPEED           1200
  #undef  SFH620A_RX
  // #define SFH620A_RX              12                // default DDSU66 serial software GPIO


// -- Low level interface devices -----------------
#undef  USE_DHT
// #define USE_DHT                                  // Add support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor (1k6 code)

#undef  USE_MAX31855
//#define USE_MAX31855                             // Add support for MAX31855 K-Type thermocouple sensor using softSPI
#undef  USE_MAX31865
//#define USE_MAX31865                             // Add support for MAX31865 RTD sensors using softSPI
  #undef  MAX31865_PTD_WIRES
  // #define MAX31865_PTD_WIRES  2                 // PTDs come in several flavors. Pick yours
  #undef  MAX31865_PTD_RES
  // #define MAX31865_PTD_RES    100               // Nominal PTD resistance at 0°C (100Ω for a PT100, 1000Ω for a PT1000, YMMV!)
  #undef  MAX31865_REF_RES
  // #define MAX31865_REF_RES    430               // Reference resistor (Usually 430Ω for a PT100, 4300Ω for a PT1000)
  #undef  MAX31865_PTD_BIAS
  // #define MAX31865_PTD_BIAS   0                 // To calibrate your not-so-good PTD

// -- IR Remote features - all protocols from IRremoteESP8266 --------------------------
// IR Full Protocols mode is activated through platform.io only.
// Either use 'default_envs = sonoff-ircustom' and disable some features here to keep code not too big
// or use 'default_envs = sonoff-ir' for a pre-packaged IR-dedicated firmware
// When using 'sonoff-ircustom' or 'sonoff-ir', parameters below
// (USE_IR_REMOTE, USE_IR_RECEIVE, USE_IR_HVAC...) are IGNORED.
//
// Code impact of IR full protocols is +81k code, 3k mem
// You can reduce this size by disabling some protocols in "lib/IRremoteESP8266.x.x.x/src/IRremoteESP8266.h"

// -- IR Remote features - subset of IR protocols --------------------------
#undef  USE_IR_REMOTE
// #define USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 and ArduinoJson (+4k3 code, 0k3 mem, 48 iram)
#undef  USE_IR_SEND_AIWA
// #define USE_IR_SEND_AIWA                       // Support IRsend Aiwa protocol
  #undef  USE_IR_SEND_DISH
  // #define USE_IR_SEND_DISH                       // Support IRsend Dish protocol
  #undef  USE_IR_SEND_JVC
  // #define USE_IR_SEND_JVC                        // Support IRsend JVC protocol
  #undef  USE_IR_SEND_LG
  //  #define USE_IR_SEND_LG                         // Support IRsend LG protocol
  #undef  USE_IR_SEND_MITSUBISHI
  //  #define USE_IR_SEND_MITSUBISHI                 // Support IRsend Mitsubishi protocol
  #undef  USE_IR_SEND_NEC
  // #define USE_IR_SEND_NEC                        // Support IRsend NEC protocol
  #undef  USE_IR_SEND_PANASONIC
  // #define USE_IR_SEND_PANASONIC                  // Support IRsend Panasonic protocol
  #undef  USE_IR_SEND_PIONEER
  // #define USE_IR_SEND_PIONEER                    // Support IRsend Pioneer protocol
  #undef  USE_IR_SEND_RC5
  // #define USE_IR_SEND_RC5                        // Support IRsend Philips RC5 protocol
  #undef  USE_IR_SEND_RC6
  // #define USE_IR_SEND_RC6                        // Support IRsend Philips RC6 protocol
  #undef  USE_IR_SEND_SAMSUNG
  // #define USE_IR_SEND_SAMSUNG                    // Support IRsend Samsung protocol
  #undef  USE_IR_SEND_SANYO
  //  #define USE_IR_SND_SANYO                      // Support IRsend Sanyo protocol
  #undef  USE_IR_SEND_SHARP
  // #define USE_IR_SEND_SHARP                      // Support IRsend Sharp protocol
  #undef  USE_IR_SEND_SONY
  // #define USE_IR_SEND_SONY                       // Support IRsend Sony protocol
  #undef  USE_IR_SEND_WHYNTER
  // #define USE_IR_SEND_WHYNTER                    // Support IRsend Whynter protocol

#undef  USE_IR_HVAC
//  #define USE_IR_HVAC                            // Support for HVAC systems using IR (+3k5 code)
  #undef  USE_IR_HVAC_TOSHIBA
  // #define USE_IR_HVAC_TOSHIBA                  // Support IRhvac Toshiba protocol
  #undef  USE_IR_HVAC_MITSUBISHI
  // #define USE_IR_HVAC_MITSUBISHI               // Support IRhvac Mitsubischi protocol
  #undef  USE_IR_HVAC_LG
  // #define USE_IR_HVAC_LG                       // Support IRhvac LG protocol
  #undef  USE_IR_HVAC_FUJITSU
  // #define USE_IR_HVAC_FUJITSU                  // Support IRhvac Fujitsu protocol
  #undef  USE_IR_HVAC_MIDEA
  // #define USE_IR_HVAC_MIDEA                    // Support IRhvac Midea/Komeco protocol

#undef  USE_IR_RECEIVE
// #define USE_IR_RECEIVE                         // Support for IR receiver (+7k2 code, 264 iram)
  #undef  IR_RCV_BUFFER_SIZE
  // #define IR_RCV_BUFFER_SIZE      100          // Max number of packets allowed in capture buffer (default 100 (*2 bytes ram))
  #undef  IR_RCV_TIMEOUT
  // #define IR_RCV_TIMEOUT          15           // Number of milli-Seconds of no-more-data before we consider a message ended (default 15)
  #undef  IR_RCV_MIN_UNKNOWN_SIZE
  // #define IR_RCV_MIN_UNKNOWN_SIZE 6            // Set the smallest sized "UNKNOWN" message packets we actually care about (default 6, max 255)

// -- Zigbee interface ----------------------------
#undef  USE_ZIGBEE
//#define USE_ZIGBEE                                // Enable serial communication with Zigbee CC2530 flashed with ZNP
  #undef  USE_ZIGBEE_PANID
  // #define USE_ZIGBEE_PANID  0x1A63                // arbitrary PAN ID for Zigbee network, must be unique in the home
  #undef  USE_ZIGBEE_EXTPANID
  // #define USE_ZIGBEE_EXTPANID 0xCCCCCCCCCCCCCCCCL // arbitrary extended PAN ID
  #undef  USE_ZIGBEE_CHANNEL
  // #define USE_ZIGBEE_CHANNEL  11                  // Zigbee Channel (11-26)
  #undef  USE_ZIGBEE_PRECFGKEY_L
  // #define USE_ZIGBEE_PRECFGKEY_L 0x0F0D0B0907050301L  // note: changing requires to re-pair all devices
  #undef  USE_ZIGBEE_PRECFGKEY_H
  // #define USE_ZIGBEE_PRECFGKEY_H 0x0D0C0A0806040200L  // note: changing requires to re-pair all devices
  #undef  USE_ZIGBEE_PERMIT_JOIN
  // #define USE_ZIGBEE_PERMIT_JOIN false           // don't allow joining by default

// -- Other sensors/drivers -----------------------
#undef  USE_SR04
// #define USE_SR04                                 // Add support for HC-SR04 ultrasonic devices (+1k code)
#undef  USE_TM1638
//#define USE_TM1638                               // Add support for TM1638 switches copying Switch1 .. Switch8 (+1k code)
#undef  USE_HX711
// #define USE_HX711                                // Add support for HX711 load cell (+1k5 code)
  #undef  USE_HX711_GUI
  // #define USE_HX711_GUI                          // Add optional web GUI to HX711 as scale (+1k8 code)
#undef  USE_TX20_WIND_SENSOR
//#define USE_TX20_WIND_SENSOR                     // Add support for La Crosse TX20 anemometer (+2k code)
#undef  USE_RC_SWITCH
//#define USE_RC_SWITCH                            // Add support for RF transceiver using library RcSwitch (+2k7 code, 460 iram)
#undef  USE_RF_SENSOR
//#define USE_RF_SENSOR                            // Add support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)
#undef  USE_THEO_V2
//  #define USE_THEO_V2                            // Add support for decoding Theo V2 sensors as documented on https://sidweb.nl using 434MHz RF sensor receiver (+1k4 code)
#undef  USE_ALECTO_V2
//  #define USE_ALECTO_V2                          // Add support for decoding Alecto V2 sensors like ACH2010, WS3000 and DKW2012 weather stations using 868MHz RF sensor receiver (+1k7 code)
#undef  USE_HRE
//#define USE_HRE                                  // Add support for Badger HR-E Water Meter (+1k4 code)
#undef  USE_A4988_STEPPER
//#define USE_A4988_STEPPER                        // Add support for A4988/DRV8825 stepper-motor-driver-circuit (+10k5 code)

// -- End of general directives -------------------

/*********************************************************************************************\
 * Debug features
\*********************************************************************************************/

#undef  DEBUG_TASMOTA_CORE
//#define DEBUG_TASMOTA_CORE                       // Enable core debug messages
#undef  DEBUG_TASMOTA_DRIVER
//#define DEBUG_TASMOTA_DRIVER                     // Enable driver debug messages
#undef  DEBUG_TASMOTA_SENSOR
//#define DEBUG_TASMOTA_SENSOR                     // Enable sensor debug messages
#undef  USE_DEBUG_DRIVER
//#define USE_DEBUG_DRIVER                         // Use xdrv_99_debug.ino providing commands CpuChk, CfgXor, CfgDump, CfgPeek and CfgPoke

/*********************************************************************************************\
 * Optional firmware configurations
 * Select none or just one for optional features and sensors as configured in sonoff_post.h
 * See RELEASENOTES.md for selected features
\*********************************************************************************************/

#undef  FIRMWARE_CLASSIC
//#define FIRMWARE_CLASSIC                         // Create sonoff-classic with initial configuration tools WPS, SmartConfig and WifiManager
#undef  FIRMWARE_BASIC
//#define FIRMWARE_BASIC                           // Create sonoff-basic with no sensors
#undef  FIRMWARE_SENSORS
//#define FIRMWARE_SENSORS                         // Create sonoff-sensors with useful sensors enabled
#undef  FIRMWARE_KNX_NO_EMULATION
//#define FIRMWARE_KNX_NO_EMULATION                // Create sonoff-knx with KNX but without Emulation
#undef  FIRMWARE_DISPLAYS
//#define FIRMWARE_DISPLAYS                        // Create sonoff-display with display drivers enabled
#undef  FIRMWARE_IR
//#define FIRMWARE_IR                              // Create sonoff-ir with IR full protocols activated, and many sensors disabled
#undef  FIRMWARE_IR_CUSTOM
//#define FIRMWARE_IR_CUSTOM                       // Create sonoff customizable with special marker to add all IR protocols
#undef  FIRMWARE_MINIMAL
//#define FIRMWARE_MINIMAL                         // Create sonoff-minimal as intermediate firmware for OTA-MAGIC

/*********************************************************************************************\
 * No user configurable items below
\*********************************************************************************************/

#endif  // _USER_CONFIG_OVERRIDE_H_
