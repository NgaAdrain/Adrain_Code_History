#include <stdio.h>
#include <string.h>
#include "employee.h"

int searchNode(char* name, empList *l);
void searchByName(empList *l){

	char temp[N_MAX];
	int c = 0;
	printf("<<Search By Name>>\n");
	printf(">> Please type name for searching:> ");
	fgets(temp,N_MAX,stdin);
	temp[strlen(temp)-1] = '\0';
	c = searchNode(temp,l);
	if(!c)
		printf("Opps! %s in not in the Employee List!\n",temp);

}

int searchNode(char* name, empList *l){
	empNode* temp = l->head;
	int check = 0;
	while(temp!=NULL){
		check = strcmp(name,temp->name);
		if(check != 0){
			temp = temp->next;
		}
		else{
			printf("EmpName: %s is found\n",name);
			printf("[Name:%s score:%d]\n",temp->name,temp->score);
			break;
		}
	}
	if(check!=0) return 0;
	else return 1;
}

