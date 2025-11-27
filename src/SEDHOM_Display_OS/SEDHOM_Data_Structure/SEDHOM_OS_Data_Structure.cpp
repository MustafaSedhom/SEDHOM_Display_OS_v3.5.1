#include "SEDHOM_OS_Data_Structure.h"

//========================================================================================
// Stack functions
Stack::Stack(int Stack_size)
{
    size = Stack_size;
    array = new Data_Type[size];
    top = -1;
}
Stack::~Stack()
{
    delete[] array;
}
void Stack::push(Data_Type value)
{
    if(isFull())return;
    array[++top]=value;

}
Data_Type Stack::pop()
{
    if(isEmpty())return(Data_Type());
    Data_Type var = array[top];
    top--;
    return var;
}
Data_Type Stack::peak()
{
    if(isEmpty()) return(Data_Type());
    return (array[top]);
}
bool Stack::isEmpty()
{
    return(top == -1);
}
bool Stack::isFull()
{
    return(top == size-1);   
}
//========================================================================================
