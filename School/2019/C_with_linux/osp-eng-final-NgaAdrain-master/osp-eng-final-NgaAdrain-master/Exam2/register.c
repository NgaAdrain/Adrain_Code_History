#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

void initialization(empNode n, empList* l);
void addNode(empNode n, empList* l);

void registerEmp(empList* l){
	empNode temp;
	printf("<< Register a new employee >> \n");
	printf(">> Please type name and score (ex: IronMan 100)>");
	scanf("%s %d",temp.name, &temp.score);
	getchar();
	if(l->head == NULL)
		initialization(temp,l);
	else
		addNode(temp,l);
	printf("Registered...\n");
}

void initialization(empNode n, empList *l){
	l->head = (empNode*) malloc(sizeof(empNode));
	l->tail = l->head;
	l->tail->score = n.score;
	strcpy(l->tail->name,n.name);	
	l->head->next = NULL;
}

void addNode(empNode n, empList *l){
	l->tail->next = (empNode*) malloc(sizeof(empNode));
	l->tail = l->tail->next;
	l->tail->score = n.score;
	strcpy(l->tail->name,n.name);
	l->tail->next = NULL;
}

