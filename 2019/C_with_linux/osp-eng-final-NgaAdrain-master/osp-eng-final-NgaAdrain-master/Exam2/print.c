#include <stdio.h>
#include "employee.h"

void printNode(empList *l);
void printAll(empList *l){
	printf("<<Display all employees>>\n");
	printNode(l);
}

void printNode(empList *l){
	empNode* temp = l->head;
	while(temp != NULL){
		printf("[Name:%s score:%d]",temp->name,temp->score);
		temp = temp->next;
		if(temp != l->tail)
			printf("-->");	
		else{
			printf("[Name:%s score:%d]",temp->name,temp->score);
			temp = temp->next;
			}
	}
	printf("\n");
}

