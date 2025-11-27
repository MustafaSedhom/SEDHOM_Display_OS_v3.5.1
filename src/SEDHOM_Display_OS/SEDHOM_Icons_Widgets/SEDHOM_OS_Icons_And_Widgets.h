#include <stdio.h>
#include <Arduino.h>
#include <TouchScreen.h>
#include <Adafruit_GFX.h>    // Core graphics library
// #include <UTFTGLUE.h> 
#include "../SEDHOM_Display_Drivers/SEDHOM_OS_SIMPLE_GUI.h"
#include "../SEDHOM_Data_Types/SEDHOM_OS_status_types.h"
#include "../SEDHOM_Data_Types/SEDHOM_OS_data_type.h"
#include "../SEDHOM_Touch/SEDHOM_Display_Touch.h"
#include "../SEDHOM_On_Taps/SEDHOM_OnTaps.h"
// #include "variable_for_system.h"
/////////////////////////////init colors////////////////////////////
// New color definitions.  thanks to Bodmer
#define BLACK       0x0000      /*   0,   0,   0 */
#define NAVY        0x000F      /*   0,   0, 128 */
#define DARKGREEN   0x03E0      /*   0, 128,   0 */
#define DARKCYAN    0x03EF      /*   0, 128, 128 */
#define MAROON      0x7800      /* 128,   0,   0 */
#define PURPLE      0x780F      /* 128,   0, 128 */
#define OLIVE       0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY   0xC618      /* 192, 192, 192 */
#define DARKGREY    0x7BEF      /* 128, 128, 128 */
#define BLUE        0x001F      /*   0,   0, 255 */
#define GREEN       0x07E0      /*   0, 255,   0 */
#define CYAN        0x07FF      /*   0, 255, 255 */
#define RED         0xF800      /* 255,   0,   0 */
#define MAGENTA     0xF81F      /* 255,   0, 255 */
#define YELLOW      0xFFE0      /* 255, 255,   0 */
#define WHITE       0xFFFF      /* 255, 255, 255 */
#define ORANGE      0xFDA0      /* 255, 180,   0 */
#define GREENYELLOW 0xB7E0      /* 180, 255,   0 */
#define PINK        0xFC9F





extern UTFTGLUE Display ;
extern TouchScreen ts;



// data type of Id icon 
typedef struct 
{
    bool is_professser;
    string_t user_name;
    string_t universty;
    string_t department_1;
    string_t department_2;
    string_t Born;
    string_t number;

}User_ID_Data_t;




class Icons /*: public MCUFRIEND_kbv */ 

{
  private:
    uint16_t mode;
   void drawClockFace(int CENTER_X,int CENTER_Y,int CLOCK_RADIUS,int fram_color ,int numbers_color,int Background) 
   {
 

    Display.setColor(Background);
    Display.fillCircle(CENTER_X, CENTER_Y, CLOCK_RADIUS);
    Display.setColor(fram_color);
    Display.drawCircle(CENTER_X, CENTER_Y, CLOCK_RADIUS);
 

    for (int i = 0; i < 12; i++) {
      float angle = i * 30 * DEG_TO_RAD;
      int x1 = CENTER_X + (CLOCK_RADIUS - 10) * sin(angle);
      int y1 = CENTER_Y - (CLOCK_RADIUS - 10) * cos(angle);
      int x2 = CENTER_X + CLOCK_RADIUS * sin(angle);
      int y2 = CENTER_Y - CLOCK_RADIUS * cos(angle);
      Display.drawLine(x1, y1, x2, y2);


      char buf[3];
      sprintf(buf, "%d", i == 0 ? 12 : i);
      int tx = CENTER_X + (CLOCK_RADIUS - 20) * sin(angle) -8;
      int ty = CENTER_Y - (CLOCK_RADIUS - 20) * cos(angle) +8;
      Display.setTextColor(numbers_color);

      Display.setFont(BigFont);
      Display.setCursor(tx, ty);
      Display.write(buf);
     }
   }
   void drawHands(int CENTER_X,int CENTER_Y,int CLOCK_RADIUS,int h, int m, int s,
                           int hour_color,int min_color,int sec_color, word bgColor) 
   {
     static int last_hx=CENTER_X, last_hy=CENTER_Y, last_mx=CENTER_X, last_my=CENTER_Y, last_sx=CENTER_X, last_sy=CENTER_Y;


     float secAngle = (s * 6 * DEG_TO_RAD);
     float minAngle = (m * 6 * DEG_TO_RAD);
     float hourAngle = (h % 12 + m / 60.0) * 30 * DEG_TO_RAD;


     int hx = CENTER_X + (CLOCK_RADIUS - 50) * sin(hourAngle);
     int hy = CENTER_Y - (CLOCK_RADIUS - 50) * cos(hourAngle);

     int mx = CENTER_X + (CLOCK_RADIUS - 30) * sin(minAngle);
     int my = CENTER_Y - (CLOCK_RADIUS - 30) * cos(minAngle);

     int sx = CENTER_X + (CLOCK_RADIUS - 20) * sin(secAngle);
     int sy = CENTER_Y - (CLOCK_RADIUS - 20) * cos(secAngle);
     Display.setColor(Not_mode());
     Display.fillCircle(CENTER_X,CENTER_Y,5);
     Display.setColor(bgColor);
     Display.fillCircle(CENTER_X,CENTER_Y,2);

     Display.setColor(bgColor);
     Display.drawLine(CENTER_X, CENTER_Y, last_hx, last_hy);
     Display.drawLine(CENTER_X, CENTER_Y, last_mx, last_my);
     Display.drawLine(CENTER_X, CENTER_Y, last_sx, last_sy);


     Display.setColor(hour_color);
     Display.drawLine(CENTER_X, CENTER_Y, hx, hy);


     Display.setColor(min_color);
     Display.drawLine(CENTER_X, CENTER_Y, mx, my);


     Display.setColor(sec_color);
     Display.drawLine(CENTER_X, CENTER_Y, sx, sy);


     last_hx = hx; last_hy = hy;
     last_mx = mx; last_my = my;
     last_sx = sx; last_sy = sy;
   }
  public:

  
  void init()
  {
    Display.InitLCD();
  }
  void begin(uint16_t Mode)
  {
    mode=Mode;
  }

//*************************************************************************************************************

void WIFI_Icon(int x,int y,int range,uint16_t color_on,uint16_t color_off,int Background)
{
    uint16_t one=RED,two=RED,three=RED,four=RED;
    
    if(range==1){one=color_off;two=color_off;three=color_off;four=color_off;}
    else if(range==2){one=color_off;two=color_off;three=color_off;four=color_on;}
    else if(range==3){one=color_off;two=color_off;three=color_on;four=color_on;}
    else if(range==4){one=color_off;two=color_on;three=color_on;four=color_on;}
    else if(range==5){one=color_on;two=color_on;three=color_on;four=color_on;}
    Display.setColor(one);
    Display.fillCircle(x,y,20);
    Display.setColor(Background);
    Display.fillCircle(x,y,20-3);
    Display.setColor(two);
    Display.fillCircle(x,y,20-6);
    Display.setColor(Background);
    Display.fillCircle(x,y,20-9);
    Display.setColor(three);
    Display.fillCircle(x,y,20-12);
    Display.setColor(Background);
    Display.fillCircle(x,y,20-15);
    Display.setColor(Background);
    Display.fillRoundRect(x-21,y,x-21+42,y+20);

    Display.fillTriangle(x-3,y+5,x+24,y+5,x+21,y-20,Background);

    Display.fillTriangle(x+3,y+5,x-24,y+5,x-21,y-20,Background);

    Display.setColor(four);
    Display.fillCircle(x,y,20-18);
    Display.setTextSize(8);Display.setFont(BigFont);
    if(range==1){Display.setCursor(x+8,y+5); Display.setFont(BigFont); Display.setTextColor(color_off); 
    Display.write("!");}
    else if(range==0){Display.setColor(Background);Display.fillRoundRect(x-15,y-27,x-15+37,y-27+38);}
} 

void Battary_Icon(int x,int y,int range,uint16_t color,uint16_t txt_color,int Background,bool low_charge_red_color=true)
{   
    int txt_x=0;
    int txt_y_index = y+22;
    uint16_t color_Battary;
    if(low_charge_red_color==1)
    {
        if(range<20){color_Battary=RED; txt_x=(range>=10)?x-60:x-45;txt_color=Not_mode();}
        else if(range>=20){color_Battary=color;txt_x=(range==100)?x-65:x-58;}
    }
    else if(low_charge_red_color==0)
    {
        if(range<20){color_Battary=GREEN; txt_x=(range>=10)?x-53:x-45;}
        else if(range>=20){color_Battary=GREEN;txt_x=(range==100)?x-65:x-58;}
    }
    
    int rangeB=map(range,0,100,5,45);
    Display.setColor(color_Battary);
    Display.fillRoundRect(x,y,x+50,y+30);
    Display.setColor(Background);
    Display.fillRoundRect(x+3,y+3,(x+3)+50-6,(y+3)+30-6);
    Display.setColor(color_Battary);
    Display.fillRect(x+50-1,y+10,x+50+10,y+10+10);
    Display.setColor(color_Battary);
    Display.fillRoundRect(x+2,y+3,x+2+rangeB,y+3+30-6);

    Display.setCursor(txt_x+60,txt_y_index); Display.setFont(BigFont); Display.setTextColor(txt_color); 
    char range_as_str[10];
    sprintf(range_as_str, "%d", range);
    Display.setTextSize(8);Display.setFont(BigFont);
    Display.write(range_as_str);
    Display.write("%");
}

void Home_Icon(int x,int y,uint16_t color,int Background)
{
    
    Display.fillTriangle(x+30,y,(x+30)+25,y+15,(x+30)-25,y+15,color);
    Display.setColor(color);
    Display.fillRoundRect(x+10,y+12,x+10+40,y+12+25);
    Display.setColor(Background);
    Display.fillRoundRect(x+23,y+20,x+23+15,y+20+20);
}

void Setting_Icon(int x,int y,uint16_t color,int Background)
{
    Display.setColor(color);
    Display.fillCircle(x-10,y,10);
    Display.fillCircle(x-10,y-10,3);
    Display.fillCircle(x-10,y+10,3);
    Display.fillCircle(x,y-5,3);
    Display.fillCircle(x,y+5,3);
    Display.fillCircle(x-20,y-5,3);
    Display.fillCircle(x-20,y+5,3);
    Display.setColor(Background); 
    Display.fillCircle(x-10,y,5);
}

void Add_Icon(int x,int y,uint16_t color)
{
    Display.setColor(color);
    Display.fillRoundRect(x+15,y-2+15,x+15+30,y-2+15+5);
    Display.fillRoundRect(x+13+15,y-14+15,x+15+13+5,y-14+15+30);
}

void SD_Card_Icon(int x,int y)
{
    Display.setColor(WHITE);
    Display.fillRoundRect(x-5,y-5,x+5+30,y+5+35);
    Display.setColor(BLACK);
    Display.fillRoundRect(x,y,x+30,y+35);
    Display.setColor(WHITE);
    Display.fillRoundRect(x+15,y,x+15+17,y+8);
    Display.fillTriangle(x+30,y+8,x+17,y+8,x+17,y,BLACK);
    Display.setColor(YELLOW);
    Display.fillRoundRect(x+4,y+20,x+4+2,y+20+10);
    Display.fillRoundRect(x+11,y+20,x+11+2,y+20+10);
    Display.fillRoundRect(x+18,y+20,x+18+2,y+20+10);
    Display.fillRoundRect(x+30-5,y+20,x+30-5+2,y+20+10);
    Display.setColor(BLACK);
    Display.fillRect(x+12,y+1,(x+12)+5,(y+1)+8);
}

void Control_Icon(int x,int y,uint16_t color,int Background)
{
    Display.setColor(color);
    Display.fillRoundRect(x,y,x+40,y+3);
    Display.fillRoundRect(x,y+15,x+40,y+15+3);
    Display.fillRoundRect(x,y+30,x+40,y+30+3);
    
    Display.fillCircle(x+30-2,y+1,6);
    Display.fillCircle(x+10+2,y+15+1,6);
    Display.fillCircle(x+31-2,y+30+1,6);
    Display.setColor(Background);
    Display.fillCircle(x+30-2,y+1,6-3);
    Display.fillCircle(x+10+2,y+15+1,6-3);
    Display.fillCircle(x+31-2,y+30+1,6-3);
}

void Sensor_Icon(int x,int y,uint16_t color)
{
    Display.setColor(color);
    Display.fillRoundRect(x+3,y,x+3+30,y+10);
    Display.fillCircle(x+18,y+10,5);
    Display.drawLine(x+12,y+17,x+6,y+25);
    Display.drawLine(x+23,y+17,x+30,y+25);
    Display.drawLine(x+18,y+17,x+18,y+25);
     if(Is_Touch_Presssed())
    {
        if(pixel_x > x && pixel_x < x+30)
        {
            if(pixel_y > y&& pixel_y < y+25) 
            {
                Is_changed_happend = true;
                sensor_Icon_OnTap();
            }
        }
    }
}
void Power_off_Icon(int x,int y,int color,int Background)
{
    static bool draw=1;
    if((draw))
    {
        Display.setColor(color);
        Display.fillCircle(x, y,20);
        Display.setColor(Background);
        Display.fillCircle(x,y,17);
        Display.fillRect(x-8,y,x+8,y-20);
        Display.setColor(color);
        Display.fillRect(x-1,y,x+1,y-23);
        draw=0;
    }
    if(Is_Touch_Presssed())
    {
        if(pixel_x > x-20 && pixel_x < x+20)
        {
            if(pixel_y > y-20 && pixel_y < y+20) 
            {
                Is_changed_happend = true;
                Power_off_onTap(&draw);
            }
        }
    }
}

void Bluetooth_Icon(int x , int y ,int connect_status,int color,int underground_color)
{

 if(connect_status == BLuetooth_Status_open_and_not_connected || connect_status == BLuetooth_Status_open_and_connected )
 {
    Display.setColor(color);
    Display.fillTriangle( (x) , (y) , (x+15) , (y+10) , (x) , (y+20) , color);
    Display.fillTriangle( (x) , (y)+15 , (x+15) , (y+10)+15 , (x) , (y+20)+15 , color);

    Display.fillTriangle( (x-15) , (y+5) , (x) , (y+16) , (x-15) , (y+30) , color);

    Display.fillTriangle( (x-15)+2 , (y+5)+3 , (x)-2 , (y+16) , (x-15)+2 , (y+30)-3 , underground_color);

    Display.fillTriangle( (x)+2 , (y)+3 , (x+15)-2 , (y+10) , (x)+2 , (y+20)-4 , underground_color);
    Display.fillTriangle( ((x))+2 , ((y)+15)+3 , ((x+15))-2 , ((y)+15)+10 , ((x))+2 , ((y+20)+15)-3 , underground_color);
    Display.setColor(underground_color);
    Display.fillRect(x-18, y+2, (x-15)+3, (y+5)+30);

    if(connect_status == BLuetooth_Status_open_and_connected)
    {
        Display.setColor(color);
        Display.fillCircle(x-10, y+17,1);
        Display.fillCircle(x+13, y+18,1);
    }
 }
 else
 {
    Display.setColor(mode);
    Display.fillRect(x-20, y-10, (x-20)+42, (y-10)+50);
 }

}
uint16_t Not_mode()
{
   if(mode == BLACK) return WHITE;
   else return BLACK;
}
uint16_t Mode()
{
   return mode;
}
void set_mode(uint16_t Mode)
{
    mode = Mode;
    Display.fillScreen(mode); 
    begin(mode);
}
void fill_All_Display(uint16_t color,bool with_App_Bar = 1)
{
    if(!with_App_Bar)fill_Round_Rect(4,61,471,253,3,color);
    else Display.fillScreen(color); 
}
void clear_All_Display(bool with_App_Bar = 1)
{
    if(!with_App_Bar)fill_Round_Rect(4,61,471,253,3,mode);
    else Display.fillScreen(mode); 
}
void Reload_Icon(int x,int y,int raduis,uint16_t color ,uint16_t Background)
{
  for(int i=1;i<=8;i++)
  {
      if(i==1 || i == 2 || i==4 || i==8)
      {
         Display.drawCircleHelper(x,y,raduis,i,color);
         Display.drawCircleHelper(x,y,raduis,i*2,color);
         Display.drawCircleHelper(x,y,raduis,i*4,color);
      }
      delay(100);
         Display.drawCircleHelper(x,y,raduis,0x1,Background);
         Display.drawCircleHelper(x,y,raduis,0x2,Background);
         Display.drawCircleHelper(x,y,raduis,0x4,Background);
         Display.drawCircleHelper(x,y,raduis,0x8,Background);
  }
}
void Reload_Animation_Icon(int x, int y, int radius, uint16_t color, uint16_t Background) 
{
    int segments = 12; 
    int angleStep = 360 / segments;
    int delayTime = 100; 

    for (int i = 0; i < segments; i++) {

        float angle = i * angleStep * 3.14159 / 180; 

        int dotX = x + cos(angle) * radius;
        int dotY = y + sin(angle) * radius;

        Display.setColor(color);
        Display.fillCircle(dotX, dotY, 3);

        delay(delayTime);

        Display.setColor(Background);
        Display.fillCircle(dotX, dotY, 3);
    }
}

void Button_Icon(int x,int y,bool print_on_and_off = 0)
{
    Display.setColor(GREEN);
    Display.fillRoundRect(x, y, x+40, y+20);
    Display.fillCircleHelper(x+3,y+10,10,0x2,0,GREEN);
    Display.fillCircleHelper(x+35,y+10,10,0x1,0,GREEN);
    Display.setColor(WHITE);
    Display.fillCircle(x+34,y+10,8);
    if(print_on_and_off)
    {
         Display.setCursor(x-1,y+4); Display.setTextSize(2); Display.setTextColor(WHITE); 
         Display.write("ON");
    }

    Display.setColor(RED);
    Display.fillRoundRect(x, y+30, x+40, y+20+30);
    Display.fillCircleHelper(x+3,y+10+30,10,0x2,0,RED);
    Display.fillCircleHelper(x+35,y+10+30,10,0x1,0,RED);
    Display.setColor(WHITE);
    Display.fillCircle(x+4,y+10+30,8);
    if(print_on_and_off)
    {
         Display.setCursor(x+15,y+34); Display.setTextSize(2); Display.setTextColor(WHITE); 
         Display.write("O");Display.setCursor(x+25,y+34);Display.write("F");
         Display.setCursor(x+34,y+34);Display.write("F");
    }
}
void Big_Frame_window()
{
    
    Display.drawFastHLine(1,60-1,480-2,Not_mode());
    Display.setColor(Not_mode());
    Display.drawRoundRect(1,1,480-2,320-2);
}
void Draw_clock_window(int x,int y,int raduis,int frame_color,int number_color,int Background)
{
     drawClockFace(x,y,raduis,frame_color,number_color,Background);
}
void update_time_in_clock_window(int x,int y,int raduis,int hour,int min,int sec,
                                         int hour_color,int min_color,int sec_color,uint16_t Background)
{
     drawHands(x,y,raduis,hour, min, sec,hour_color,min_color,sec_color, Background);
}
void Add_new_WIFI_window(int color_window , char * SSID , char * paasword)
{
    Display.flush();
    Display.setColor(mode);
    Display.fillRoundRect(40, 70, 420, 300);
    Display.setColor(Not_mode());
    Display.drawRoundRect(40, 70, 420, 300);
    Display.drawRoundRect(380,70 ,420 ,110 );
    Display.setColor(RED);
    Display.fillRoundRect(380+1,70+1 ,420-1 ,110-1 );
    Display.setCursor(393,98);Display.setFont(BigFont);
    Display.setTextColor(Not_mode());Display.write("X");
    Display.setCursor(100,100);Display.setFont(BigFont);
    Display.setTextColor(Not_mode());Display.write("Add New WIFI");

    Display.setCursor(60,150);Display.setFont(BigFont);
    Display.setTextColor(Not_mode());Display.write("SSID");
    Display.setCursor(60,200);Display.setFont(BigFont);
    Display.setTextColor(Not_mode());Display.write("Pass");

    Display.setColor(Not_mode());
    Display.drawRoundRect(140,120 ,140+260 ,120+40 );
    Display.drawRoundRect(140,170 ,140+260 ,170+40 );

    Display.setColor(color_window);
    Display.fillRoundRect(170, 250,295, 290);
    Display.setCursor(180,277);Display.setFont(BigFont);
    Display.setTextColor(mode);Display.write("Connect");
    
    Display.setCursor(160,145);Display.setFont(SmallFont);
    
    Display.setTextColor(color_window);Display.write(SSID);
    Display.setCursor(160,195);Display.write(paasword);
}
void Display_Time(int x,int y,int hour,int minut,int sec,word_t time_name,int color)
{
    char Hour_as_str[3];
    char min_as_str[3];
    char sec_as_str[3];
    sprintf(Hour_as_str,"%d",hour);
    sprintf(min_as_str,"%d",minut);
    sprintf(sec_as_str,"%d",sec);
    Display.setFont(font_7_segment);
    Display.setTextColor(color);
    if(hour<10)
    {
       Display.setCursor(x,y+35);
       Display.write("0");
    }
    else
    {
      Display.setCursor(x,y+35);
    }
    Display.setFont(font_7_segment);
    Display.setTextColor(color);Display.write(Hour_as_str);
    Display.setColor(color);
    Display.fillCircle(x+75,y,5);
    Display.fillCircle(x+75,y+20,5);
    Display.setCursor(x+83,y+35);
    if(minut<10)
    {
       Display.setCursor(x+83,y+35);
       Display.write("0");
    }
    else
    {
      Display.setCursor(x+83,y+35);
    }
    Display.setFont(font_7_segment);Display.write(min_as_str);

    Display.setCursor(x+145,y);
    Display.setFont(BigFont);
    Display.write(sec_as_str);

    Display.setCursor(x+145,y+38);
    Display.setFont(BigFont);
    Display.write(time_name);
}
void Terminal_Icon(int x,int y)
{
    Display.setColor(WHITE);
    Display.fillRoundRect(x,y,x+50,y+50);
    Display.setColor(BLACK);
    Display.fillRoundRect(x+3,y+3,x-3+50,y-3+50);
    Display.setFont(BigFont);
    Display.setTextColor(GREEN);
    Display.setCursor(x+10,y+30);
    Display.write(">_");
}
void About_Icon(int x,int y ,int color,int Background)
{
    Display.setColor(color);
    Display.fillCircle(x,y,20);
    Display.setColor(Background);
    Display.fillCircle(x,y,17);
    Display.setFont(BigFont);
    Display.setTextColor(color);
    Display.setCursor(x-6,y+8);
    Display.write("!");
}
void Display_Date(int x,int y,int color,int text_color,int Background,int year,char * month_name,int Day,char * week_day_name)
{
    char year_as_str[5];
    char Day_as_str[5];
    sprintf(year_as_str,"%d",year);
    sprintf(Day_as_str,"%d",Day);

    Display.setColor(color);
    Display.fillRoundRect(x,y,x+130,y+130);
    Display.setFont(BigFont);
    Display.setColor(text_color);
    Display.setCursor(x+42,y+40);
    Display.write(week_day_name);
    Display.setCursor(x+47,y+65);
    Display.write(Day_as_str);
    Display.setCursor(x+42,y+90);
    Display.write(month_name);
    Display.setCursor(x+35,y+115);
    Display.write(year_as_str);

    Display.setColor(Background);
    Display.drawLine(x+15,y,x+10,y+8);
    Display.drawLine(x+15+1,y,x+10+1,y+8);
    Display.drawLine(x+15+2,y,x+10+2,y+8);
    Display.drawLine(x+15+3,y,x+10+3,y+8);
    Display.drawLine(x+15+4,y,x+10+4,y+8);

    Display.drawLine(x+15+20,y,x+10+20,y+8);
    Display.drawLine(x+15+1+20,y,x+10+1+20,y+8);
    Display.drawLine(x+15+2+20,y,x+10+2+20,y+8);
    Display.drawLine(x+15+3+20,y,x+10+3+20,y+8);
    Display.drawLine(x+15+4+20,y,x+10+4+20,y+8);

    Display.drawLine(x+15+40,y,x+10+40,y+8);
    Display.drawLine(x+15+1+40,y,x+10+1+40,y+8);
    Display.drawLine(x+15+2+40,y,x+10+2+40,y+8);
    Display.drawLine(x+15+3+40,y,x+10+3+40,y+8);
    Display.drawLine(x+15+4+40,y,x+10+4+40,y+8);

    Display.drawLine(x+15+60,y,x+10+60,y+8);
    Display.drawLine(x+15+1+60,y,x+10+1+60,y+8);
    Display.drawLine(x+15+2+60,y,x+10+2+60,y+8);
    Display.drawLine(x+15+3+60,y,x+10+3+60,y+8);
    Display.drawLine(x+15+4+60,y,x+10+4+60,y+8);

    Display.drawLine(x+15+80,y,x+10+80,y+8);
    Display.drawLine(x+15+1+80,y,x+10+1+80,y+8);
    Display.drawLine(x+15+2+80,y,x+10+2+80,y+8);
    Display.drawLine(x+15+3+80,y,x+10+3+80,y+8);
    Display.drawLine(x+15+4+80,y,x+10+4+80,y+8);

    Display.drawLine(x+15+100,y,x+10+100,y+8);
    Display.drawLine(x+15+1+100,y,x+10+1+100,y+8);
    Display.drawLine(x+15+2+100,y,x+10+2+100,y+8);
    Display.drawLine(x+15+3+100,y,x+10+3+100,y+8);
    Display.drawLine(x+15+4+100,y,x+10+4+100,y+8);

    Display.fillCircle(x+114-100,y+8,4);
    Display.fillCircle(x+114-80,y+8,4);
    Display.fillCircle(x+114-60,y+8,4);
    Display.fillCircle(x+114-40,y+8,4);
    Display.fillCircle(x+114-20,y+8,4);
    Display.fillCircle(x+114,y+8,4);

}

void fillRoundRect(int x,int y,int h,int w,int color)
{
    Display.setColor(color);
    Display.fillRoundRect(x,y,x+h,y+w);
}
void drawRoundRect(int x,int y,int h,int w,int color)
{
   Display.setColor(color);
   Display.drawRoundRect(x,y,x+h,y+w);
}
void drawLine(int x1 ,int y1 ,int x2 ,int y2 ,int color)
{
    Display.setColor(color);
    Display.drawLine(x1,y1,x2,y2);
}
void Display_Strings_and_numbers(int x,int y,const GFXfont* font,int color, const char * string)
{
    Display.setCursor(x,y);
    Display.setTextColor(color);
    Display.setFont(font);
    Display.write(string);
}

void fill_circle_with_end(int x,int y,int radius,int end_volume,int color ,int end_color)
{
  Display.setColor(end_color);
  Display.fillCircle(x,y,radius);
  Display.setColor(color);
  Display.fillCircle(x,y,radius-end_volume);
}
void fill_rectangle_with_end(int x,int y,int h,int w,int end_volume,int color,int end_color)
{
    fillRoundRect(x,y,h,w,end_color);
    fillRoundRect(x + end_volume,y + end_volume,h - 2*end_volume,w - 2*end_volume,color);
}

void UP_Arrow_Icon(int x,int y, uint16_t color)
{
  Display.fillTriangle(x-20-6,y+25+3,x,y-6,x+20+6,y+25+3,Not_mode());
  Display.fillTriangle(x-20,y+25,x,y,x+20,y+25,color);
  fill_rectangle_with_end(x-10,y+25,20,20,3,color,Not_mode());
  Display.setColor(color);
  Display.fillRect(x-10+3,y+25,x-10 + 20-3, y+25+20-3);
}
void DOWN_Arrow_Icon(int x,int y, uint16_t color)
{
  Display.fillTriangle(x-20-6,y+25-3,x,y-6+60,x+20+6,y+25-3,Not_mode());
  Display.fillTriangle(x-20,y+25,x,y+50,x+20,y+25,color);
  fill_rectangle_with_end(x-10,y+5,20,20,3,color,Not_mode());
  Display.setColor(color);
  Display.fillRect(x-10+3,y+8,x-10 + 20-3, y+25+20-3);
}
void LEFT_Arrow_Icon(int x,int y, uint16_t color)
{
  Display.fillTriangle(x-6,y,x+25+3,y-25-6,x+25+3,y+25+6,Not_mode());
  Display.fillTriangle(x,y,x+25,y-25,x+25,y+25,color);
  fill_rectangle_with_end(x+25,y-8-1,20,20,3,color,Not_mode());
  Display.setColor(color);
  Display.fillRect(x+25,y-8+3-1,x+25 + 20-3, y-8+20-3-1);
}
void RIGHT_Aroow_Icon(int x,int y, uint16_t color)
{
  Display.fillTriangle(x+6+50,y,x+25-3,y-25-6,x+25-3,y+25+6,Not_mode());
  Display.fillTriangle(x+50,y,x+25,y-25,x+25,y+25,color);
  fill_rectangle_with_end(x+5,y-8-1,20,20,3,color,Not_mode());
  Display.setColor(color);
  Display.fillRect(x+8,y-8+3-1,x+5 + 20+3, y-8+20-3-1);
}

void SEDHOM_LOGO(int x,int y,int color_pins,int color,int color_string)
{
    for (int i = 10; i< 140; i+=20)  
    { 
      fillRoundRect(x+i,y-18,10,20,color_pins);
      fillRoundRect(x+i,y+148,10,20,color_pins);
      fillRoundRect(x-18,y+i,20,10,color_pins);
      fillRoundRect(x+148,y+i,20,10,color_pins);
     }
    fillRoundRect(x,y,150,150,color_string);
    fillRoundRect(x+10,y+10,130,130,color);
    Display.setColor(color_string);
    Display.fillCircle(x+120,y+30,6);
    Display_Strings_and_numbers(x+25,y+60,BigFont,color_string,"SEDHOM");
    Display_Strings_and_numbers(x+20,y+100,BigFont,color_string,"2222006");
}

void start_after_lock_all_screen(int color,int color_pin,int color_string,int color_screen)
{
    Display.fillScreen(color_screen);
    Display_Strings_and_numbers(165,30,BigFont,color_string,"SEDHOM OS");
    SEDHOM_LOGO(160,80,color_pin,color,color_string);
    Display_Strings_and_numbers(20,300,SmallFont,color_string,"Eng.Mustafa Sedhom");
    Display_Strings_and_numbers(330,300,SmallFont,color_string,"SEDHOM OS v2.0.2");
}

void Color_Icon(int x,int y)
{
    fillRoundRect(x,y,30,30,MAGENTA);
    fillRoundRect(x+5,y+5,30,30,RED);
    fillRoundRect(x+10,y+10,30,30,BLUE);
    fillRoundRect(x+15,y+15,30,30,GREEN);

}
void Time_Icon(int x,int y,int color,int Background_color)
{
    Display.setColor(color);
    Display.fillCircle(x,y,20);
    Display.setColor(Background_color);
    Display.fillCircle(x,y,17);
    fillRoundRect(x-2,y-14,3,12,color);
    fillRoundRect(x,y-1,10,3,color);
    Display.setColor(color);
    Display.fillCircle(x,y,4);
}
void Date_Icon(int x,int y,int color,int Background_color)
{
    fillRoundRect(x,y,45,48,color);
    fillRoundRect(x+2,y+10,41,36,Background_color);
    Display.setColor(Background_color);
    Display.fillCircle(x+5,y+5,3);
    Display.fillCircle(x+23,y+5,3);
    Display.fillCircle(x+40,y+5,3);
    Display_Strings_and_numbers(x+20,y+24,SmallFont,color,"6");
    Display_Strings_and_numbers(x+12,y+33,SmallFont,color,"Jun");
    Display_Strings_and_numbers(x+9,y+46,SmallFont,color,"2025");
}

void Back_Arrow_Icon(int x,int y, uint16_t color)
{
  Display.fillTriangle(x-6,y,x+25+3,y-15-6,x+25+3,y+15+6,Not_mode());
  Display.fillTriangle(x,y,x+25,y-15,x+25,y+15,color);
  fill_rectangle_with_end(x+25,y-8-1,25,18,3,color,Not_mode());
  Display.setColor(color);
  Display.fillRect(x+25,y-8+3-1,x+25 + 20-3, y-8+20-3-3);
}
void After_Arrow_Icon(int x,int y, uint16_t color)
{
  Display.fillTriangle(x+6+50,y,x+25-3,y-15-6,x+25-3,y+15+6,Not_mode());
  Display.fillTriangle(x+50,y,x+25,y-15,x+25,y+15,color);
  fill_rectangle_with_end(x,y-8-1,25,18,3,color,Not_mode());
  Display.setColor(color);
  Display.fillRect(x+15,y-8+3-1,x+5 + 20+6, y-8+20-3-3);
}

void fill_Circle(int x,int y,int r,int color)
{
    Display.setColor(color);
    Display.fillCircle(x,y,r);
}
void draw_Circle(int x,int y,int r,int color)
{
    Display.setColor(color);
    Display.drawCircle(x,y,r);
}
void Switch_Icon(int x,int y,Color_t color_on,Color_t color_off,bool state)
{
    Color_t color = color_off;
    int index = x+57;
    int index_str = x-13;
    word_t state_str = "OFF";
    color = (state) ? color_on : color_off ;
    index = (state) ? (x+5) : (x+57) ;
    index_str = (state) ? (x+40) : (x-13) ;
    state_str = (state) ? "ON" : "OFF" ;

    fillRoundRect(x,y,60,40,color);
    fill_Circle(x,y+20,20,color);
    fill_Circle(x+60,y+20,20,color);

    fill_Circle(index,y+20,15,Not_mode());//not mode
    Display_Strings_and_numbers((index_str),y+28,BigFont,mode,state_str);//mode
}
void label_Icon(int x,int y,int h,int w,int end,word_t name,word_t string_in_label,Color_t color_str_in_label,Color_t color_name,Color_t color,Color_t Background)
{
    Color_t label_color_in_func = color;
    float num = atoi(string_in_label);
    if(string_in_label == "OFF" || string_in_label == "off" || num == 0){label_color_in_func = RED;}
    else if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = color;}
    //else {label_color_in_func = color;}
    if(string_in_label == "ON" || string_in_label == "on" || num >= 1){label_color_in_func = color;}
   fillRoundRect(x,y,h,w,label_color_in_func); 
   fillRoundRect(x+end,y+end,h-2*end,w-2*end,Background); 
   Display_Strings_and_numbers(x-120,y+(0.6*w),BigFont,color_name,name);
   Display_Strings_and_numbers(x+10,y+(0.6*w),SmallFont,color_str_in_label,string_in_label);
}

void slide_Icon(int x,int y,int h,byte_t range ,Color_t color_active,Color_t color_not_active ,Color_t ball_color,Color_t box_color,Color_t range_in_box_color)
{
    long index = map(range,0,100,0,h);
    char range_str[5];
    sprintf(range_str,"%d",range);

    fillRoundRect(x,y,h,10,color_not_active);
    fillRoundRect(x,y,index,10,color_active);
    fill_Circle(x+index,y+5,10,Not_mode());
    fill_rectangle_with_end(x+h+15,y-10,40,30,3,Mode(),box_color);
    Display_Strings_and_numbers(x+h+8+15,y+19-8,SmallFont,range_in_box_color,range_str);
}
void file_Icon(int x,int y,Color_t color,Color_t end_color,Color_t Background,Color_t file_extend_color,word_t file_extend)
{
    fill_rectangle_with_end(x,y,50,60,3,Background,end_color);
    fill_rectangle_with_end(x-10,y+30,30,20,3,color,end_color);
    fill_rectangle_with_end(x+29,y-1,30,21,3,Background,Background);
    Display.fillTriangle(x+6+43,y+20,x+29,y,x+29,y+20,end_color);
    Display.fillTriangle(x+43,y+18,x+29+3,y+6,x+29+3,y+18,color);
    fillRoundRect(x+10,y+15,15,2,end_color);
    fillRoundRect(x+10,y+25,30,2,end_color);    
    fillRoundRect(x+25,y+35,15,2,end_color);
    fillRoundRect(x+25,y+45,15,2,end_color);
    Display_Strings_and_numbers(x-5,y+46,SmallFont,file_extend_color,file_extend);
}
void folder_Icon(int x,int y,Color_t folder_color)
{
    fillRoundRect(x,y,30,40,folder_color);
    fillRoundRect(x+28,y+5,40,20,folder_color);
    fill_rectangle_with_end(x+5,y+10,60,20,1,WHITE,BLACK);
    fillRoundRect(x,y+20,68,35,folder_color);
    Display.drawFastHLine(x,y+20,69,BLACK);
    //Display_Strings_and_numbers(x+15,y+40,SmallFont,Not_mode(),"Folder");
}
void BOX_and_TXT_Icon(int x_pos,int y_pos,int h,int w,Color_t color_box,const GFXfont* font,Color_t TXT_color,word_t TXT)
{
    fillRoundRect(x_pos,y_pos,h,w,color_box);
    // Display_Strings_and_numbers(x_pos+13,y_pos+20,font,TXT_color,TXT);
    Display.setCursor(x_pos+13,y_pos+25);
    Display.setTextColor(TXT_color);
    Display.setFont(font);
    Display.write(TXT);
}
void BOX_with_end_and_TXT_Icon(int x_pos,int y_pos,int h,int w,Color_t color_box,const GFXfont* font,Color_t TXT_color,int end ,Color_t color_end,word_t TXT)
{
    // fillRoundRect(x_pos,y_pos,h,w,color_box);
    fill_rectangle_with_end(x_pos,y_pos,h,w,end,color_box,color_end);
    // Display_Strings_and_numbers(x_pos+13,y_pos+20,font,TXT_color,TXT);
    Display.setCursor(x_pos+(h*.2),y_pos+(w*.8));
    Display.setTextColor(TXT_color);
    Display.setFont(font);
    Display.write(TXT);
}
void BOX_and_TXT_seven_segment_Icon(int x_pos,int y_pos,int h,int w,Color_t color_box,const GFXfont* font,Color_t TXT_color,word_t TXT)
{
    fillRoundRect(x_pos,y_pos,h,w,color_box);
    // Display_Strings_and_numbers(x_pos+13,y_pos+20,font,TXT_color,TXT);
    Display.setCursor(x_pos+(h*.3),y_pos+53);
    Display.setTextColor(TXT_color);
    Display.setFont(font);
    Display.write(TXT);
}
void fill_Round_Rect(int x,int y,int h,int w,int raduis,Color_t color)
{
     Display.set_Round_Of_Shapes(raduis);
     fillRoundRect(x,y,h,w,color);
}
void draw_Round_Rect(int x,int y,int h,int w,int raduis,Color_t color)
{
     Display.set_Round_Of_Shapes(raduis);
     drawRoundRect(x,y,h,w,color);
}

void Container(int x ,int y,int h ,int w,int raduis,Color_t color,void (*OnTap)())
{
    fill_Round_Rect(x,y,h,w,raduis,color);
    if(Is_Touch_Presssed())
    {
        if(pixel_x > x && pixel_x < x+h)
        {
            if(pixel_y > y && pixel_y < y+w) 
            {
                Is_changed_happend = true;
                OnTap();
            }
        }
    }
}

void Text(int x,int y,const GFXfont* font,Color_t color,const string_t string)
{
   Display_Strings_and_numbers(x,y,font,color,string);
}

void Divider_vertical(int x,int y,int length , int thikness,int color)
{
    fill_Round_Rect(x,y,length,thikness,1,color);
}
void Divider_Horezontal(int x,int y,int length , int thikness,int color)
{
    fill_Round_Rect(x,y,thikness,length,1,color);
}

int Screen_lenght()
{
    return(Display.height());
}
int Screen_width()
{
    return(Display.width());
}
void ID_Card_Icon(int x,int y,Color_t color,Color_t main_font_color,Color_t font_color,
    Color_t image_background,bool default_image,bool eye,bool prof,
    char* name,char* unversity,char* department_1,char* department_2,char* Born,char* number,
     void (*OnTap)())
{
    #define x1   x
    #define y1   y

    #define h1    270
    #define w1    200

    Color_t color_id =0;
    if(color == WHITE) color_id = BLACK;
    else if(color == BLACK) color_id = WHITE;
    else  color_id = color;
    Container(x1-3,y1-3,h1+6,w1+6,20,color_id,OnTap);
    Container(x1,y1,h1,w1,20,color,OnTap);
    Text(((prof)?x1+60:x1+80),y1+20,BigFont,main_font_color,((prof)?"PROFESSER":"STUDENT"));
    Divider_vertical(x1+10,y1+35,h1-20,3,main_font_color);
    Text(x1+30,y1+55,SmallFont,font_color,"IDENTITY CARD");

    Text(x1+10,y1+70,SmallFont,main_font_color,((prof)?"Dr Name":"Nmae"));
    Text(x1+10,y1+85,SmallFont,font_color,name);

    Text(x1+10,y1+100,SmallFont,main_font_color,((prof)?"Unversity":"Stadies at"));
    Text(x1+10,y1+115,SmallFont,font_color,unversity);

    Text(x1+10,y1+130,SmallFont,main_font_color,"Department");
    Text(x1+10,y1+145,SmallFont,font_color,department_1);
    Text(x1+10,y1+160,SmallFont,font_color,department_2);

    Text(x1+10,y1+175,SmallFont,main_font_color,"Born");
    Text(x1+10,y1+190,SmallFont,font_color,Born);

    Container(x1+160,y1+45,100,110,0,image_background,OnTap);
    
    if(default_image)
    {
        fill_Circle(x1+210,y1+160,40,DARKGREY);
        fill_Circle(x1+210,y1+100,25,DARKGREY);
        if(eye)
        {
            fill_Circle(x1+220,y1+97,7,BLACK);
            fill_Circle(x1+220,y1+97,5,DARKGREY);
            fill_Circle(x1+220,y1+97,1,BLACK);//eye
            Divider_vertical(x1+205,y1+97,10,2,BLACK);
            fill_Circle(x1+200,y1+97,7,BLACK);
            fill_Circle(x1+200,y1+97,5,DARKGREY);
            fill_Circle(x1+200,y1+97,1,BLACK);//eye
            Divider_vertical(x1+225,y1+97,10,2,BLACK);
            Divider_vertical(x1+185,y1+97,10,2,BLACK);
        }
    }
    fill_Round_Rect(x1+150,y1+155,120,45,15,color);
    Text(x1+157,y1+175,SmallFont,font_color,number);
}
void New_page_With_App_Bar(bool reverse_icon,bool power_off_icon)
{
    // fill_Round_Rect(6,4,130,52,3,mode);
    Big_Frame_window();
    App_Bar(); 
    New_page(reverse_icon,power_off_icon,0);
    if(power_off_icon)Power_off_Icon(40,30,RED,Mode());
    if(reverse_icon)Back_Arrow_Icon(20,30,Back_arraw_color);
}
void New_page(bool reverse_icon,bool power_off_icon,bool no_delet_reverse_icon = 1)
{
    fill_Round_Rect(no_delet_reverse_icon ? 75:6,4,no_delet_reverse_icon ? 60:130,52,3,mode);
    if(!no_delet_reverse_icon)
    {
        if(power_off_icon)Power_off_Icon(40,30,RED,Mode());
        if(reverse_icon)Back_Arrow_Icon(20,30,Back_arraw_color);
    }
}
void App_Bar()
{
    WIFI_Icon(373,38,WIFI_state,WIFI_ON_color,WIFI_OFF_color,Mode());
    Bluetooth_Icon(330,12,Bluetooth_state,BLE_color,Mode());
    Battary_Icon(410,15,Battary_Value,Battary_color,Not_mode(),Mode());
    Display_Time(137,20,Hour,min,sec,time_name,Time_color);
}







};

