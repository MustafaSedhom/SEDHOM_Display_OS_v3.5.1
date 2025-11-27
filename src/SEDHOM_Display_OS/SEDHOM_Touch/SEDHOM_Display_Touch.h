#include <TouchScreen.h>
#include <Arduino.h>
#include "../SEDHOM_Display_Drivers/SEDHOM_OS_SIMPLE_GUI.h"


#if defined(ESP32)
  #define LCD_RS   33
  #define LCD_WR   25
  #define LCD_CS   27
  #define LCD_RST  32
  #define LCD_RD   26

#elif defined(ESP8266)
  #define LCD_RS   D1
  #define LCD_WR   D2
  #define LCD_CS   D3
  #define LCD_RST  D4
  #define LCD_RD   D5

#elif defined(__AVR_ATmega328P__)
  #define LCD_RS   A2
  #define LCD_WR   A1
  #define LCD_CS   A3
  #define LCD_RST  A4
  #define LCD_RD   A0

#elif defined(__AVR_ATmega2560__)
  #define LCD_RS   A2
  #define LCD_WR   A1
  #define LCD_CS   A0
  #define LCD_RST  A4
  #define LCD_RD   A3

#elif defined(ARDUINO_ARCH_RP2040)
  #define LCD_RS   6
  #define LCD_WR   7
  #define LCD_CS   8
  #define LCD_RST  9
  #define LCD_RD   10

#else
  #error "Board not recognized! Define pins manually."
#endif



extern int pixel_x;
extern int pixel_y;
extern int pixel_z;
//touch 
bool Is_Touch_Presssed();
int touch_get_X_point();
int touch_get_Y_point();
int touch_get_Z_point();