#include "../SEDHOM_Data_Types/SEDHOM_OS_data_type.h"
#include "../SEDHOM_Data_Types/SEDHOM_OS_status_types.h"
/////////////////////////////////////
// use UART to communicate
/////////////////////////////////////
//defualt pins RX   0
//defualt pins TX   1


void SEDHOM_OS_Device_Start_Comunication();
bool SEDHOM_Ready_or_Avaliable();
void SEDHOM_OS_Device_Send(string_t string);
string_t SEDHOM_OS_Device_Recieve();