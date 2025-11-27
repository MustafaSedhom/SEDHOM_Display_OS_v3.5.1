#ifndef STATUS_TYPES_H
#define STATUS_TYPES_H



#define SmallFont        &FreeSmallFont
#define BigFont          &FreeBigFont
#define SevenSegNumFont  &FreeSevenSegNumFont
#define font_7_segment   SevenSegNumFont

#define Night_Mode       BLACK
#define Dark_Mode        BLACK
#define Light_Mode       WHITE
#define Normal_Mode      WHITE

#define Vertical         0 
#define Horizontal       1

#define on               ON
#define off              OFF


typedef enum WIFI_Status
{
    WIFI_Status_not_connected,
    WIFI_Status_no_internet,
    WIFI_Status_conected_level_1,
    WIFI_Status_conected_level_2_half,
    WIFI_Status_conected_level_3,
    WIFI_Status_conected_level_4_full
}WIFI_STATUS_t;
typedef enum Bluetooth_Status
{
    BLuetooth_Status_closed,
    BLuetooth_Status_open_and_not_connected,
    BLuetooth_Status_open_and_connected
}BLUETOOTH_STATUS_t;

typedef enum Set_Rotation
{
    degree_0,
    degree_90,
    degree_270,
    degree_180,
}ROTATION_STASTUS_t;
typedef enum Set_Switch
{
    OFF,
    ON
}SWITCH_STATUS_t;

#endif
