#include "WString.h"
#include "Arduino.h"
#include "SEDHOM_OS_Windos_And_Screens.h"

Icons_t Icon;

UTFTGLUE Display(0, LCD_RS, LCD_WR, LCD_CS, LCD_RST, LCD_RD);

void APP_Bar_And_Big_Window() 
{
    Icon.Big_Frame_window();
    Icon.WIFI_Icon(373,38,WIFI_state,WIFI_ON_color,WIFI_OFF_color,Icon.Mode());
    Icon.Bluetooth_Icon(330,12,Bluetooth_state,BLE_color,Icon.Mode());
    Icon.Battary_Icon(410,15,Battary_Value,Battary_color,Icon.Not_mode(),Icon.Mode());
    Icon.Display_Time(137,20,Hour,min,sec,time_name,Time_color);
}
void rectangle_in_screen(int h,int w)
{
    Display.setColor(Icon.Not_mode());
    Display.drawRoundRect(30,70,30+w,70+h);
    Display.drawRoundRect(150,70,150+w,70+h);
    Display.drawRoundRect(270,70,270+w,70+h);
    Display.drawRoundRect(390,70,390+w,70+h);

    Display.drawRoundRect(30,180,30+w,180+h);
    Display.drawRoundRect(150,180,150+w,180+h);
    Display.drawRoundRect(270,180,270+w,180+h);
    Display.drawRoundRect(390,180,390+w,180+h);
}
void Depart_screen()
{
    Display.drawFastVLine(237,60,259,Icon.Not_mode());

    Display.drawFastHLine(2,130,476,Icon.Not_mode());
    Display.drawFastHLine(2,190,476,Icon.Not_mode());
    Display.drawFastHLine(2,250,476,Icon.Not_mode());
}
void terminal_clear()
{
    Icon.fillRoundRect(3,60,473,257,BLACK);
}
word_t get_answer_for_this_command(word_t command)
{
    #define I_Do_that   "ok"
    #define print_befor_answer()  line+=15;Display.setCursor(25,line);Display.setColor(color_char_answer);\
                                                                       Display.write("$$$? ");
    #define print_answer(answer)       Display.setColor(color_CMD_answer);Display.write(answer);
    #define CMD_answer(answer)         print_befor_answer();print_answer(answer);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(command == "set my name = Mustafa Sedhom"){return "welcome to SEDHOM OS Mustafa Sedhom";}
    else if(command == "open file_1.txt"){return "-> \"my name is mustafa sedhom iam 19 years old.\"";}
    else if(command == "control GPIO 6 as PWM = 96"){return I_Do_that;}
    else if(command == "Read from GPIO 11"){return "GPIO 11 now is => ON(1)";}
    else if(command == "CD Control")
    {   dir = "S::SEDHOM::Control -> "; return 2;}
    else if(command == "open SD Card folder")
    {
        CMD_answer("choose folders<> and files[] => ");
        CMD_answer("1.[ sedhom.cpp ]            2.< Setting >");
        CMD_answer("3.< WIFI Config >           4.[ SEDHOM.png ]");
        CMD_answer("5.< Bluetooth Config >");
        dir = "S::SEDHOM::Control::SD Card -> ";
        return 2;
    }
    else if(command == "5"){dir="S::SEDHOM::Control::SD Card::WIFI Config -> " ;return 1;}
    else if(command == "clear"){terminal_clear(); line = 60;return 2;}


    else{return 0;}
}
void set_number(int x,int y,Color_t color_inc,Color_t color_dec,Color_t box_inc_color,Color_t box_dec_color,Color_t box_num_color,Color_t color_num ,byte_t num)
{
    char c[4];
    sprintf(c,"%d",num);
     Icon.BOX_with_end_and_TXT_Icon(x,y,30,30,box_inc_color,BigFont,color_inc,3,Icon.Not_mode(),"+");
     Icon.BOX_with_end_and_TXT_Icon(x+40,y-20,80,70,box_num_color,BigFont,0,3,Icon.Not_mode(),"");
     Icon.Display_Strings_and_numbers(x+50,y+40,SevenSegNumFont,color_num,c);
     Icon.BOX_with_end_and_TXT_Icon(x+130,y,30,30,box_dec_color,BigFont,color_dec,3,Icon.Not_mode(),"-");
}
void set_number(int x,int y,Color_t color_inc,Color_t color_dec,Color_t box_inc_color,Color_t box_dec_color,Color_t box_num_color,Color_t color_num)
{
     Icon.BOX_with_end_and_TXT_Icon(x,y,30,30,box_inc_color,BigFont,color_inc,3,Icon.Not_mode(),"+");
     Icon.BOX_with_end_and_TXT_Icon(x+40,y-20,80,70,box_num_color,BigFont,0,3,Icon.Not_mode(),"");
     Icon.BOX_with_end_and_TXT_Icon(x+130,y,30,30,box_dec_color,BigFont,color_dec,3,Icon.Not_mode(),"-");
}
void set_number_with_resize_box(int x,int y,int h,int w,Color_t color_inc,Color_t color_dec,Color_t box_inc_color,Color_t box_dec_color,Color_t box_num_color,Color_t color_num ,int num)
{
    char c[6];
    sprintf(c,"%d",num);
     Icon.BOX_with_end_and_TXT_Icon(x,y,30,30,box_inc_color,BigFont,color_inc,3,Icon.Not_mode(),"+");
     Icon.BOX_with_end_and_TXT_Icon(x+40,y-20,h,w,box_num_color,BigFont,0,3,Icon.Not_mode(),"");
     Icon.Display_Strings_and_numbers(x+50,y+40,SevenSegNumFont,color_num,c);
     Icon.BOX_with_end_and_TXT_Icon(x+h+50,y,30,30,box_dec_color,BigFont,color_dec,3,Icon.Not_mode(),"-");
}
void Terminal_do()
{
    ///////////////////////////////////////////////


    #define y_index  60

    //////////////////////////////////////////////
    Display.setFont(SmallFont);
    Display.setCursor(10,line);
    ///////////////////////////////////////////////
    if(colors_in_terminal_or_GREEN)
    {
       color_CMD_answer = BLUE ;
       color_char_answer =  WHITE ;
       color_error_answer =  ORANGE ;
       color_dir =  RED ;
    } 
    else
    {
       color_CMD_answer = GREEN ;
       color_char_answer =  GREEN ;
       color_error_answer =  GREEN ;
       color_dir =  GREEN ;
    }
    #define print_dir()       line+=15;Display.setCursor(10,line);Display.setColor(color_dir);\
                                                                       Display.write(dir);
    #define print_befor_answer()  line+=15;Display.setCursor(25,line);Display.setColor(color_char_answer);\
                                                                       Display.write("$$$? ");
    #define print_answer(answer)       Display.setColor(color_CMD_answer);Display.write(answer);
    #define print_wrong(answer)       Display.setColor(color_error_answer);Display.write(answer);
    #define CMD_answer(answer)         print_befor_answer();print_answer(answer);
    #define CMD_answer_wrong(answer)         print_befor_answer();print_wrong(answer);
    #define print_command(command)       Display.setColor(color_command);Display.write(command);
    #define wrong_func()                  "error not exist"
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static word_t last_command = 0;
    if(last_command != command)
    {
        print_dir();
        print_command(command);
        // CMD_answer(get_answer_for_this_command(command));
        word_t answer =get_answer_for_this_command(command);
        if(answer == 0){CMD_answer_wrong(wrong_func());}
        else if(answer == 1){print_dir();}
        else if(answer == 2){}
        else {CMD_answer(answer);}
        last_command = command;
    }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(line > 305){terminal_clear(); line = y_index;}
}
void new_window(word_t name_window)
{
    Icon.fill_Round_Rect(40,70,380,230,5,Icon.Mode());
    Icon.draw_Round_Rect(40,70,380,230,5,Icon.Not_mode());
    Icon.draw_Round_Rect(380,70,40,40,5,Icon.Not_mode());
    Icon.fill_Round_Rect(380+2,70+2,40-4,40-4,5,RED);
    Icon.Text(393,95,BigFont,Icon.Not_mode(),"X");
    Icon.Text(100,90,BigFont,Icon.Not_mode(),name_window);
}
void draw_switch_after_change()
{
    {
        Icon.Switch_Icon(150,80,Switch_on_color,Switch_off_color,Switch_1_state);
        Icon.Switch_Icon(380,80,Switch_on_color,Switch_off_color,Switch_2_state);

        Icon.Switch_Icon(150,140,Switch_on_color,Switch_off_color,Switch_3_state);
        Icon.Switch_Icon(380,140,Switch_on_color,Switch_off_color,Switch_4_state);

        Icon.Switch_Icon(150,200,Switch_on_color,Switch_off_color,Switch_5_state);
        Icon.Switch_Icon(380,200,Switch_on_color,Switch_off_color,Switch_6_state);

        Icon.Switch_Icon(150,260,Switch_on_color,Switch_off_color,Switch_7_state);
        Icon.Switch_Icon(380,260,Switch_on_color,Switch_off_color,Switch_8_state);


        Icon.Display_Strings_and_numbers(10,107,BigFont,TXT_color_in_Switch_screen, switch_1_name);
        Icon.Display_Strings_and_numbers(240,107,BigFont,TXT_color_in_Switch_screen,switch_2_name);

        Icon.Display_Strings_and_numbers(10,167,BigFont,TXT_color_in_Switch_screen, switch_3_name);
        Icon.Display_Strings_and_numbers(240,167,BigFont,TXT_color_in_Switch_screen,switch_4_name);

        Icon.Display_Strings_and_numbers(10,227,BigFont,TXT_color_in_Switch_screen, switch_5_name);
        Icon.Display_Strings_and_numbers(240,227,BigFont,TXT_color_in_Switch_screen,switch_6_name);

        Icon.Display_Strings_and_numbers(10,287,BigFont,TXT_color_in_Switch_screen, switch_7_name);
        Icon.Display_Strings_and_numbers(240,287,BigFont,TXT_color_in_Switch_screen,switch_8_name);
    }
}
void draw_timer_screen()
{
    /////////////     set Date
    //month
    set_number(120,82,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,Timer_clock_month);
    //day
    set_number(300,82,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,Timer_clock_day);
    // Icon.Display_Strings_and_numbers(160,150,BigFont,TXT_color_in_Timer_clock_screen,"Month");
    // Icon.Display_Strings_and_numbers(360,150,BigFont,TXT_color_in_Timer_clock_screen,"Day");
    ////////////////////////////////////////////////////////////////////////////
    // Display.drawFastHLine(2,152,477,Icon.Not_mode());
    /////////////    set Time
    Icon.Display_Strings_and_numbers(5,205,BigFont,TXT_color_in_Timer_clock_screen,"TIME->");
    //hour
    set_number(120,180,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,Timer_clock_hour);
    //min
    set_number(300,180,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,Timer_clock_min);
    //sec
    set_number(210,250,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,Timer_clock_sec);
    // Icon.Display_Strings_and_numbers(170,248,BigFont,TXT_color_in_Timer_clock_screen,"Hour");
    // Icon.Display_Strings_and_numbers(340,248,BigFont,TXT_color_in_Timer_clock_screen,"Minute");
    // Icon.Display_Strings_and_numbers(245,318,BigFont,TXT_color_in_Timer_clock_screen,"Second");

    // Icon.BOX_with_end_and_TXT_Icon(410,255,50,50,box_num_color,BigFont,color_num,3,Icon.Not_mode(),"");
    Display.setColor(color_num);
    Display.setCursor(410+8,255+35);
    Display.write(Timer_clock_time_name);
    
    // Icon.BOX_with_end_and_TXT_Icon(5,235,160,80,box_num_color,BigFont,color_num,3,Icon.Not_mode(),"");
    // Icon.Display_Strings_and_numbers(12,258,BigFont,TXT_color_in_Timer_clock_screen,"Set Clock");
    Icon.Switch_Icon(50,265,Switch_on_color,Switch_off_color,Switch_Timer_clock);
}
void set_touch_nmber(int x,int y,byte_t * var)
{
    if(pixel_x > x && pixel_x <x+30)
    {if(pixel_y > y && pixel_y <y+30){if(*(var) != 60){(*(var))++;draw_timer_screen();}}}
    if(pixel_x > x +130 && pixel_x < x +30 +130)
    {if(pixel_y > y && pixel_y <y+30){if(*(var) != 0){(*(var))--;draw_timer_screen();}}}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//screens
void init_Rotation_and_mode(int Rotation , Color_t Mode) 
{
    // icon.init();
    Icon.init();
    Display.setRotation(Rotation);        
    // icon.set_mode(Mode);
    Icon.set_mode(Mode);
}
void main_Screen() 
{
    // Icon.clear_All_Display(Icon.Mode());
    Icon.Big_Frame_window();
    int color_mix = Display.color565(0,0,255);
    // Display.setColor(color_mix);
    // APP_Bar_And_Big_Window();
    // Icon.Power_off_Icon(40,30,RED,Icon.Mode());
    Icon.New_page_With_App_Bar(false,true);
    Icon.Home_Icon(70,10,CYAN,Icon.Mode());


    Display.setColor(Icon.Not_mode());
    rectangle_in_screen(60,60); 

    Display.setFont(BigFont);
    Display.setTextColor(TXT_color_in_main_screen);
    Display.setCursor(15,160);Display.write("Switch");
    Display.setCursor(133,160);Display.write("Slider");
    Display.setCursor(253,160);Display.write("Sensor");
    Display.setCursor(385,160);Display.write("About");

    Display.setCursor(35,270);Display.write("CMD");
    Display.setCursor(135,270);Display.write("SDcard");
    Display.setCursor(255,270);Display.write("Setting");
    Display.setCursor(400,270);Display.write("Add");

    Icon.Button_Icon(41,75);
    Icon.Control_Icon(160,85,slider_Icon_color,Icon.Mode());
    Icon.Sensor_Icon(283,90,sensor_Icon_color);
    Icon.About_Icon(420,100,About_Icon_color,Icon.Mode());

    Icon.Terminal_Icon(35,185);
    Icon.SD_Card_Icon(166,192);
    Icon.Setting_Icon(310,210,Setting_Icon_color,Icon.Mode());
    Icon.Add_Icon(390,195,ADD_Icon_color);
}
void start_screen() 
{
    Icon.start_after_lock_all_screen(BLACK,WHITE,GREEN,BLACK);
}
void lock_screen() 
{
    // Icon.clear_All_Display();
    Icon.After_Arrow_Icon(400,280,GREEN);
    Icon.Draw_clock_window(160,160,150,lock_screen_color,Icon.Not_mode(),Icon.Mode());
    Icon.BOX_and_TXT_Icon(200,145,50,30,lock_screen_color,BigFont,Icon.Not_mode(),"");
    Icon.Display_Strings_and_numbers(210,168,BigFont,Icon.Not_mode(),time_name);
    Icon.update_time_in_clock_window(160,160,160,Hour,min,sec,BLUE,GREEN,RED,Icon.Mode());
    Icon.Display_Date(330,30,lock_screen_color,Icon.Not_mode(),Icon.Mode(),year,month_name[month],day,day_name[day_in_week]);
}
void LCD_3D_Controll_Axis_Screen()
{
//   Display.fillScreen(Icon.Mode());
  Icon.fill_rectangle_with_end(50,20,80,80,3,YELLOW,Icon.Not_mode());
  Icon.fill_rectangle_with_end(270,20,80,80,3,CYAN,Icon.Not_mode());
  Icon.fill_rectangle_with_end(270,200,80,80,3,GREEN,Icon.Not_mode());
  Icon.fill_rectangle_with_end(50,200,80,80,3,DARKGREY,Icon.Not_mode());
  Icon.Home_Icon(48,23,Icon.Not_mode(),YELLOW);
  Icon.Home_Icon(290,23,Icon.Not_mode(),CYAN);
  Icon.Home_Icon(290,237,Icon.Not_mode(),GREEN);
  Icon.Home_Icon(48,237,Icon.Not_mode(),DARKGREY);
  Icon.Display_Strings_and_numbers(55,90,BigFont,Icon.Not_mode(),"X");
  Icon.Display_Strings_and_numbers(332,95,BigFont,Icon.Not_mode(),"Y");
  Icon.Display_Strings_and_numbers(330,220,BigFont,Icon.Not_mode(),"Z");


  Display.setColor(Icon.Not_mode());
  Display.fillCircle(200,150,135);
  Display.setColor(Icon.Mode());
  Display.fillCircle(200,150,132);
  #define clean_color  Icon.Mode()
  Icon.fillRoundRect(130+1,15,140-4,12,clean_color);
  Icon.fillRoundRect(130+1,275,140-4,12,clean_color);
  Icon.fillRoundRect(130+1,17,30-1,20,clean_color);
  Icon.fillRoundRect(235+1,17,35-1,20,clean_color);
  Icon.fillRoundRect(130+1,264,35-3,17,clean_color);
  Icon.fillRoundRect(237+1,264,34-3,17,clean_color);

  Icon.fill_circle_with_end(200,150,120,3,LCD_3D_Controll_Axis_Screen_color,Icon.Not_mode());
  Icon.fill_circle_with_end(200,150,90,3,LCD_3D_Controll_Axis_Screen_color,Icon.Not_mode());
  Icon.fill_circle_with_end(200,150,60,3,LCD_3D_Controll_Axis_Screen_color,Icon.Not_mode());
  Icon.fill_circle_with_end(200,150,30,3,LCD_3D_Controll_Axis_Screen_color,Icon.Not_mode());

  Display.setColor(Icon.Mode());
  // Display.drawLine(107,78,295,225);

  for (int i = 9; i>=0 ; i--) 
  {
    Display.drawLine(107,78-i,295,225-i);
    Display.drawLine(107,227-i,295,74-i);
  }
  for (int i = 1; i<=9 ; i++) 
  {
    Display.drawLine(107,78+i,295,225+i);
    Display.drawLine(107,227+i,295,74+i);
  }

  Icon.fill_rectangle_with_end(370,20,60,260,2,LCD_3D_Controll_Axis_Screen_color,Icon.Not_mode());
  Display.setColor(Icon.Not_mode());
  Display.fillRect(370,(20)+50,370+60,((20)+50)+3);
  Display.fillRect(370,(20)+80,370+60,((20)+80)+3);
  Display.fillRect(370,(20)+140,370+60,((20)+140)+3);
  Display.fillRect(370,(20)+110,370+60,((50)+110));///
  Display.fillRect(370,(20)+170,370+60,((20)+170)+3);
  Display.fillRect(370,(20)+200,370+60,((20)+200)+3);
  

  Icon.UP_Arrow_Icon(200,50,CYAN);
  Icon.Display_Strings_and_numbers(193,75,BigFont,Icon.Not_mode(),"Y");
  Icon.Display_Strings_and_numbers(193,90,BigFont,Icon.Not_mode(),"+");
   Icon.DOWN_Arrow_Icon(200,200,CYAN);
  Icon.Display_Strings_and_numbers(193,240,BigFont,Icon.Not_mode(),"Y");
  Icon.Display_Strings_and_numbers(193,225,BigFont,Icon.Not_mode(),"-");

  Icon.UP_Arrow_Icon(400,25,GREEN);
  Icon.Display_Strings_and_numbers(393,50,BigFont,Icon.Not_mode(),"Z");
  Icon.Display_Strings_and_numbers(393,65,BigFont,Icon.Not_mode(),"+");
  Icon.DOWN_Arrow_Icon(400,220,GREEN);
  Icon.Display_Strings_and_numbers(393,260,BigFont,Icon.Not_mode(),"Z");
  Icon.Display_Strings_and_numbers(393,245,BigFont,Icon.Not_mode(),"-");
  Icon.LEFT_Arrow_Icon(100,150,YELLOW);
  Icon.Display_Strings_and_numbers(110,159,BigFont,Icon.Not_mode(),"X");
  Icon.Display_Strings_and_numbers(128,159,BigFont,Icon.Not_mode(),"+");
  Icon.RIGHT_Aroow_Icon(250,150,YELLOW);
  Icon.Display_Strings_and_numbers(278,159,BigFont,Icon.Not_mode(),"X");
  Icon.Display_Strings_and_numbers(260,159,BigFont,Icon.Not_mode(),"-");
 
  //Icon.Display_Strings_and_numbers(130,15,SmallFont,MAGENTA,"ُ3D printer controller");
  //Icon.Display_Strings_and_numbers(110,315,SmallFont,MAGENTA,"ُEng.Sedhom => 3D printer controller");

  Display.fillTriangle(100,80,110,70,110,90,Icon.Mode());
  Display.fillTriangle(300,80,290,70,290,88,Icon.Mode());
  Display.fillTriangle(300,80+141,290,70+141,290,88+141,Icon.Mode());
  Display.fillTriangle(100,80+145,110,70+145,110,90+145,Icon.Mode());

  Icon.LEFT_Arrow_Icon(10,150,BLUE);

}
void Switch_screen()
{
    #define x   pixel_x
    #define y   pixel_y

    Icon.New_page_With_App_Bar(true,false);
    Icon.Button_Icon(85,5);
    draw_switch_after_change();
    
    Depart_screen();
}
void Sensor_screen()
{
    Icon.New_page_With_App_Bar(true,false);

    Icon.Sensor_Icon(85,18,YELLOW);
    Icon.label_Icon(130,80,100,40,end_label,sensor_1_name,sensor_1_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());
    Icon.label_Icon(370,80,100,40,end_label,sensor_2_name,sensor_2_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());

    Icon.label_Icon(130,140,100,40,end_label,sensor_3_name,sensor_3_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());
    Icon.label_Icon(370,140,100,40,end_label,sensor_4_name,sensor_4_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());

    Icon.label_Icon(130,200,100,40,end_label,sensor_5_name,sensor_5_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());
    Icon.label_Icon(370,200,100,40,end_label,sensor_6_name,sensor_6_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());

    Icon.label_Icon(130,265,100,40,end_label,sensor_7_name,sensor_7_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());
    Icon.label_Icon(370,265,100,40,end_label,sensor_8_name,sensor_8_state,color_str_in_label_in_sensor_screen,
    TXT_color_in_Sensor_screen,color_label_in_sensor_screen,Icon.Mode());

    Depart_screen();


}
void Slider_screen()
{
    #define slide_size 250
    Icon.New_page_With_App_Bar(true,false);

    Icon.Control_Icon(85,15,BLUE,Icon.Mode());
    

    Icon.slide_Icon(160,85,slide_size,Slider_1_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
    Icon.Display_Strings_and_numbers(20,97,BigFont,TXT_color_in_Slider_screen,Slider_1_name);

    Icon.slide_Icon(160,135,slide_size,Slider_2_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
    Icon.Display_Strings_and_numbers(20,147,BigFont,TXT_color_in_Slider_screen,Slider_2_name);

    Icon.slide_Icon(160,185,slide_size,Slider_3_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
    Icon.Display_Strings_and_numbers(20,197,BigFont,TXT_color_in_Slider_screen,Slider_3_name);

    Icon.slide_Icon(160,235,slide_size,Slider_4_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
    Icon.Display_Strings_and_numbers(20,247,BigFont,TXT_color_in_Slider_screen,Slider_4_name);

     Icon.slide_Icon(160,285,slide_size,Slider_5_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
    Icon.Display_Strings_and_numbers(20,297,BigFont,TXT_color_in_Slider_screen,Slider_5_name);

    Display.drawFastHLine(2,115,476,Icon.Not_mode());
    Display.drawFastHLine(2,165,476,Icon.Not_mode());
    Display.drawFastHLine(2,215,476,Icon.Not_mode());
    Display.drawFastHLine(2,265,476,Icon.Not_mode());

}
void SD_Card_screen()
{
    Icon.New_page_With_App_Bar(true,false);

    Icon.SD_Card_Icon(90,13);
    

    Icon.file_Icon(60,65,file_1_color,file_end_color,file_Background_color,file_1_extend_color,file_1_extend);
    Icon.Display_Strings_and_numbers(5,145,BigFont,TXT_color_in_SD_Card_screen,file_1_name);
 
    Icon.file_Icon(60,150,file_2_color,file_end_color,file_Background_color,file_2_extend_color,file_2_extend);
    Icon.Display_Strings_and_numbers(5,230,BigFont,TXT_color_in_SD_Card_screen,file_2_name);

    Icon.file_Icon(60,235,file_3_color,file_end_color,file_Background_color,file_3_extend_color,file_3_extend);
    Icon.Display_Strings_and_numbers(5,315,BigFont,TXT_color_in_SD_Card_screen,file_3_name);

    Icon.folder_Icon(200,65,folder_1_color);
    Icon.Display_Strings_and_numbers(190,145,BigFont,TXT_color_in_SD_Card_screen,folder_1_name);
    Icon.Setting_Icon(245,103,Icon.Mode(),folder_1_color);//
    Icon.folder_Icon(200,150,folder_2_color);
    Icon.Display_Strings_and_numbers(190,230,BigFont,TXT_color_in_SD_Card_screen,folder_2_name);
    Icon.folder_Icon(200,235,folder_3_color);
    Icon.Display_Strings_and_numbers(190,315,BigFont,TXT_color_in_SD_Card_screen,folder_3_name);
    Icon.folder_Icon(360,65,folder_4_color);
    Icon.Display_Strings_and_numbers(350,145,BigFont,TXT_color_in_SD_Card_screen,folder_4_name);
    Icon.folder_Icon(360,150,folder_5_color);
    Icon.Display_Strings_and_numbers(350,230,BigFont,TXT_color_in_SD_Card_screen,folder_5_name);
    Icon.folder_Icon(360,235,folder_6_color);
    Icon.Display_Strings_and_numbers(350,315,BigFont,TXT_color_in_SD_Card_screen,folder_6_name);



}
void Terminal_screen()
{
    Icon.New_page_With_App_Bar(true,false);

    Icon.Terminal_Icon(83,6);
    terminal_clear();
}
void send_command_to_terminal(word_t Command)
{
    command = Command;
    Terminal_do();
}
void ADD_screen()//
{
    Icon.New_page_With_App_Bar(true,false);

    Icon.Add_Icon(75,15,GREEN);

}
void Setting_screen() 
{
    Icon.New_page_With_App_Bar(true,false);

    Icon.Setting_Icon(120,30,GREEN,Icon.Mode());

    rectangle_in_screen(60,60);

    Icon.WIFI_Icon(60,105,WIFI_Status_no_internet,0x0,RED,Icon.Mode());
    Icon.Bluetooth_Icon(180,80,BLuetooth_Status_open_and_not_connected,BLUE,Icon.Mode());
    Icon.Color_Icon(277,77);
    Icon.Terminal_Icon(35,185);
    Icon.About_Icon(420,210,Icon.Not_mode(),Icon.Mode());
    Icon.Sensor_Icon(403,90,YELLOW);
    Icon.Time_Icon(180,210,MAGENTA,Icon.Mode());
    Icon.Date_Icon(278,185,GREEN,Icon.Mode());

    Display.setFont(BigFont);
    Display.setTextColor(TXT_color_in_setting_screen);
    Display.setCursor(30,160);Display.write("WIFI");
    Display.setCursor(160,160);Display.write("BLE");
    Display.setCursor(260,160);Display.write("Color");
    Display.setCursor(375,160);Display.write("Sensor");

    Display.setCursor(40,270);Display.write("CMD");
    Display.setCursor(150,270);Display.write("TIME");
    Display.setCursor(270,270);Display.write("DATE");
    Display.setCursor(380,270);Display.write("About");
}
/////////////////////////////////////////////////////////////////////////////////////////////////
//windows
void WIFI_Settings_window()
{ 
    // Display.set_Round_Of_Shapes(5);
    #define wifi_color_show  wifi_color_show_wifi_window   //grteen 
    #define wifi_color_dont_show  wifi_color_dont_show_wifi_window //dark 
    #define txt_range_wifi_color  txt_range_wifi_color_wifi_window //white 

    new_window("WIFI Settings");
    
    

    Display.drawFastVLine(380,120,120,Icon.Not_mode());
    if(Is_window_1_or_window_2_wifi_window)
    {
       Display.setColor(color_window_wifi_window);
       Display.fillCircle(400, 190,5);
       Display.setColor(LIGHTGREY);
       Display.fillCircle(400, 170,5);
      
       Display.fillTriangle(390, 150, 400, 130,410,150, GREEN);
       Display.fillTriangle(390, 210, 400, 230,410,210, LIGHTGREY);

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(Icon.Not_mode());
       Display.setCursor(50,120);Display.write("6>");
       Display.setCursor(50,150);Display.write("7>");
       Display.setCursor(50,180);Display.write("8>");
       Display.setCursor(50,210);Display.write("9>");
       Display.setCursor(50,240);Display.write("A>");

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(color_TXT_wifi_window);
       Display.setCursor(80,120);Display.write(WIFI_NAME_6);
       Display.setCursor(80,150);Display.write(WIFI_NAME_7);
       Display.setCursor(80,180);Display.write(WIFI_NAME_8);
       Display.setCursor(80,210);Display.write(WIFI_NAME_9);
       Display.setCursor(80,240);Display.write(WIFI_NAME_A);

       Display.setFont(BigFont);Display.setTextColor(txt_range_wifi_color_wifi_window);
       char range_6_as_str[11];
       char range_7_as_str[11];
       char range_8_as_str[11];
       char range_9_as_str[11];
       char range_A_as_str[11];
       sprintf(range_6_as_str, "%d", Range_wifi_6);
       sprintf(range_7_as_str, "%d", Range_wifi_7);
       sprintf(range_8_as_str, "%d", Range_wifi_8);
       sprintf(range_9_as_str, "%d", Range_wifi_9);
       sprintf(range_A_as_str, "%d", Range_wifi_A);
       Icon.WIFI_Icon(310,120,Range_wifi_draw_6,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,150,Range_wifi_draw_7,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,180,Range_wifi_draw_8,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,210,Range_wifi_draw_9,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,240,Range_wifi_draw_A,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Display.setFont(BigFont);Display.setTextColor(txt_range_wifi_color_wifi_window);
       Display.setCursor(330,120);Display.write(range_6_as_str);Display.write("%");
       Display.setCursor(330,150);Display.write(range_7_as_str);Display.write("%");
       Display.setCursor(330,180);Display.write(range_8_as_str);Display.write("%");
       Display.setCursor(330,210);Display.write(range_9_as_str);Display.write("%");
       Display.setCursor(330,240);Display.write(range_A_as_str);Display.write("%");

    }
    else
    {
       Display.setColor(color_window_wifi_window);
       Display.fillCircle(400, 170,5);
       Display.setColor(LIGHTGREY);
       Display.fillCircle(400, 190,5);

       Display.fillTriangle(390, 150, 400, 130,410,150, LIGHTGREY);
       Display.fillTriangle(390, 210, 400, 230,410,210, GREEN);

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(Icon.Not_mode());
       Display.setCursor(50,120);Display.write("1>");
       Display.setCursor(50,150);Display.write("2>");
       Display.setCursor(50,180);Display.write("3>");
       Display.setCursor(50,210);Display.write("4>");
       Display.setCursor(50,240);Display.write("5>");

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(color_TXT_wifi_window);
       Display.setCursor(80,120);Display.write(WIFI_NAME_1);
       Display.setCursor(80,150);Display.write(WIFI_NAME_2);
       Display.setCursor(80,180);Display.write(WIFI_NAME_3);
       Display.setCursor(80,210);Display.write(WIFI_NAME_4);
       Display.setCursor(80,240);Display.write(WIFI_NAME_5);

       
       char range_1_as_str[11];
       char range_2_as_str[11];
       char range_3_as_str[11];
       char range_4_as_str[11];
       char range_5_as_str[11];
       sprintf(range_1_as_str, "%d", Range_wifi_1);
       sprintf(range_2_as_str, "%d", Range_wifi_2);
       sprintf(range_3_as_str, "%d", Range_wifi_3);
       sprintf(range_4_as_str, "%d", Range_wifi_4);
       sprintf(range_5_as_str, "%d", Range_wifi_5);
       Icon.WIFI_Icon(310,120,Range_wifi_draw_1,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,150,Range_wifi_draw_2,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,180,Range_wifi_draw_3,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,210,Range_wifi_draw_4,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Icon.WIFI_Icon(310,240,Range_wifi_draw_5,wifi_color_show,wifi_color_dont_show,Icon.Mode());
       Display.setFont(BigFont);Display.setTextColor(txt_range_wifi_color_wifi_window);
       Display.setCursor(330,120);Display.write(range_1_as_str);Display.write("%");
       Display.setCursor(330,150);Display.write(range_2_as_str);Display.write("%");
       Display.setCursor(330,180);Display.write(range_3_as_str);Display.write("%");
       Display.setCursor(330,210);Display.write(range_4_as_str);Display.write("%");
       Display.setCursor(330,240);Display.write(range_5_as_str);Display.write("%");
    }
    Display.set_Round_Of_Shapes(10);
    Display.setColor(color_window_wifi_window);
    Display.fillRoundRect(50, 250,150, 290);
    Display.fillRoundRect(180, 250,280, 290);
    Display.fillRoundRect(310, 250,410, 290);

    Display.setCursor(70,275);Display.setTextSize(8);Display.setFont(BigFont);
    Display.setTextColor(Icon.Not_mode());Display.write("Scan");

    Display.setCursor(210,277);Display.setTextSize(8);Display.setFont(BigFont);
    Display.setTextColor(Icon.Not_mode());Display.write("Add");

    Display.setCursor(330,275);Display.setTextSize(8);Display.setFont(BigFont);
    Display.setTextColor(Icon.Not_mode());Display.write("Save");
}
void Add_new_WIFI_Window()
{
    Icon.Add_new_WIFI_window(Add_new_WIFI_Window_color,add_new_wifi_SSID, add_new_wifi_Password);
}
void BLE_Settings_window()
{
    #define wifi_color_show  GREEN 
    #define wifi_color_dont_show  DARKGREY 
    #define txt_rangr_wifi_color  WHITE 

    new_window("BLE Settings");
    
    

    Display.drawFastVLine(380,120,120,Icon.Not_mode());
    if(Is_window_1_or_window_2_BLE_window)
    {
       Display.setColor(color_window_BLE_window);
       Display.fillCircle(400, 190,5);
       Display.setColor(LIGHTGREY);
       Display.fillCircle(400, 170,5);
      
       Display.fillTriangle(390, 150, 400, 130,410,150, GREEN);
       Display.fillTriangle(390, 210, 400, 230,410,210, LIGHTGREY);

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(Icon.Not_mode());
       Display.setCursor(50,120);Display.write("6>");
       Display.setCursor(50,150);Display.write("7>");
       Display.setCursor(50,180);Display.write("8>");
       Display.setCursor(50,210);Display.write("9>");
       Display.setCursor(50,240);Display.write("A>");

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(color_TXT_BLE_window);
       Display.setCursor(80,120);Display.write(BLE_NAME_6);
       Display.setCursor(80,150);Display.write(BLE_NAME_7);
       Display.setCursor(80,180);Display.write(BLE_NAME_8);
       Display.setCursor(80,210);Display.write(BLE_NAME_9);
       Display.setCursor(80,240);Display.write(BLE_NAME_A);

    }
    else
    {
       Display.setColor(color_window_BLE_window);
       Display.fillCircle(400, 170,5);
       Display.setColor(LIGHTGREY);
       Display.fillCircle(400, 190,5);

       Display.fillTriangle(390, 150, 400, 130,410,150, LIGHTGREY);
       Display.fillTriangle(390, 210, 400, 230,410,210, GREEN);

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(Icon.Not_mode());
       Display.setCursor(50,120);Display.write("1>");
       Display.setCursor(50,150);Display.write("2>");
       Display.setCursor(50,180);Display.write("3>");
       Display.setCursor(50,210);Display.write("4>");
       Display.setCursor(50,240);Display.write("5>");

       Display.setTextSize(8);Display.setFont(BigFont);
       Display.setTextColor(color_TXT_BLE_window);
       Display.setCursor(80,120);Display.write(BLE_NAME_1);
       Display.setCursor(80,150);Display.write(BLE_NAME_2);
       Display.setCursor(80,180);Display.write(BLE_NAME_3);
       Display.setCursor(80,210);Display.write(BLE_NAME_4);
       Display.setCursor(80,240);Display.write(BLE_NAME_5);

    }
    Display.setColor(color_window_BLE_window);
    Display.fillRoundRect(50, 250,150, 290);
    Display.fillRoundRect(180, 250,280, 290);
    Display.fillRoundRect(310, 250,410, 290);

    Display.setCursor(70,275);Display.setTextSize(8);Display.setFont(BigFont);
    Display.setTextColor(Icon.Not_mode());Display.write("Scan");

    Display.setCursor(210,277);Display.setTextSize(8);Display.setFont(BigFont);
    Display.setTextColor(Icon.Not_mode());Display.write("Add");

    Display.setCursor(330,275);Display.setTextSize(8);Display.setFont(BigFont);
    Display.setTextColor(Icon.Not_mode());Display.write("Save");
}
void color_setting_Window()
{
    new_window("Color Setting");
    Icon.fillRoundRect(70,120,60,60,RED);
    Icon.fillRoundRect(70+80,120,60,60,GREEN);
    Icon.fillRoundRect(70+160,120,60,60,BLUE);
    Icon.fillRoundRect(70+240,120,60,60,YELLOW);
    Icon.fillRoundRect(70,220,60,60,CYAN);
    Icon.fillRoundRect(70+80,220,60,60,MAGENTA);
    Icon.fillRoundRect(70+160,220,60,60,DARKGREY);
    Icon.fillRoundRect(70+240,220,60,60,Icon.Not_mode());
}
void Full_KeyBoard_window()
{
    Icon.clear_All_Display();
    Icon.Back_Arrow_Icon(20,30,RED);
    word_t key_board_char_1_S[] = {"q","w","e","r","t","y","u","i","o","p"};
    word_t key_board_char_2_S[] = {"a","s","d","f","g","h","j","k","l"};
    word_t key_board_char_3_S[] = {"z","x","c","v","b","n","m"};

    word_t key_board_char_1_C[] = {"Q","W","E","R","T","Y","U","I","O","P"};
    word_t key_board_char_2_C[] = {"A","S","D","F","G","H","J","K","L"};
    word_t key_board_char_3_C[] = {"Z","X","C","V","B","N","M"};

    word_t key_board_special_char_1[] = {"!","@","#","$","%","^","&","*","(",")"};
    word_t key_board_special_char_2[] = {"`","~","-","_","=","+","[","]","{","}"};
    word_t key_board_special_char_3[] = {"\\","|",":",";","\"","\'",",",".","/"};
    word_t key_board_special_char_4[] = {"<",">","?"};

    Icon.BOX_and_TXT_Icon(100,10,360,40,Full_KeyBoard_window_user_input_BOX_color,BigFont
                                ,Full_KeyBoard_window_user_input_TXT_color,Full_KeyBoard_window_user_input_TXT);
   if(special_char)
   {
        for(int i = 0; i<=9 ;i++)
        {
            Icon.BOX_and_TXT_Icon(11+(46*i),70,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_special_char_1[i]); 
            Icon.BOX_and_TXT_Icon(11+(46*i),116,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_special_char_2[i]);
            if(i==9)break; 
            Icon.BOX_and_TXT_Icon(11+(46*i),162,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_special_char_3[i]);  
        }   
        for(int i = 0; i<=2 ;i++)
        {
            Icon.BOX_and_TXT_Icon(149+(46*i),208,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_special_char_4[i]);    
        }
   }
   else if(caps_lock && !special_char)
   {
            for(int i = 0; i<=9 ;i++)
        {;
            Icon.BOX_and_TXT_Icon(11+(46*i),70,40,40,Full_KeyBoard_window_color,BigFont
            ,Full_KeyBoard_window_TXT_color,key_board_special_char_1[i]);
            Icon.BOX_and_TXT_Icon(11+(46*i),116,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_char_1_C[i]);     
        }
        for(int i = 0; i<=8 ;i++)
        {
            Icon.BOX_and_TXT_Icon(11+(46*i),162,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_char_2_C[i]);    
        }
        for(int i = 0; i<=6 ;i++)
        {
            Icon.BOX_and_TXT_Icon(57+(46*i),208,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_char_3_C[i]);    
        }
   }
   else if(!caps_lock && !special_char)
   {
       for(int i = 0; i<=9 ;i++)
        {
            char c[3];
            sprintf(c,"%d",i);
            Icon.BOX_and_TXT_Icon(11+(46*i),70,40,40,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color,c);
            Icon.BOX_and_TXT_Icon(11+(46*i),116,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_char_1_S[i]);     
        }
        for(int i = 0; i<=8 ;i++)
        {
            Icon.BOX_and_TXT_Icon(11+(46*i),162,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_char_2_S[i]);    
        }
        for(int i = 0; i<=6 ;i++)
        {
            Icon.BOX_and_TXT_Icon(57+(46*i),208,40,40,Full_KeyBoard_window_color,BigFont
                                        ,Full_KeyBoard_window_TXT_color,key_board_char_3_S[i]);    
        }
   }
   Icon.BOX_and_TXT_Icon(104,255,85,40,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color," $%");//11
   Icon.BOX_and_TXT_Icon(195,255,130,40,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color," Space");//104
   Icon.BOX_and_TXT_Icon(11,209,40,51,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color,"");
   Icon.BOX_and_TXT_Icon(11,255,85,40,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color,"Caps");//241
   Icon.BOX_and_TXT_Icon(332,255,130,40,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color," Done"); 
   Icon.BOX_and_TXT_Icon(424,163,40,51,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color,"");
   Icon.BOX_and_TXT_Icon(378,209,86,40,Full_KeyBoard_window_color,BigFont,Full_KeyBoard_window_TXT_color," <-");                               
}
void Numeric_KeyBoard_window() 
{
    Icon.clear_All_Display();
    Icon.Back_Arrow_Icon(20,30,RED);
    Icon.BOX_and_TXT_Icon(100,10,360,40,Full_KeyBoard_window_user_input_BOX_color,BigFont
                                ,Full_KeyBoard_window_user_input_TXT_color,Numeric_KeyBoard_window_user_input_num);

    Icon.BOX_and_TXT_seven_segment_Icon(15,66,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"7");
    Icon.BOX_and_TXT_seven_segment_Icon(105,66,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"8");
    Icon.BOX_and_TXT_seven_segment_Icon(194,66,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"9");
    Icon.BOX_and_TXT_seven_segment_Icon(283,66,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,".");
    Icon.BOX_and_TXT_seven_segment_Icon(372,66,70,90,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"");

    Icon.BOX_and_TXT_seven_segment_Icon(15,150,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"4");
    Icon.BOX_and_TXT_seven_segment_Icon(105,150,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"5");
    Icon.BOX_and_TXT_seven_segment_Icon(194,150,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"6");
    Icon.BOX_and_TXT_seven_segment_Icon(283,150,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"0");
    Icon.BOX_and_TXT_seven_segment_Icon(372,150,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"");                                                

    Icon.BOX_and_TXT_seven_segment_Icon(15,234,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"1");
    Icon.BOX_and_TXT_seven_segment_Icon(105,234,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"2");
    Icon.BOX_and_TXT_seven_segment_Icon(194,234,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"3");
    Icon.BOX_and_TXT_seven_segment_Icon(283,234,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,".");  
    Icon.BOX_and_TXT_seven_segment_Icon(372,234,70,60,Numeric_KeyBoard_window_color,SevenSegNumFont,
                                                 Numeric_KeyBoard_window_TXT_color,"");   
    Icon.Display_Strings_and_numbers(310,100,BigFont,Numeric_KeyBoard_window_TXT_color,"_");                                          
    Icon.fill_Circle(318,265,4,Numeric_KeyBoard_window_TXT_color);                                         
    Icon.Display_Strings_and_numbers(390,150,BigFont,Numeric_KeyBoard_window_TXT_color,"<-");                                          
    Icon.Display_Strings_and_numbers(375,270,BigFont,Numeric_KeyBoard_window_TXT_color,"Done");                                          
}
void Time_setting_window()
{
    new_window("Time Setting");
    // Icon.Time_Icon(70,100,MAGENTA,Icon.Mode());
    set_number(240,130,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,Hour);
    set_number(240,240,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,min);
    Icon.Display_Strings_and_numbers(75,155,BigFont,TXT_color_in_time_window,"Hour  -> ");
    Icon.Display_Strings_and_numbers(60,265,BigFont,TXT_color_in_time_window,"Minute -> ");

}
void Date_setting_window()
{
    new_window("Date Setting");
    set_number(250,210,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,month);
    set_number(50,210,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,day);
    set_number_with_resize_box(110,115,150,70,color_inc,color_dec,box_inc_color,box_dec_color,box_num_color,color_num,year);
    Icon.Display_Strings_and_numbers(195,185,BigFont,TXT_color_in_Date_window,"Year");
    Icon.Display_Strings_and_numbers(108,280,BigFont,TXT_color_in_Date_window,"Day");
    Icon.Display_Strings_and_numbers(297,280,BigFont,TXT_color_in_Date_window,"Month");
}
void warning_window()
{
   Icon.fill_rectangle_with_end(100,100,250,150,4,warning_box_color,warning_box_end_color); 
   Icon.fill_rectangle_with_end(310,100,40,40,4,RED,warning_box_end_color);
   Icon.Display_Strings_and_numbers(323,130,BigFont,Icon.Not_mode(),"X");
   Icon.Display_Strings_and_numbers(120,130,BigFont,WHITE,warning_msg_Title);
   Icon.Display_Strings_and_numbers(105,160,BigFont,warning_TXT_msg_color,warning_msg_line_1);
   Icon.Display_Strings_and_numbers(105,180,BigFont,warning_TXT_msg_color,warning_msg_line_2);
   Icon.Display_Strings_and_numbers(105,200,BigFont,warning_TXT_msg_color,warning_msg_line_3);
   Icon.Display_Strings_and_numbers(105,220,BigFont,warning_TXT_msg_color,warning_msg_line_4);
   Icon.Display_Strings_and_numbers(105,240,BigFont,warning_TXT_msg_color,warning_msg_line_5);
}
void Timer_clock_screen()
{
    Icon.New_page_With_App_Bar(true,false);

    Icon.Time_Icon(105,30,GREEN,Icon.Mode());
    Icon.Display_Strings_and_numbers(5,100,BigFont,TXT_color_in_Timer_clock_screen,"DATE->");
    Icon.Display_Strings_and_numbers(160,150,BigFont,TXT_color_in_Timer_clock_screen,"Month");
    Icon.Display_Strings_and_numbers(360,150,BigFont,TXT_color_in_Timer_clock_screen,"Day");
    ////////////////////////////////////////////////////////////////////////////
    Display.drawFastHLine(2,152,477,Icon.Not_mode());
    /////////////    set Time
    Icon.Display_Strings_and_numbers(5,205,BigFont,TXT_color_in_Timer_clock_screen,"TIME->");
    Icon.Display_Strings_and_numbers(170,248,BigFont,TXT_color_in_Timer_clock_screen,"Hour");
    Icon.Display_Strings_and_numbers(340,248,BigFont,TXT_color_in_Timer_clock_screen,"Minute");
    Icon.Display_Strings_and_numbers(245,318,BigFont,TXT_color_in_Timer_clock_screen,"Second");
    Icon.BOX_with_end_and_TXT_Icon(410,255,50,50,box_num_color,BigFont,color_num,3,Icon.Not_mode(),"");
    Icon.BOX_with_end_and_TXT_Icon(5,235,160,80,box_num_color,BigFont,color_num,3,Icon.Not_mode(),"");
    Icon.Display_Strings_and_numbers(12,258,BigFont,TXT_color_in_Timer_clock_screen,"Set Clock");
    Icon.Switch_Icon(50,265,Switch_on_color,Switch_off_color,Switch_Timer_clock);
    draw_timer_screen();
}
//touch
word_t Full_KeyBoard_window_touch() 
{
    word_t key_board_char_1_S[] = {"q","w","e","r","t","y","u","i","o","p"};
    word_t key_board_char_2_S[] = {"a","s","d","f","g","h","j","k","l"};
    word_t key_board_char_3_S[] = {"z","x","c","v","b","n","m"};

    word_t key_board_char_1_C[] = {"Q","W","E","R","T","Y","U","I","O","P"};
    word_t key_board_char_2_C[] = {"A","S","D","F","G","H","J","K","L"};
    word_t key_board_char_3_C[] = {"Z","X","C","V","B","N","M"};

    word_t key_board_special_char_1[] = {"!","@","#","$","%","^","&","*","(",")"};
    word_t key_board_special_char_2[] = {"`","~","-","_","=","+","[","]","{","}"};
    word_t key_board_special_char_3[] = {"\\","|",":",";","\"","\'",",",".","/"};
    word_t key_board_special_char_4[] = {"<",">","?"};
    static String temp = "";


    if (!caps_lock && !special_char)
    {
        if (pixel_y > 70 && pixel_y < 70+40) 
        {
            for (byte_t i = 0; i <= 9; i++)
            {
                char c[3];
                sprintf(c, "%d", i);
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += c;}
            }

        }
        if (pixel_y > 116 && pixel_y < 116+40) 
        {
            for (byte_t i = 0; i <= 9; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_char_1_S[i];}
            } 
        }
        if (pixel_y > 162 && pixel_y < 162+40) 
        {
            for (byte_t i = 0; i <= 8; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_char_2_S[i];}
            } 
        }    
        if (pixel_y > 208 && pixel_y < 208+40) 
        {
            for (byte_t i = 1; i <= 7; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_char_3_S[i-1];}
            } 
        }
    }
    if (caps_lock && !special_char)
    {
        if (pixel_y > 70 && pixel_y < 70+40) 
        {
            for (byte_t i = 0; i <= 9; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_special_char_1[i];}
            }

        }
        if (pixel_y > 116 && pixel_y < 116+40) 
        {
            for (byte_t i = 0; i <= 9; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_char_1_C[i];}
            } 
        }
        if (pixel_y > 162 && pixel_y < 162+40) 
        {
            for (byte_t i = 0; i <= 8; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_char_2_C[i];}
            } 
        }    
        if (pixel_y > 208 && pixel_y < 208+40) 
        {
            for (byte_t i = 1; i <= 7; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_char_3_C[i-1];}
            } 
        }
    }
    if(special_char)
    {
        if (pixel_y > 70 && pixel_y < 70+40) 
        {
            for (byte_t i = 0; i <= 9; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_special_char_1[i];}
            }

        }
        if (pixel_y > 116 && pixel_y < 116+40) 
        {
            for (byte_t i = 0; i <= 9; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_special_char_2[i];}
            } 
        }
        if (pixel_y > 162 && pixel_y < 162+40) 
        {
            for (byte_t i = 0; i <= 8; i++)
            {
                if (pixel_x > 11+(46*i) && pixel_x < (11+(46*i)) +40){temp += key_board_special_char_3[i];}
            } 
        }    
        if (pixel_y > 208 && pixel_y < 208+40) 
        {
            for (byte_t i = 0; i <= 2; i++)
            {
                if (pixel_x > 149+(46*i) && pixel_x < (149+(46*i)) +40){temp += key_board_special_char_4[i];}
            } 
        }
    }  
    if (pixel_y > 255 && pixel_y < 255+40) 
    {
        if (pixel_x > 104 && pixel_x < 104+85){special_char = !special_char; char v[23];temp.toCharArray(v,23);Full_KeyBoard_window_user_input_TXT = v; Full_KeyBoard_window(); return "";}//$%
        if (pixel_x > 195 && pixel_x < 195+130){temp += " ";}//space
        if (pixel_x > 332 && pixel_x < 332+130){ char v[23];temp.toCharArray(v,23);Full_KeyBoard_window_user_input_TXT = v; return "Done";}//done
        if (pixel_x > 11 && pixel_x < 11+85){caps_lock = !caps_lock;  char v[23];temp.toCharArray(v,23);Full_KeyBoard_window_user_input_TXT = v; Full_KeyBoard_window(); return "";}//caps
    }
    if (pixel_y > 209 && pixel_y < 209+51) 
    {
        if (pixel_x > 378 && pixel_x < 378+90){ if(temp.length()>0) temp.remove(temp.length() - 1);}//backspace
    }
    
        
        
    char c [22]={0};   
    temp.toCharArray(c,22);
    // Full_KeyBoard_window_user_input_TXT = c;
    Icon.BOX_and_TXT_Icon(100,10,360,40,Full_KeyBoard_window_user_input_BOX_color,BigFont
                                ,Full_KeyBoard_window_user_input_TXT_color,c); 
    delay(250); 

    
}
void Switch_screen_touch()
{
    #define x  pixel_x
    #define y  pixel_y
    // العمود الأول (X من 150 لـ 250 تقريبًا)
    if(x > 150 && x < 250) {
        if(y > 80 && y < 120) { Switch_1_state = !Switch_1_state; draw_switch_after_change(); }
        else if(y > 140 && y < 180) { Switch_3_state = !Switch_3_state; draw_switch_after_change(); }
        else if(y > 200 && y < 240) { Switch_5_state = !Switch_5_state; draw_switch_after_change(); }
        else if(y > 260 && y < 300) { Switch_7_state = !Switch_7_state; draw_switch_after_change(); }
    }

    // العمود الثاني (X من 380 لـ 480 تقريبًا)
    if(x > 380 && x < 480) {
        if(y > 80 && y < 120) { Switch_2_state = !Switch_2_state; draw_switch_after_change(); }
        else if(y > 140 && y < 180) { Switch_4_state = !Switch_4_state; draw_switch_after_change(); }
        else if(y > 200 && y < 240) { Switch_6_state = !Switch_6_state; draw_switch_after_change(); }
        else if(y > 260 && y < 300) { Switch_8_state = !Switch_8_state; draw_switch_after_change(); }
    }
}
void timer_screen_touch()
{
    // month
   set_touch_nmber(120,82,&Timer_clock_month);
    // day
   set_touch_nmber(300,82,&Timer_clock_day);
   // hour
   set_touch_nmber(120,180,&Timer_clock_hour);
   // min
   set_touch_nmber(300,180,&Timer_clock_min);
   // sec
   set_touch_nmber(210,250,&Timer_clock_sec);
   // time name
    if(pixel_x > 410 && pixel_x <410+50)
    {if(pixel_y > 255 && pixel_y <255+50){ 
        Icon.BOX_with_end_and_TXT_Icon(410,255,50,50,box_num_color,BigFont,color_num,3,Icon.Not_mode(),"");
        Timer_clock_time_name = ((Timer_clock_time_name == "AM")?"PM":"AM");
        Display.setCursor(410+8,255+35);
        Display.write(Timer_clock_time_name);
    }}

    if(pixel_x > 40 && pixel_x < 50+100) {
    if(pixel_y > 255 && pixel_y < 265+60) { Switch_Timer_clock = !Switch_Timer_clock; draw_timer_screen(); }}


    if(Switch_Timer_clock && Timer_clock_month == month && Timer_clock_day == day && Timer_clock_hour == Hour
       && Timer_clock_min == min && Timer_clock_sec == sec && Timer_clock_time_name == time_name )
    {
        Timer_clock_is_on = ON ;
    }
    else
    {
        Timer_clock_is_on = OFF ;
    }

    if(Timer_clock_is_on)
    {
        char time_now[20] ={0};
        char date_now[20] ={0};
        char time_now_h[3]={0};
        char time_now_m[3]={0};
        char time_now_s[3]={0};
        char date_now_y[5]={0};
        char date_now_m[3]={0};
        char date_now_d[3]={0};
        sprintf(time_now_h,"%d",Hour);
        sprintf(time_now_m,"%d",min);
        sprintf(time_now_s,"%d",sec);
        sprintf(date_now_y,"%d",year);
        sprintf(date_now_m,"%d",month);
        sprintf(date_now_d,"%d",day);
        // concat time
        strcat(time_now,">> ");
        strcat(time_now,time_now_h);
        strcat(time_now,":");
        strcat(time_now,time_now_m);
        strcat(time_now,":");
        strcat(time_now,time_now_s);
        strcat(time_now," ");
        strcat(time_now,time_name);
        // concat time
        strcat(date_now,">> ");
        strcat(date_now,date_now_y);
        strcat(date_now,"/");
        strcat(date_now,date_now_m);
        strcat(date_now,"/");
        strcat(date_now,date_now_d);
        //print msg
        warning_msg_Title  = "Timer Clock" ;
        warning_msg_line_1 = " you set timer" ;
        warning_msg_line_2 = "     Befor." ;
        warning_msg_line_3 = date_now ;
        warning_msg_line_4 = time_now ;
        warning_msg_line_5 = "  now is Time." ;
        warning_TXT_msg_color = GREEN ;
        warning_window();
       if(pixel_x > 310 && pixel_x < 310+40) {
       if(pixel_y > 100 && pixel_y < 100+40) {Switch_Timer_clock = OFF;Icon.clear_All_Display(0); Timer_clock_screen(); }}
    }
    // 310,100,40,40
}
void slider_screen_touch()
{
    if(pixel_x >= 130 && pixel_x <= 120+320)
    {
        if(pixel_y > 85 && pixel_y < 85+10) 
        {
             Icon.fillRoundRect(145,80,275,20,Icon.Mode());
             Slider_1_Range = constrain(map(pixel_x,130,130+300,0,100),0,100);
              Icon.slide_Icon(160,85,250,Slider_1_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
        }
        if(pixel_y > 135 && pixel_y < 135+10) 
        {
             Icon.fillRoundRect(145,130,275,20,Icon.Mode());
             Slider_1_Range = constrain(map(pixel_x,130,130+300,0,100),0,100);
              Icon.slide_Icon(160,135,250,Slider_1_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
        }
        if(pixel_y > 185 && pixel_y < 185+10) 
        {
             Icon.fillRoundRect(145,180,275,20,Icon.Mode());
             Slider_1_Range = constrain(map(pixel_x,130,130+300,0,100),0,100);
              Icon.slide_Icon(160,185,250,Slider_1_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
        }
        if(pixel_y > 235 && pixel_y < 235+10) 
        {
             Icon.fillRoundRect(145,230,275,20,Icon.Mode());
             Slider_1_Range = constrain(map(pixel_x,130,130+300,0,100),0,100);
              Icon.slide_Icon(160,235,250,Slider_1_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
        }
        if(pixel_y > 285 && pixel_y < 285+13) 
        {
             Icon.fillRoundRect(145,280,275,20,Icon.Mode());
             Slider_1_Range = constrain(map(pixel_x,130,130+300,0,100),0,100);
              Icon.slide_Icon(160,285,250,Slider_1_Range,slide_active_color,slide_not_active_color,
                     slide_ball_color,slider_box_color,slider_Range_in_box_color);
        }
    }

}
word_t Numeric_KeyBoard_window_touch()
{
   static String num = "";

    if(pixel_x >= 15 && pixel_x <= 15+70)//15,66,70,60,
    {
        if(pixel_y > 66 && pixel_y < 66+60)   {num += '7'; }
        if(pixel_y > 150 && pixel_y < 150+60) {num += '4'; }
        if(pixel_y > 234 && pixel_y < 234+60) {num += '1'; }
    }
    if(pixel_x >= 105 && pixel_x <= 105+70)//15,66,70,60,
    {
        if(pixel_y > 66 && pixel_y < 66+60)   {num += '8'; }
        if(pixel_y > 150 && pixel_y < 150+60) {num += '5'; }
        if(pixel_y > 234 && pixel_y < 234+60) {num += '2'; }
    }
    if(pixel_x >= 194 && pixel_x <= 194+70)//15,66,70,60,
    {
        if(pixel_y > 66 && pixel_y < 66+60)   {num += '9'; }
        if(pixel_y > 150 && pixel_y < 150+60) {num += '6'; }
        if(pixel_y > 234 && pixel_y < 234+60) {num += '3'; }
    }
    if(pixel_x >= 283  && pixel_x <= 283+70)//15,66,70,60,
    {
        if(pixel_y > 66 && pixel_y < 66+60)   {num += '-'; }
        if(pixel_y > 150 && pixel_y < 150+60) {num += '0'; }
        if(pixel_y > 234 && pixel_y < 234+60) {num += '.'; }
    }
    if(pixel_x >= 372  && pixel_x <= 372+70)//15,66,70,60,
    {
        if(pixel_y > 66 && pixel_y < 66+140)   
        {
            // char return_back [11]; 
            // num.toCharArray(return_back,11);
            // num =""; 
             if(num.length()>0) num.remove(num.length() - 1);
        }
        if(pixel_y > 234 && pixel_y < 234+60) 
        {
            char final_num[22];
            num.toCharArray(final_num,22);
            Numeric_KeyBoard_window_user_input_num = final_num;
            return"Done"; 
        }
    }
    char c[22];
    num.toCharArray(c,22);
    Icon.BOX_and_TXT_Icon(100,10,360,40,Full_KeyBoard_window_user_input_BOX_color,BigFont
                                ,Full_KeyBoard_window_user_input_TXT_color,c);
    delay(250);
    return "else";
}
// others
void Clear_Display()
{
    Icon.clear_All_Display();
}










