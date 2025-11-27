//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "../SEDHOM_Data_Types/SEDHOM_OS_data_type.h"
#include "../SEDHOM_Data_Types/SEDHOM_OS_status_types.h"
#include "../SEDHOM_Screen_And_Pages/SEDHOM_OS_Windos_And_Screens.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern byte_t Battary_Value ;

extern WIFI_STATUS_t WIFI_state ;
extern BLUETOOTH_STATUS_t Bluetooth_state ;
////
extern bool Is_changed_happend;
////
// extern Icons_t Icon;

extern byte_t Hour ;
extern byte_t min  ;
extern byte_t sec ;
extern word_t time_name ;

extern number_t year ;
extern byte_t day ;
extern byte_t month ;
extern byte_t day_in_week ;
extern char month_name[13][5] ;
extern char day_name[8][5] ;

extern word_t WIFI_NAME_1 ;
extern word_t WIFI_NAME_2 ;
extern word_t WIFI_NAME_3 ;
extern word_t WIFI_NAME_4 ;
extern word_t WIFI_NAME_5 ;
extern word_t WIFI_NAME_6 ;
extern word_t WIFI_NAME_7 ;
extern word_t WIFI_NAME_8 ;
extern word_t WIFI_NAME_9 ;
extern word_t WIFI_NAME_A ;


extern byte_t Range_wifi_1 ; 
extern byte_t Range_wifi_2 ;
extern byte_t Range_wifi_3 ;
extern byte_t Range_wifi_4 ;
extern byte_t Range_wifi_5 ;
extern byte_t Range_wifi_6 ;
extern byte_t Range_wifi_7 ;
extern byte_t Range_wifi_8 ;
extern byte_t Range_wifi_9 ; 
extern byte_t Range_wifi_A ;

extern WIFI_STATUS_t Range_wifi_draw_1 ;
extern WIFI_STATUS_t Range_wifi_draw_2 ;
extern WIFI_STATUS_t Range_wifi_draw_3 ;
extern WIFI_STATUS_t Range_wifi_draw_4 ;
extern WIFI_STATUS_t Range_wifi_draw_5 ;
extern WIFI_STATUS_t Range_wifi_draw_6 ;
extern WIFI_STATUS_t Range_wifi_draw_7 ;
extern WIFI_STATUS_t Range_wifi_draw_8 ;
extern WIFI_STATUS_t Range_wifi_draw_9 ;
extern WIFI_STATUS_t Range_wifi_draw_A ;

extern word_t BLE_NAME_1 ;
extern word_t BLE_NAME_2 ;
extern word_t BLE_NAME_3 ;
extern word_t BLE_NAME_4 ;
extern word_t BLE_NAME_5 ;
extern word_t BLE_NAME_6 ;
extern word_t BLE_NAME_7 ;
extern word_t BLE_NAME_8 ;
extern word_t BLE_NAME_9 ;
extern word_t BLE_NAME_A ;
//state
extern bool Switch_1_state ; 
extern bool Switch_2_state ; 
extern bool Switch_3_state ; 
extern bool Switch_4_state ; 
extern bool Switch_5_state ; 
extern bool Switch_6_state ; 
extern bool Switch_7_state ; 
extern bool Switch_8_state ; 
extern bool Switch_Timer_clock ;
//slide
extern byte_t Slider_1_Range ;
extern byte_t Slider_2_Range ;
extern byte_t Slider_3_Range ;
extern byte_t Slider_4_Range ;
extern byte_t Slider_5_Range ;
extern byte_t Slider_6_Range ;
extern byte_t Slider_7_Range ;
extern byte_t Slider_8_Range ;
//name
extern word_t switch_1_name ;
extern word_t switch_2_name ;
extern word_t switch_3_name ;
extern word_t switch_4_name ;
extern word_t switch_5_name ;
extern word_t switch_6_name ;
extern word_t switch_7_name ;
extern word_t switch_8_name ;
//sensor-label
extern word_t sensor_1_name ;
extern word_t sensor_2_name ;
extern word_t sensor_3_name ;
extern word_t sensor_4_name ;
extern word_t sensor_5_name ;
extern word_t sensor_6_name ;
extern word_t sensor_7_name ;
extern word_t sensor_8_name ;
//slider
extern word_t Slider_1_name ;
extern word_t Slider_2_name ;
extern word_t Slider_3_name ;
extern word_t Slider_4_name ;
extern word_t Slider_5_name ;
extern word_t Slider_6_name ;
extern word_t Slider_7_name ;
extern word_t Slider_8_name ;
//foldeers & files
extern word_t folder_1_name ;
extern word_t folder_2_name ;
extern word_t folder_3_name ;
extern word_t folder_4_name ;
extern word_t folder_5_name ;
extern word_t folder_6_name ;
extern word_t folder_7_name ;
extern word_t folder_8_name ;
extern word_t file_1_extend ;
extern word_t file_2_extend ;
extern word_t file_3_extend ;
extern word_t file_4_extend ;
extern word_t file_5_extend ;
extern word_t file_6_extend ;
extern word_t file_7_extend ;
extern word_t file_1_name ;
extern word_t file_2_name ;
extern word_t file_3_name ;
extern word_t file_4_name ;
extern word_t file_5_name ;
extern word_t file_6_name ;
extern word_t file_7_name ;
extern word_t file_8_name ;
//sensor
extern word_t sensor_1_state ;
extern word_t sensor_2_state ;
extern word_t sensor_3_state ;
extern word_t sensor_4_state ;
extern word_t sensor_5_state ;
extern word_t sensor_6_state ;
extern word_t sensor_7_state ;
extern word_t sensor_8_state ;
// label
extern u8_t end_label ;
// terminal
extern word_t command;
extern word_t warning_msg_Title  ;
extern word_t warning_msg_line_1 ;
extern word_t warning_msg_line_2 ;
extern word_t warning_msg_line_3 ;
extern word_t warning_msg_line_4 ;
extern word_t warning_msg_line_5 ;
extern bool colors_in_terminal_or_GREEN ;
extern bool do_command ;
extern bool end_command ;
// extern String Dir ;
extern word_t dir;
extern int line ;
//add new wifi
extern word_t add_new_wifi_SSID ; 
extern word_t add_new_wifi_Password ; 
//wifi window
extern bool Is_window_1_or_window_2_wifi_window ;
extern bool Is_window_1_or_window_2_BLE_window ;
//keyboard
extern bool caps_lock ;
extern bool special_char ;
extern word_t Full_KeyBoard_window_user_input_TXT ;
extern word_t Numeric_KeyBoard_window_user_input_num ;
//timer
extern bool Timer_clock_is_on ;
extern byte_t Timer_clock_month ;
extern byte_t Timer_clock_day ;
extern byte_t Timer_clock_hour ;
extern byte_t Timer_clock_min ;
extern byte_t Timer_clock_sec ;
extern word_t Timer_clock_time_name ;
//////////////////////////////////////////////////////
//colors
extern Color_t BLE_color ;
extern Color_t WIFI_ON_color ;
extern Color_t WIFI_OFF_color ;
extern Color_t Battary_color ;
extern Color_t Time_color ;
extern Color_t Back_arraw_color ;

extern Color_t slider_Icon_color ;
extern Color_t sensor_Icon_color ;
extern Color_t About_Icon_color ;
extern Color_t Setting_Icon_color ;
extern Color_t ADD_Icon_color ;
extern Color_t Switch_on_color ;
extern Color_t Switch_off_color ;
extern Color_t TXT_color_in_main_screen ;
extern Color_t TXT_color_in_Switch_screen ;
extern Color_t TXT_color_in_setting_screen ;
extern Color_t TXT_color_in_Sensor_screen ;
extern Color_t TXT_color_in_Slider_screen ;
extern Color_t TXT_color_in_SD_Card_screen ;
extern Color_t TXT_color_in_Timer_clock_screen ;
extern Color_t TXT_color_in_time_window ;
extern Color_t TXT_color_in_Date_window ;
extern Color_t color_str_in_label_in_sensor_screen ;
extern Color_t color_label_in_sensor_screen ;
extern Color_t slide_active_color ;
extern Color_t slide_not_active_color ;
extern Color_t slide_ball_color ;
extern Color_t slider_box_color ;
extern Color_t slider_Range_in_box_color ;
extern Color_t folder_1_color ;
extern Color_t folder_2_color ;
extern Color_t folder_3_color ;
extern Color_t folder_4_color ;
extern Color_t folder_5_color ;
extern Color_t folder_6_color ;
extern Color_t folder_7_color ;
extern Color_t folder_8_color ;
extern Color_t file_end_color ;
extern Color_t file_Background_color ;
extern Color_t file_1_color ;
extern Color_t file_2_color ;
extern Color_t file_3_color ;
extern Color_t file_4_color ;
extern Color_t file_5_color ;
extern Color_t file_6_color ;
extern Color_t file_7_color ;
extern Color_t file_8_color ;
extern Color_t file_1_extend_color ;
extern Color_t file_2_extend_color ;
extern Color_t file_3_extend_color ;
extern Color_t file_4_extend_color ;
extern Color_t file_5_extend_color ;
extern Color_t file_6_extend_color ;
extern Color_t file_7_extend_color ;
extern Color_t file_8_extend_color ;
//CMD
extern Color_t color_CMD_answer ; 
extern Color_t color_char_answer ; 
extern Color_t color_error_answer ; 
extern Color_t color_dir ; 
extern Color_t color_command ; 
//full keyboard
extern Color_t Full_KeyBoard_window_color ;
extern Color_t Full_KeyBoard_window_user_input_TXT_color  ;
extern Color_t Full_KeyBoard_window_user_input_BOX_color  ;
extern Color_t Full_KeyBoard_window_TXT_color ;
//numeric keyboard
extern Color_t Numeric_KeyBoard_window_color ;
extern Color_t Numeric_KeyBoard_window_user_input_TXT_color  ;
extern Color_t Numeric_KeyBoard_window_user_input_BOX_color  ;
extern Color_t Numeric_KeyBoard_window_TXT_color ;
//add wifi
extern Color_t Add_new_WIFI_Window_color ;
//wifi window
extern Color_t color_window_wifi_window ;
extern Color_t color_TXT_wifi_window ;
extern Color_t wifi_color_show_wifi_window ;
extern Color_t wifi_color_dont_show_wifi_window ;
extern Color_t txt_range_wifi_color_wifi_window ;
//BLE window
extern Color_t color_window_BLE_window ;
extern Color_t color_TXT_BLE_window ;
//3D screen color
extern Color_t LCD_3D_Controll_Axis_Screen_color ;
//lock screen color
extern Color_t lock_screen_color ;
//date and time window
extern Color_t color_inc ;
extern Color_t color_dec ;
extern Color_t color_num ;
extern Color_t box_inc_color ;
extern Color_t box_dec_color ;
extern Color_t box_num_color ;
extern Color_t warning_box_color ;
extern Color_t warning_box_end_color ;
extern Color_t warning_TXT_msg_color ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////