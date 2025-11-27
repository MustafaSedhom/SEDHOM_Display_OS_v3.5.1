#include "SEDHOM_Communication.h"

#define SEDHOM_special_char   0x5C

void SEDHOM_OS_Device_Start_Comunication()
{
    Serial.begin(115200);
}
bool SEDHOM_Ready_or_Avaliable()
{
    return(Serial.available());
}
void SEDHOM_OS_Device_Send(string_t string)
{
    Serial.print(string);
    Serial.write(SEDHOM_special_char);
}
string_t SEDHOM_OS_Device_Recieve()
{
    #define size 100 
    char text[size];
    static char out[size];
    Serial.readStringUntil(SEDHOM_special_char).toCharArray(text,size);
    sprintf(out, "%s", text);
    return out;
}