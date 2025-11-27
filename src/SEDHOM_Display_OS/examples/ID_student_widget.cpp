// #include <Arduino.h>
// #include "../SEDHOM_Display_OS.h"

// SEDHOM_OS_Icons_t Icon_TFT;
// void ID_on_tap();

// User_ID_Data_t Student[]={
//     // Null student => 0
//     {
//         false,
//         "************",
//         "************",
//         "************",
//         "************",
//         "************",
//         "*** *** *** **",
//     },  
//     //mustafa sedhom student => 1  
//     {
//          true,
//         "MUSTAFA SEDHOM",
//         "SCIENCE UNVERSITY",
//         "COMPUTER SCINCE",
//         "AND MATHEMATICS",
//         "22/02/2006",
//         "011 449 829 08"
//     },
//     //Ahmed sedhom student => 2  
//     {
//          false,
//         "AHMED SEDHOM",
//         "MEDICEN UNVERSITY",
//         "COMPUTER SCINCE",
//         "AND MATHEMATICS",
//         "23/07/2003",
//         "012 876 234 90"
//     },
//     //Omar sedhom student => 3
//     {
//          false,
//         "OMAR SEDHOM",
//         "AMU UNVERSITY",
//         "COMPUTER SCINCE",
//         "AND MATHEMATICS",
//         "01/11/2004",
//         "015 932 247 98"
//     },
// };


// #define student_index 3


// void setup()
// {
//     /////////////////////////////////////////////////////////////////////////////
//     SEDHOM_OS_Device_Start_Comunication();
//     ////////////////////////////////////////////////////////////////////////////
//     init_Rotation_and_mode(1,BLACK);   
//     ////////////////////////////////////////////////////////////////////////////

//     Icon_TFT.ID_Card_Icon(
//         200,10,Icon_TFT.Mode(),GREEN,CYAN,Icon_TFT.Mode(),true,false,
//         Student[student_index].is_professser,
//         Student[student_index].user_name,
//         Student[student_index].universty,
//         Student[student_index].department_1,
//         Student[student_index].department_2,
//         Student[student_index].Born,
//         Student[student_index].number,
//         ID_on_tap
//     ); 

// }
// void loop()
// {
// }
// void ID_on_tap()
// {

// }