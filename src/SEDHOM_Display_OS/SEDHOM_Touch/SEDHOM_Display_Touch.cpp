#include "SEDHOM_Display_Touch.h"

  const int SEDHOM_XP =8 ,SEDHOM_XM = A2, SEDHOM_YP = A3,SEDHOM_YM = 9;
// touch screen dimentions
const int TS_LEFT = 954, TS_RT = 88, TS_TOP = 908, TS_BOT = 125;
#define MINPRESSURE 200
#define MAXPRESSURE 1000


TouchScreen ts = TouchScreen(SEDHOM_XP, SEDHOM_YP, SEDHOM_XM, SEDHOM_YM, 300);

int pixel_x=0;
int pixel_y=0;
int pixel_z=0;

/////////////////////////////////////////////////////////////////////////////////////////////////
//helper function
bool Touch_getXY() 
{
  TSPoint p = ts.getPoint();

  pinMode(SEDHOM_YP, OUTPUT);
  pinMode(SEDHOM_XM, OUTPUT);
  digitalWrite(SEDHOM_YP, HIGH);
  digitalWrite(SEDHOM_XM, HIGH);

  bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
  if (pressed) {
    pixel_x = map(p.y, TS_LEFT, TS_RT, 0, 480);
    pixel_y = map(p.x, TS_TOP, TS_BOT, 0, 320);
    pixel_z = p.z;
  }
  return pressed;
}
bool Is_Touch_Presssed()
{
    return Touch_getXY();
}
int touch_get_X_point()
{
    Touch_getXY();
    return pixel_x; 
}
int touch_get_Y_point()
{
    Touch_getXY();
    return pixel_y; 
}
int touch_get_Z_point()
{
    Touch_getXY();
    return pixel_z; 
}