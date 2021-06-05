#ifndef _DELETE_C_
#define _DELETE_C_
#include<stdio.h>
#include<string.h>
#include "phone.h"

extern int total_people;
void deleteByName()
{

    Contact* p=PhoneBook;
    Contact* P=PhoneBook;
    char* c ="\0";
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
            for(int k=i; k<total_people-1; k++)
            {
                strcpy((P+k)->Name,(P+k+1)->Name);
                strcpy((P+k)->PhoneNumber,(P+k+1)->PhoneNumber);
            }
            strcpy((P+total_people)->Name, c);
            strcpy((P+total_people)->PhoneNumber, c);
            total_people--;
            printf("%s is deleted...\n",name);
            break;
        }
        if(is_found==0)
        {
            printf("Oops! %s is not in the PhoneBook.\n",name);
        }
    }
}
#endif
