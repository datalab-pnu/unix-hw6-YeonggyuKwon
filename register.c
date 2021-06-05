#ifndef _RESISTER_C_
#define _RESISTER_C_
#include<stdio.h>
#include "phone.h"
#include <string.h>

int total_people=0;
void registerPhoneData()
{
char* password="qwerty1234";
    char s[20];
    int count=0;
    static Contact* P=PhoneBook;
    printf("Ask to type password\n");
    while(count<3)
    {
        int true_password=1;
        printf("password:\n");
        scanf("%s", s);
        for(int i=0; i<strlen(s); i++)
        {
            if( (password[i] != s[i]) || (strlen(password)!=strlen(s)) )
            {
                count++;
                true_password=0;
                break;
            }
        }
        if(true_password)
        {
            printf("New User Name:");
            scanf("%s", P->Name);
            printf("PhoneNumber:");
            scanf("%s", P->PhoneNumber);
            printf("Registered...\n");
            P++;
            total_people++;
            break;
        }
        switch(count)
        {
        case 1:
            printf("not matched!!\n");
            break;
        case 2:
            printf("not matched(twice)!!\n");
            break;
        case 3:
            printf("not matched(3 times)!!!\n");
            printf("You are not allowed to access PhoneBook\n");
            break;
        }
    }

}
#endif
