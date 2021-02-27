#include <stdio.h>
#include <string.h>
#include "phone.h"

static char temp[N_MAX];
static int i = 0;
void searchByName(){
	printf("Search by Name\n");
	printf(">> Enter a name to search : ");	
	fgets(temp,N_MAX,stdin);
	temp[strlen(temp)-1] = '\0';	//remove \n
	while(i < size){
	if(!strcmp(temp,PhoneBook[i].Name)) break;
	i++;
	}
	if(i!=size){
		if(strlen(PhoneBook[i].Name)>6)	
			printf("%s \t %s\n",PhoneBook[i].Name,
				PhoneBook[i].PhoneNumber);
		else
			printf("%s \t\t %s\n",PhoneBook[i].Name,
				PhoneBook[i].PhoneNumber);
		}	
	else
		printf("Oops! %s is not in the PhoneBook!\n",temp);
	i = 0;
}
