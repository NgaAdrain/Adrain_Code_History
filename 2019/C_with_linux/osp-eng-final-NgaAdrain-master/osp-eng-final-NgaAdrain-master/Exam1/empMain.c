#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

char password[PSWD_MAX];

void (* pFuncs[4])()={registerEmp,printAll,searchByName,save};

int displayMenu();

int main(void){
	char input_pass[PSWD_MAX];	
	int service = 0;	
	int trial = 0;
	printf("Regist Your Password : ");
	fgets(password,PSWD_MAX,stdin);	
	printf("Welcome! Employee Management Program\n");
	printf("Insert Your Password : ");
	fgets(input_pass,PSWD_MAX,stdin);
	if(strcmp(input_pass,password)){
		trial++;
		printf(">> Not Matched!! \n");
		printf("password : ");
		fgets(input_pass,PSWD_MAX,stdin);
		while((trial<4)&&(strcmp(input_pass,password))){
			switch(trial){
				case 2:
					printf(">> Not Matched(twice)!!! \n");
					printf("password : ");
					fgets(input_pass,PSWD_MAX,stdin);
					break;
				case 3:
					printf(">> Not Matched(3times)!!! \n");
					printf("password : ");
					fgets(input_pass,PSWD_MAX,stdin);
					break;
				}
				trial++;
			}
		if(trial==4){
			printf(">> You are not allowed to access EMS.\n");
			return 1;
		}
	}
	trial = 0;
	do{
		service = displayMenu();
		if(service > 0 && service <= 4)
			pFuncs[service-1]();
		else if(service == 0 || service >5)
			printf("You choose a wrong service number\n");
	}while(service !=5);
	printf("Thanks for Using! Bye Bye! \n");
	return 0;
}
int displayMenu(){
	int service = 0;
	printf("============ Employee Management ============\n");
	printf("<<<1. Register\t 2. Print All \t 3. Search \t 4. Save \t 5. Exit>>>\n");
	printf("Please enter your service number (1-5)> ");
	scanf("%d", &service);
	getchar();
	return service;	
}

