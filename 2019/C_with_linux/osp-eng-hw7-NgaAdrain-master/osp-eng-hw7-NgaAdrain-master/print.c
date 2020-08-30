#include <stdio.h>
#include "phone.h"
/*****************
** Your code..
** This function should be implemented in search.c
** Please modify this code with your vairables
*************************/
void print()
{
    printf("Print all contants in the PhoneBook\n");
	// This code illustrate sample usage of printArray()
	// Please modify this
	//Contact A[5]={
    //    {"Roki", "12345678"},
    //    {"Thor", "33333333"},
    //    {"IronMan","3765898"},
    //    {"Hulk", "74561253"},
    //    {"Groot", "99999999"}
    //};
	printArray(PhoneBook, size);
}

/*****************
** for implementing above two functions
** please study this funciton well
** Students can use this function for testing your codes.
*************************/
void printArray(void *arr, int size)
{
    int i;
    void *vp;
    vp= arr;
    for(i=0; i<size; i++)
    {
        // Calculate address for arr[i]:  ((Contact*)arr+i)
        // derefernce structure Contact: *((Contact*)arr+i)).Name
        // for stucture we use ->: ((Contact*)vp+i)->Name
        printf("Addr vp:%p\t", (Contact*)vp+i);
        printf("name:%s\t phone:%s\n", ((Contact*)vp+i)->Name, ((Contact*)vp+i)->PhoneNumber);
    }
    printf("\n");
}
