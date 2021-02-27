#include <stdio.h>
#include <string.h>
#include "phone.h"

typedef int (*chk)();	//define type of function pointer
static int try = 0;
static int checkPassword();

//register function//
void registerPhoneData(){
	chk chkpass = checkPassword; //do not need to use // but practicing
	printf("Registration\n");
	int check = chkpass(); //check == 0 no problem
	if(check) return;			 //check == 1 can't access 
	printf("New User Name: ");
	fgets(PhoneBook[size].Name,N_MAX,stdin); 	//contain \n
	PhoneBook[size].Name[strlen(PhoneBook[size].Name)-1]='\0';//delete \n
	printf("PhoneNumber : ");
	fgets(PhoneBook[size].PhoneNumber,PN_MAX,stdin);
	PhoneBook[size].PhoneNumber[strlen(PhoneBook[size].PhoneNumber)-1]='\0';//
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
