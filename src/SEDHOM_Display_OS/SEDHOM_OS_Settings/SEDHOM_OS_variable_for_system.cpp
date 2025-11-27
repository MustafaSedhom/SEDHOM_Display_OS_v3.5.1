//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "SEDHOM_OS_variable_for_system.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern Icons Icon;

byte_t Battary_Value = 99 ;
WIFI_STATUS_t WIFI_state = WIFI_Status_no_internet;
BLUETOOTH_STATUS_t Bluetooth_state = BLuetooth_Status_open_and_not_connected;
////
bool Is_changed_happend = false;
////

byte_t Hour = 00;
byte_t min  = 00;
byte_t sec  = 00;
word_t time_name = "AM";

number_t year = 0000;
byte_t month = 00;
byte_t day  = 00;
byte_t day_in_week = 5;
char month_name[13][5] = {"","Jan","Feb" ,"Mar" ,"Apr" ,"May" ,"Jun" ,"Jul" ,"Aug" ,"Sep" ,"Oct" ,"Nov" ,"Dec" } ;
char day_name[8][5] = {"","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

word_t WIFI_NAME_1 ="Mustafa Sed..."; 
word_t WIFI_NAME_2 ="WE_A84E5B";
word_t WIFI_NAME_3 ="MEO_WIFI";       
word_t WIFI_NAME_4 ="ESP8266_WIFI";
word_t WIFI_NAME_5 ="BON_24680";      
word_t WIFI_NAME_6 ="ESP32_wifi";
word_t WIFI_NAME_7 ="Eslam_netw...";  
word_t WIFI_NAME_8 ="me";
word_t WIFI_NAME_9 ="ALLAH_AKBAR";   
word_t WIFI_NAME_A ="FW86H";


byte_t Range_wifi_1 = 99;
byte_t Range_wifi_2 = 82;
byte_t Range_wifi_3 = 47;
byte_t Range_wifi_4 = 21;
byte_t Range_wifi_5 = 35;
byte_t Range_wifi_6 = 65;
byte_t Range_wifi_7 = 78; 
byte_t Range_wifi_8 = 10;
byte_t Range_wifi_9 = 54; 
byte_t Range_wifi_A = 26;

WIFI_STATUS_t Range_wifi_draw_1 = WIFI_Status_no_internet;
WIFI_STATUS_t Range_wifi_draw_2 = WIFI_Status_no_internet;
WIFI_STATUS_t Range_wifi_draw_3 = WIFI_Status_no_internet;
WIFI_STATUS_t Range_wifi_draw_4 = WIFI_Status_no_internet;
WIFI_STATUS_t Range_wifi_draw_5 = WIFI_Status_no_internet;
WIFI_STATUS_t Range_wifi_draw_6 = WIFI_Status_no_internet;
WIFI_STATUS_t Range_wifi_draw_7 = WIFI_Status_no_internet; 
WIFI_STATUS_t Range_wifi_draw_8 = WIFI_Status_no_internet;
WIFI_STATUS_t Range_wifi_draw_9 = WIFI_Status_no_internet; 
WIFI_STATUS_t Range_wifi_draw_A = WIFI_Status_no_internet;

word_t BLE_NAME_1 ="Mustafa Sed..."; 
word_t BLE_NAME_2 ="WE_A84E5B";
word_t BLE_NAME_3 ="MEO_WIFI";       
word_t BLE_NAME_4 ="ESP8266_WIFI";
word_t BLE_NAME_5 ="BON_24680";      
word_t BLE_NAME_6 ="ESP32_wifi";
word_t BLE_NAME_7 ="Eslam_netw...";  
word_t BLE_NAME_8 ="me";
word_t BLE_NAME_9 ="ALLAH_AKBAR";   
word_t BLE_NAME_A ="FW86H";
//
//state
bool Switch_1_state = OFF;
bool Switch_2_state = OFF;
bool Switch_3_state = OFF;
bool Switch_4_state = OFF;
bool Switch_5_state = OFF;
bool Switch_6_state = OFF;
bool Switch_7_state = OFF;
bool Switch_8_state = OFF;
bool Switch_Timer_clock = OFF;
//sensor
word_t sensor_1_state ="0000000";
word_t sensor_2_state ="0000000";
word_t sensor_3_state ="0000000";
word_t sensor_4_state ="0000000";
word_t sensor_5_state ="0000000";
word_t sensor_6_state ="0000000";
word_t sensor_7_state ="0000000";
word_t sensor_8_state ="0000000";
//slider
byte_t Slider_1_Range = 0 ;
byte_t Slider_2_Range = 0 ;
byte_t Slider_3_Range = 0 ;
byte_t Slider_4_Range = 0 ;
byte_t Slider_5_Range = 0 ;
byte_t Slider_6_Range = 0 ;
byte_t Slider_7_Range = 0 ;
byte_t Slider_8_Range = 0 ;
//name
word_t switch_1_name ="Button1";
word_t switch_2_name ="Button2";
word_t switch_3_name ="Button3";
word_t switch_4_name ="Button4";
word_t switch_5_name ="Button5";
word_t switch_6_name ="Button6";
word_t switch_7_name ="Button7";
word_t switch_8_name ="Button8";
//sensor-label
word_t sensor_1_name ="sensor1";
word_t sensor_2_name ="sensor2";
word_t sensor_3_name ="sensor3";
word_t sensor_4_name ="sensor4";
word_t sensor_5_name ="sensor5";
word_t sensor_6_name ="sensor6";
word_t sensor_7_name ="sensor7";
word_t sensor_8_name ="sensor8";
//slider
word_t Slider_1_name ="Slider1";
word_t Slider_2_name ="Slider2";
word_t Slider_3_name ="Slider3";
word_t Slider_4_name ="Slider4";
word_t Slider_5_name ="Slider5";
word_t Slider_6_name ="Slider6";
word_t Slider_7_name ="Slider7";
word_t Slider_8_name ="Slider8";
//folder&files
word_t folder_1_name = "  OS";
word_t folder_2_name = "SEDH~2";
word_t folder_3_name = "SEDH~3";
word_t folder_4_name = "SEDH~4";
word_t folder_5_name = "SEDH~5";
word_t folder_6_name = "SEDH~6";
word_t folder_7_name = "SEDH~7";
word_t folder_8_name = "SEDH~8";
word_t file_1_extend ="TXT";
word_t file_2_extend ="C++";
word_t file_3_extend ="py";
word_t file_4_extend ="HEX";
word_t file_5_extend ="HEX";
word_t file_6_extend ="HEX";
word_t file_7_extend ="HEX";
word_t file_8_extend ="HEX";
word_t file_1_name ="sed~1.TXT";
word_t file_2_name ="sed~2.Cpp";
word_t file_3_name ="sed~3.py";
word_t file_4_name ="sed~4.HEX";
word_t file_5_name ="sed~5.HEX";
word_t file_6_name ="sed~6.HEX";
word_t file_7_name ="sed~7.HEX";
word_t file_8_name ="sed~8.HEX";

word_t command = "";
word_t warning_msg_Title = " Warning!!!";
word_t warning_msg_line_1 = "";
word_t warning_msg_line_2 = "";
word_t warning_msg_line_3 = "Error in System";
word_t warning_msg_line_4 = "";
word_t warning_msg_line_5 = "";
u8_t end_label = 5; 
bool colors_in_terminal_or_GREEN = 1;
bool do_command = 0;
bool end_command = 0;
// String Dir = "S::SEDHOM -> ";
word_t dir = "S::SEDHOM -> ";
int line = 60;
//add wifi
word_t add_new_wifi_SSID = ""; 
word_t add_new_wifi_Password = ""; 
//wifi window
bool Is_window_1_or_window_2_wifi_window = 0 ;
bool Is_window_1_or_window_2_BLE_window = 0 ;
//timer
bool Timer_clock_is_on = OFF; 
byte_t Timer_clock_month = 00; 
byte_t Timer_clock_day = 00;
byte_t Timer_clock_hour = 00; 
byte_t Timer_clock_min = 00; 
byte_t Timer_clock_sec = 00; 
word_t Timer_clock_time_name = "??"; 
//keyboard
word_t Full_KeyBoard_window_user_input_TXT = "";
word_t Numeric_KeyBoard_window_user_input_num = "" ;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//colors
//APP_Bar
Color_t BLE_color = YELLOW;
Color_t WIFI_ON_color = BLUE;
Color_t WIFI_OFF_color = DARKGREY;
Color_t Battary_color = GREEN;
Color_t Time_color = MAGENTA;
Color_t Back_arraw_color = BLUE;

//Icons
Color_t slider_Icon_color = BLUE;
Color_t sensor_Icon_color = RED;
Color_t About_Icon_color = Icon.Not_mode();
Color_t Setting_Icon_color = YELLOW;
Color_t ADD_Icon_color = GREEN;
Color_t Switch_on_color = GREEN;
Color_t Switch_off_color = RED;
Color_t TXT_color_in_main_screen = RED;
Color_t TXT_color_in_setting_screen = YELLOW;
Color_t TXT_color_in_Switch_screen = MAGENTA;
Color_t TXT_color_in_Sensor_screen = CYAN;
Color_t TXT_color_in_Slider_screen = RED;
Color_t TXT_color_in_SD_Card_screen = GREEN;
Color_t TXT_color_in_Timer_clock_screen = MAGENTA ;
Color_t TXT_color_in_time_window = RED ;
Color_t TXT_color_in_Date_window = BLUE ;
Color_t color_str_in_label_in_sensor_screen = MAGENTA;
Color_t color_label_in_sensor_screen = GREEN;
Color_t slide_active_color = GREEN ;
Color_t slide_not_active_color = RED ;
Color_t slide_ball_color = Icon.Not_mode() ;
Color_t slider_box_color = MAGENTA ;
Color_t slider_Range_in_box_color = BLUE ;
//folder => CYAN
Color_t folder_1_color = CYAN;
Color_t folder_2_color = CYAN;
Color_t folder_3_color = CYAN;
Color_t folder_4_color = CYAN;
Color_t folder_5_color = CYAN;
Color_t folder_6_color = CYAN;
Color_t folder_7_color = CYAN;
Color_t folder_8_color = CYAN;
Color_t file_end_color = Icon.Not_mode();
Color_t file_Background_color = Icon.Mode();
//folder => BLUE
Color_t file_1_color = RED;
Color_t file_2_color = BLUE;
Color_t file_3_color = MAGENTA;
Color_t file_4_color = CYAN;
Color_t file_5_color = GREEN;
Color_t file_6_color = WHITE;
Color_t file_7_color = YELLOW;
Color_t file_8_color = DARKGREY;
Color_t file_1_extend_color = Icon.Mode();
Color_t file_2_extend_color = Icon.Mode();
Color_t file_3_extend_color = Icon.Mode();
Color_t file_4_extend_color = Icon.Mode();
Color_t file_5_extend_color = Icon.Mode();
Color_t file_6_extend_color = Icon.Mode();
Color_t file_7_extend_color = Icon.Mode();
Color_t file_8_extend_color = Icon.Mode();
//CMD
Color_t color_CMD_answer ; //BLUE
Color_t color_char_answer ; // WHITE
Color_t color_error_answer ; // ORANGE
Color_t color_dir ; // RED
Color_t color_command = GREEN; // GREEN
//full keyboard
Color_t Full_KeyBoard_window_color = MAGENTA ;
Color_t Full_KeyBoard_window_user_input_TXT_color = BLACK ;
Color_t Full_KeyBoard_window_user_input_BOX_color = WHITE ;
Color_t Full_KeyBoard_window_TXT_color = Icon.Not_mode();
bool caps_lock = 0;
bool special_char = 0;
// numeric keyboard
Color_t Numeric_KeyBoard_window_color = BLUE ;
Color_t Numeric_KeyBoard_window_user_input_TXT_color = BLACK ;
Color_t Numeric_KeyBoard_window_user_input_BOX_color = WHITE ;
Color_t Numeric_KeyBoard_window_TXT_color = Icon.Not_mode();
//add wifi
Color_t Add_new_WIFI_Window_color = MAGENTA ;
//wifi window
Color_t color_window_wifi_window = MAGENTA ;
Color_t color_TXT_wifi_window = BLUE ;
Color_t wifi_color_show_wifi_window = GREEN ;
Color_t wifi_color_dont_show_wifi_window = DARKGREY ;
Color_t txt_range_wifi_color_wifi_window = WHITE ;
//BLE window
Color_t color_window_BLE_window = RED ;
Color_t color_TXT_BLE_window = YELLOW;
//3D screen color
Color_t LCD_3D_Controll_Axis_Screen_color = RED ;
//lock screen color
Color_t lock_screen_color = MAGENTA ;
//date and time window
Color_t color_inc =BLUE;
Color_t color_dec =RED;
Color_t color_num =CYAN;
Color_t box_inc_color =Icon.Mode();
Color_t box_dec_color =Icon.Mode();
Color_t box_num_color =Icon.Mode();
//warning window
Color_t warning_box_color = BLACK ;
Color_t warning_box_end_color = BLUE ;
Color_t warning_TXT_msg_color = RED ;













////////////////////////////////////////////////////////////////////////////////////////////////////////////////////