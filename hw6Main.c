#ifndef _HW6MAIN_C_
#define _HW6MAIN_C_
#include <stdio.h>
#include "phone.h"

extern void registerPhoneData();
extern void print();
extern void searchByName();
extern void deleteByName();
extern void sort();
void (* pFuncs[5])()={registerPhoneData, print, searchByName, deleteByName,sort};
static int count_service = 0;

int main(int argc, char **argv)
{
	int service;
	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t 2. Print All \t 3. Search by ID \t 4. Delete \t 5. Sort \t 6. Exit >>>\n");
        printf(" Please enter your service number (1-6)> ");
		scanf("%d", &service);
		if ( service > 0 && service <= 5 )
		{
			pFuncs[service-1]();
		}
		else if( service ==0 || service > 6)
		{
			printf("You choose a wrong service number\n");
		}
	} while (service != 6);
	return 0;
}

#endif
