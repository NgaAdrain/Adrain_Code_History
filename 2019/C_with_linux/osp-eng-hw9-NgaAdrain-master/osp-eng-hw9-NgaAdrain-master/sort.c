#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

void sortNode();
void sort()
{
	printf("Sort fuction is called\n");
	printf("Before sorting\n");
	print();	
	sortNode();
	printf("After sorting\n");
	print();
}
//====================================================//
void sortNode(){
	Node* start;
	Node* temp;
	Node* next;
	Contact tempCont;	
	start = temp = head;
	next = head->next;
	while(start!=NULL){
		while(next!=NULL){
			if(strcmp(temp->info.Name,next->info.Name)>0){
				tempCont = temp->info;
				temp->info = next->info;
				next->info = tempCont;
			}
			temp = next;
			next = next->next;
		}
		start = start -> next;
		temp = head;
		next = temp->next;
	}
}
//============================================//
