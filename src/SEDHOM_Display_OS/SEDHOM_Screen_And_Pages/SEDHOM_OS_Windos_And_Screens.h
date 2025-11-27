#ifndef SCREENS_H
#define SCREENS_H

#include "../SEDHOM_Data_Types/SEDHOM_OS_data_type.h"
#include "../SEDHOM_OS_Settings/SEDHOM_OS_variable_for_system.h"
#include "../SEDHOM_Icons_Widgets/SEDHOM_OS_Icons_And_Widgets.h"
#include "../SEDHOM_Touch/SEDHOM_Display_Touch.h"

#define SEDHOM_OS_Icons_t      Icons_t
#define SEDHOM_OS_Icon         Icon
#define SEDHOM_OS_Display_t    UTFTGLUE
#define SEDHOM_OS_Display      Display

extern Icons_t Icon ;

void init_Rotation_and_mode(int Rotation = Horizontal , Color_t Mode = Night_Mode);
void APP_Bar_And_Big_Window();
void send_command_to_terminal(word_t Command);
void Setting_screen();
void main_Screen();
void WIFI_Settings_window();
void start_screen();
void lock_screen();
void color_setting_Window();
void LCD_3D_Controll_Axis_Screen();
void BLE_Settings_window();
void Add_new_WIFI_Window();
void Switch_screen();
void Sensor_screen();
void Slider_screen();
void SD_Card_screen();
void Terminal_screen();
void ADD_screen();
void Full_KeyBoard_window();
void Numeric_KeyBoard_window();
void Time_setting_window();
void Date_setting_window();
void warning_window();
void Timer_clock_screen();
//touch
word_t Full_KeyBoard_window_touch();
word_t Numeric_KeyBoard_window_touch();
void Switch_screen_touch();
void timer_screen_touch();
void slider_screen_touch();
//others 
void Clear_Display();








#endif // SCREENS_H








