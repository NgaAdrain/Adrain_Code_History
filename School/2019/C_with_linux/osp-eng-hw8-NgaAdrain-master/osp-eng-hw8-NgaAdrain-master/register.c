#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

typedef int (*chk)();	//define type of function pointer
static int try = 0;
static int checkPassword();
void initialization(Contact info);
void addNode(Contact info);

//register function//
void registerPhoneData(){
	Contact temp;
	chk chkpass = checkPassword; //do not need to use // but practicing
	printf("Registration\n");
	int check = chkpass(); //check == 0 no problem
	if(check) return;			 //check == 1 can't access 
	printf("New User Name: ");
	fgets(temp.Name,N_MAX,stdin); 	//contain \n
	temp.Name[strlen(temp.Name)-1]='\0';//delete \n
	printf("PhoneNumber : ");
	fgets(temp.PhoneNumber,PN_MAX,stdin);
	temp.PhoneNumber[strlen(temp.PhoneNumber)-1]='\0';//
	if(PhoneBook == NULL)
		initialization(temp);	
	else
		addNode(temp);	
	size++;
	printf("Registered...\n");
}

//checking password function//
int checkPassword(){
	char temp[PSWD_MAX];	
	printf("type your password(to 10 charactor)");
	printf("password : ");
	fgets(temp,PSWD_MAX,stdin);
	if(strcmp(temp,password)){
		try++;
		printf(">> Not Matched!!! \n");
		printf("password : ");
		fgets(temp,PSWD_MAX,stdin);
		while((try<4)&&(strcmp(temp,password))){
			switch(try){
			case 2:
				printf(">> Not Matched(twice)!!! \n");
				printf("password : ");
				fgets(temp,PSWD_MAX,stdin);
				break;
			case 3:
				printf(">> Not Matched(third)!!! \n");
				printf("password : ");
				fgets(temp,PSWD_MAX,stdin);
				break;
			}
			try++;
		}
		if(try==4){ 
			printf(">> Your are not allow to access PhoneBook.\n");
			return 1;	
		}
	}
	try = 0;
	return 0;
}
//initialization function//
void initialization(Contact input){
	PhoneBook = (Node*) malloc(sizeof(Node));
	PhoneBook->info = input;
	PhoneBook->next = NULL;
	head = tail = PhoneBook;
}
//Node Append function//
void addNode(Contact info){
	tail->next = (Node*) malloc(sizeof(Node));
	tail = tail->next;
	tail->info = info;
	tail->next = NULL;
}
