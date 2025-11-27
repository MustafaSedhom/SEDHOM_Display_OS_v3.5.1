#include <stdint.h>
#include <Arduino.h>

#define u8_t           uint8_t
#define u16_t          uint16_t
#define u32_t          uint32_t
#define u64_t          uint64_t
#define Color_t        uint16_t
#define number_t       int
#define decimal_t      float
#define byte_t         int8_t
#define u_small_num_t  byte_t
#define Icons_t        Icons
#define str_t          char*
#define string_t       str_t
#define word_t         str_t

#define SEDHOM_OS_Device_Wait(sec)              delay((1000*sec))
#define SEDHOM_OS_Device_Wait_millis(mil_sec)   delay((mil_sec))