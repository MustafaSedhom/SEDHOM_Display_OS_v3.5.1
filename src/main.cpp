///////////// include my librarys 
#include <Arduino.h>
#include "SEDHOM_Display_OS/SEDHOM_Display_OS.h"
///////////// object from SEDHOM Icon you can use " Icon " only without define any object
// becuse in windos and screen folders I define Icon object you can use it
// SEDHOM_OS_Icons_t Icon_TFT;
////////////// my pages name /////////////////////////////
void Home_page();
void Button_page();
void SD_Card_page();
void Settings_page();
////////////// input pages name to list to handling scrolling betwwen all pages
list_of_pages = { Home_page, Button_page, SD_Card_page ,Settings_page };
////////////////////////////////////////////////////////////////////////////////
void setup()
{
    /////////////////////////////////////////////////////////////////////////////
    // start communcation with UART ptotocol
    // SEDHOM_OS_Device_Start_Comunication();
    ////////////////////////////////////////////////////////////////////////////
    // init Rotation of Display and set mode of Display
    init_Rotation_and_mode(Horizontal,Night_Mode);   
    ////////////////////////////////////////////////////////////////////////////
    // setting some variables
    Hour = 5;
    min = 32;
    sec = 21;
    time_name ="PM";
    Battary_Value = 23;
    ////////////////////////////////////////////////////////////////////////////
    // handling all pages
    SEDHOM_OS_handlig_pages();

}
////////////////////////////////////////////////////////////////////////////////
void loop()
{
    if(Is_Touch_Presssed()) // if any clicked in screen
    {
        if(pixel_x >= 400 && pixel_y >=280) // if next arrow clicked
        {
            add_page();
        }
        if(pixel_x <= 40 && pixel_y <=50) // if back arrow clicked
        {
            remove_page();
        }
    }
}
////////////////////////////////////////////////////////////////////////////////
void Home_page()
{
    //////// Draw fram and appBar //////////////////////
    Icon.clear_All_Display(false);
    Icon.New_page_With_App_Bar(false,true);
    //////// Draw your page icon here ///////////////////
    Icon.Home_Icon(70,10,CYAN,Icon.Mode());
    //////// Draw your pages here ///////////////////////
    Icon.After_Arrow_Icon(410,290,BLUE);
    Icon.Text(15,100,BigFont,GREEN,"SEDHOM Device OS welcome you");
    Icon.Text(80,130,BigFont,BLUE,"Eng.Mustafa Sedhom");
    Icon.Text(165,230,BigFont,RED,"Home page");
    Icon.Text(300,300,BigFont,MAGENTA,"page 1");
    Icon.Home_Icon(200,150,YELLOW,Icon.Mode());
}
void Button_page()
{
    //////// Draw fram and appBar //////////////////////
    Icon.clear_All_Display(false);
    Icon.New_page(true,false,false);
    //////// Draw your page icon here ///////////////////
    Icon.Button_Icon(85,5);
    //////// Draw your pages here ///////////////////////
    Icon.After_Arrow_Icon(410,290,BLUE);
    Icon.Text(145,230,BigFont,RED,"Button page");
    Icon.Text(300,300,BigFont,MAGENTA,"page 2");
    Icon.Button_Icon(205,140);
}
void SD_Card_page()
{
    //////// Draw fram and appBar //////////////////////
    Icon.clear_All_Display(false);
    Icon.New_page(false,false,true);
    //////// Draw your page icon here ///////////////////
    Icon.SD_Card_Icon(90,11);
    //////// Draw your pages here ///////////////////////
    Icon.After_Arrow_Icon(410,290,BLUE);
    Icon.Text(140,230,BigFont,RED,"SD Card page");
    Icon.Text(300,300,BigFont,MAGENTA,"page 3");
    Icon.SD_Card_Icon(210,140);
}
void Settings_page()
{
    //////// Draw fram and appBar //////////////////////
    Icon.clear_All_Display(0);
    Icon.New_page(false,false,true);
    //////// Draw your page icon here ///////////////////
    Icon.Setting_Icon(120,30,GREEN,Icon.Mode());
    //////// Draw your pages here ///////////////////////
    Icon.Text(130,230,BigFont,RED,"Settings page");
    Icon.Text(370,300,BigFont,MAGENTA,"page 4");
    Icon.Setting_Icon(235,160,BLUE,Icon.Mode());
}