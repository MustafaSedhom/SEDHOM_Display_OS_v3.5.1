#ifndef SEDHOM_OS_DATA_STRUCTURE_H_
#define SEDHOM_OS_DATA_STRUCTURE_H_

#include "../SEDHOM_Data_Types/SEDHOM_OS_data_type.h"

//========================================================================================
// Stack class
#ifndef STACK_DATA_TYPE
#define STACK_DATA_TYPE int
#endif
typedef STACK_DATA_TYPE Data_Type;
class Stack
{
    private:
        Data_Type* array;
        int size;
        int top;

    public:
        Stack(int Stack_size);
        ~Stack();
        bool isEmpty();
        bool isFull();
        void push(Data_Type value);
        Data_Type pop();
        Data_Type peak();
};
//========================================================================================

#endif
