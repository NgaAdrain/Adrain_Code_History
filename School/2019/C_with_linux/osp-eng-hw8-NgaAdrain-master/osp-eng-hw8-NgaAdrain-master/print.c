#include <stdio.h>
#include "phone.h"
/*****************
** Your code..
** This function should be implemented in search.c
** Please modify this code with your vairables
*************************/
void printNode(Node *inp);

void print()
{
    printf("Print all contants in the PhoneBook\n");
	printNode(PhoneBook);
}

//printNode//
void printNode(Node *inp){
	Node* temp = inp;
	while(temp != NULL){
		printf("Addr vp:%p\t",temp);
		printf("name:%s\t phone:%s\n",
			temp->info.Name,temp->info.PhoneNumber);
		temp = temp->next;
	}
}

