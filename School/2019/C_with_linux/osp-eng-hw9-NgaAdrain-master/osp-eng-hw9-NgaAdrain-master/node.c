#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

void addNode(Contact info){
	tail->next = (Node*) malloc(sizeof(Node));
	tail = tail->next;
	tail->info = info;
	tail->next = NULL;
}

int searchNode(char* name){
	Node *temp = PhoneBook;
	Contact* result = NULL;
	int check = 0;
	while(temp!=NULL){
		check = strcmp(name,temp->info.Name);
		if(check != 0){
			temp = temp->next;
		}
		else{
			printf("%s\t %s\n",temp->info.Name,temp->info.PhoneNumber);	
		}
	}
	if(check!=0)
		return 0;	
	else
		return 1;
}

void deleteNode(char* name){
	Node *temp = PhoneBook;	
	Node *parent = temp;
	int check = 0;
	while(temp->next!=NULL){
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
			break;
		}
	}
	if(check!=0){
		parent = NULL;
		temp = NULL;
	}
}

