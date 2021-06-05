#ifndef _PRINT_C_
#define _PRINT_C_
#include<stdio.h>
#include "phone.h"

void print()
{
    extern int total_people;
    Contact* p=PhoneBook;
    void* book=p;
    printf("Print all contants in the PhoneBook\n");
    for(int i=0; i<total_people; i++)
    {
        if( (((Contact*)book)->Name)=="" && (((Contact*)book)->PhoneNumber)=="" ) break;
        printf("name:%s\t phone:%s\n", ((Contact*)book+i)->Name,((Contact*)book+i)->PhoneNumber);
    }
}
#endif
