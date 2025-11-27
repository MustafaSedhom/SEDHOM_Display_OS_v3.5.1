#include "SEDHOM_OnTaps.h"

//ontaps functions
void Power_off_onTap(bool* draw)
{
    *draw=0;
    delay(100);
    static int flag =1;
    if(flag)
    {
        *draw =1;
        Icon.Power_off_Icon(240,160,GREEN,Icon.Mode());
        flag=0;
        digitalWrite(1,1);
        *draw =0;
    }
    else
    {
        *draw =1;
        Icon.Power_off_Icon(240,160,RED,Icon.Mode());
        flag=1;
        digitalWrite(1,0);
        *draw =0;
    }
   
}
void sensor_Icon_OnTap()
{

}