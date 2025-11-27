#ifndef SEDHOM_HANDLEING_PAGES_H_
#define SEDHOM_HANDLEING_PAGES_H_

#include "../SEDHOM_Data_Structure/SEDHOM_OS_Data_Structure.h"

#define max_pages_number  50

#define add_page()      push_page()
#define remove_page()   pop_page()

// #define list_of_pages(...)   void (*pages_array[])(void) = {__VA_ARGES__};
#define list_of_pages            void (*pages_array[])(void)

#define list_of_pages_num        pages_array

#define SEDHOM_OS_handlig_pages()   int total_pages = sizeof(pages_array)/sizeof(pages_array[0]);\
                                    init_pages(total_pages, pages_array);

extern Stack page;             
extern int current_page;       
extern int pages_number;       

void init_pages(int total_pages, void (**pages_array)(void));

void push_page();
void push_page_with_number(int number);
void pop_page();
void show_current_page();

#endif
