#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

// function pointer declaration
typedef int (*cmp)(const void*, int, int);
typedef int (*swap)(void*, int, int);

// Sorting PhoneBook using bubble sort
// 3rd parameter cmp cfn: a pointer to function
// 4th parameter swap sfn: a pointer to function
void sortPhoneBook(void *A, int size, cmp cfn, swap sfn);

// Functions for sortPhoneBook
// Should implement these two fuction
int contactCmpr(const void*, int, int);
int contactSwap(void*, int, int);

/*****************
** Your code..
** This function should be implemented in sort.c
** Please modify some parts with your vairables
*************************/
void sort()
{
	// This is test codes 
	// Please modify => complete//
	/*
	Contact A[5]={
        {"Roki", "12345678"},
        {"Thor", "33333333"},
        {"IronMan","3765898"},
        {"Hulk", "74561253"},
        {"Groot", "99999999"}
    };
	*/
	// calling actual bubble sort
	// modify this function with your arrays
	// if you implement contactCmpr() and contactSwap() well
	// this code works correctly
	//===================================================//
	printf("Sort fuction is called\n");
	printf("Before sorting\n");
	printArray(PhoneBook,size);
	sortPhoneBook(PhoneBook, size, contactCmpr, contactSwap);
	printf("After sorting\n");
	printArray(PhoneBook,size);
	//===================================================//
}

/************************
*** Bubble sort code is provide
*** Do not modify this code
*************************/
void sortPhoneBook(void *A, int size, cmp cfn, swap sfn)
{
    int i, j;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(cfn(A,j,j+1)>0)
                sfn(A,j,j+1);
        }
    }
}

/*****************
** Your code..
** This function should be implemented in sort.c
*************************/
// strcmp(s1,s2); returns differ based on s1
int contactCmpr(const void* arr, int i, int j)
{
    // if arr[i]> arr[j], return 1
    // else retrun 0
	// Calculate address for arr[i]:  ((Contact*)arr+i)
    // derefernce structure Contact: *((Contact*)arr+i)).Name
    // for stucture we use ->: ((Contact*)arr+i)->Name
	//===================================================//
	int check = strcmp(((Contact*)arr+i)->Name,((Contact*)arr+j)->Name);		
	if(check >0) return 1;
	else return 0;
	//===================================================//
}

/*****************
** Your code..
** This function should be implemented in sort.c
*************************/
int contactSwap(void* arr, int i, int j)
{
    // Goal: arr[i] <- arr[j], arr[j] <- arr[i]
    // calculate address for arr[i]:  ((int*)arr+i)
    // derefernce int: *((int*)arr+i))
	//===================================================//
	Contact *temp = (Contact*) malloc (sizeof(Contact)); 	
	memcpy(temp, arr+(sizeof(Contact)*i),sizeof(Contact)); 	
	memcpy(arr+(sizeof(Contact)*i),arr+(sizeof(Contact)*j),sizeof(Contact));
	memcpy(arr+(sizeof(Contact)*j),temp,sizeof(Contact));
    return 1;
	//===================================================//
}

