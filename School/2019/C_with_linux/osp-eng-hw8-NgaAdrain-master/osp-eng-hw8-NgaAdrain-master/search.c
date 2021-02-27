#include <stdio.h>
#include <string.h>
#include "phone.h"

int searchNode(char* name);
//search function//
void searchByName(){
	
	char temp[N_MAX];
	int c = 0;
	printf("Search by Name\n");
	printf(">> Enter a name to search : ");	
	fgets(temp,N_MAX,stdin);
	temp[strlen(temp)-1] = '\0';	//remove \n
	c = searchNode(temp);	
	if(!c)
		printf("Oops! %s in not in the PhoneBook!\n",temp);
}

int searchNode(char* name){
	Node *temp = PhoneBook;
	int check = 0;
	while(temp!=NULL){
		check = strcmp(name,temp->info.Name);
		if(check != 0){
			temp = temp->next;
		}
		else{
			printf("%s\t %s\n",temp->info.Name,temp->info.PhoneNumber);	
			break;	
		}
	}
	if(check!=0)
		return 0;	
	else
		return 1;
}
