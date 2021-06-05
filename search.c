#ifndef _SEARCH_C_
#define _SEARCH_C_
#include<stdio.h>
#include<string.h>
#include "phone.h"


extern int total_people;
void searchByName()
{
    Contact* p=PhoneBook;
    void* book=p;
    char name[20];
    int is_found=total_people;
    printf("Enter a name to search:");
    scanf("%s",name);
    for(int i=0; i<total_people; i++)
    {
        int is_match=1;
        for(int j=0; j<strlen(name); j++)
        {
            if((((Contact*)book+i)->Name)[j]!=name[j] || (strlen(name)!=strlen((((Contact*)book+i)->Name))))
            {
                is_match=0;
                is_found--;
                break;
            }
        }
        if(is_match)
        {
            printf("name:%s\t phone:%s\n", ((Contact*)book+i)->Name,((Contact*)book+i)->PhoneNumber);
            break;
        }
        if(is_found==0)
        {
            printf("Oops! %s is not in the PhoneBook.\n",name);
        }
    }
}
#endif
