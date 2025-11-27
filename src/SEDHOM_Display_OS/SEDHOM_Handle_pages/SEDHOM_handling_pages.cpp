#include "SEDHOM_handleing_pages.h"

Stack page(max_pages_number);
int current_page = -1;
int pages_number = 0;
void (**pages)(void) = nullptr;
//functions
void init_pages(int total_pages, void (**pages_array)(void))
{
    pages_number = total_pages;
    pages = pages_array;
    current_page = 1;
    page.push(current_page);
    show_current_page();
}

void push_page()
{
    if(current_page < pages_number)
    {
        current_page++;
        page.push(current_page);
        show_current_page();
    }
}

void push_page_with_number(int number)
{
    if(number >= 1 && number <= pages_number)
    {
        current_page = number;
        page.push(current_page);
        show_current_page();
    }
}


void pop_page()
{
    if(!page.isEmpty())
    {
        page.pop();
        if(!page.isEmpty())
            current_page = page.peak();
        else
            current_page = 1;
        show_current_page();
    }
}

void show_current_page()
{
    if(current_page >= 1 && current_page <= pages_number && pages != nullptr)
    {
        pages[current_page-1]();
    }
}
