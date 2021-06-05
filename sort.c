#ifndef _SORT_C_
#define _SORT_C_
#include<stdio.h>
#include<string.h>
#include "phone.h"
typedef int (*cmp)(const void*, int, int);
typedef int (*swap)(void*, int, int);
void sortPhoneBook(void *A, int size, cmp cfn, swap sfn);
int contactCmpr(const void*, int, int);
int contactSwap(void*, int, int);
extern int total_people;
extern void print();
void sort()
{
	printf("------Before sorting------\n");
    print();
    printf("\n");
	printf("------After sorting------\n");
	sortPhoneBook(PhoneBook, total_people, contactCmpr, contactSwap);
	print();
	printf("\n");
}

int contactCmpr(const void* arr, int i, int j)
{
return (strcmp((((Contact*)arr+i)->Name),((Contact*)arr+j)->Name));

}

int contactSwap(void* arr, int i, int j)
{
    arr=PhoneBook;
    Contact tmp;
    tmp=*((Contact*)arr+i);
    printf("%s\n", tmp.Name);
    *((Contact*)arr+i)=*((Contact*)arr+j);
    *((Contact*)arr+j)=tmp;
    return 1;
}

void sortPhoneBook(void *A, int size, cmp cfn, swap sfn)
{
    int i, j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(cfn(A, j,j+1)>0)
                sfn(A,j,j+1);
        }
    }
}
#endif
