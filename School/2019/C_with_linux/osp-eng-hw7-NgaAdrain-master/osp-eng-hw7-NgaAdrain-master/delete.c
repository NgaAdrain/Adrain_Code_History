#include <stdio.h>
#include <string.h>
#include "phone.h"

static char temp[N_MAX];
static int i = 0;

typedef void (*dnf)();//define function pointer
void deleteNSort();

//delete function's driver function//
void deleteByName(){
	dnf process = deleteNSort;//OK //but no necessity to use // just practicing
	printf("Delete by Name\n");
	printf(">> Enter a name to delete : ");
	fgets(temp,N_MAX,stdin);
	temp[strlen(temp)-1]='\0';	//delete \n	
	while(i < size){
	if(!strcmp(temp,PhoneBook[i].Name)) break;
	i++;
	}
	if(i!=size)
		process();
	else
		printf("Oops! %s is not in the PhoneBook!\n",temp);
	i = 0;
}

//delete function's navigator function//
void deleteNSort(){
	if(i==size) return;
	while(i<size-1){
	strcpy(PhoneBook[i].Name,PhoneBook[i+1].Name);	
	strcpy(PhoneBook[i].PhoneNumber,PhoneBook[i+1].PhoneNumber);
	i++;
	}
	size--;
	printf("%s is deleted...\n",temp);
}
