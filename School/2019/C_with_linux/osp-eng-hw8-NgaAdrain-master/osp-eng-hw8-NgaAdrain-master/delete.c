#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

static char temp[N_MAX];

typedef void (*dnf)(char*);//define function pointer
void deleteNode(char* name);

//delete function's driver function//
void deleteByName(){
	dnf process = deleteNode;
	printf("Delete by Name\n");
	printf(">> Enter a name to delete : ");
	fgets(temp,N_MAX,stdin);
	temp[strlen(temp)-1]='\0';	//delete \n	
	process(temp);
}

void deleteNode(char* name){
	Node *temp = PhoneBook;	
	Node *parent = temp;
	int check = 0;
	while(temp!=NULL){
		check = strcmp(name,temp->info.Name);
		if(check != 0){
			parent = temp;
			temp = temp->next;
		}
		else{
			if(temp == head){
				head = temp->next;
				PhoneBook = head;
			}
			else if(temp == tail){
				parent->next = NULL;
				tail = parent;
			}
			else{
				parent->next = temp -> next;
			}
			parent = NULL;
			free(temp);
			temp = NULL;
			printf("%s is deleted...\n",name);
			break;	
		}
	}
	if(check!=0){
		parent = NULL;
		temp = NULL;
		printf("Oops! %s is not in the PhoneBook!\n",name);
	}
}

