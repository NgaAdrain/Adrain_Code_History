#include <stdio.h>
#include "phone.h"

//variables//
static int count_service = 0;	// Total number of service requests
int size = 0;
char password[PSWD_MAX];
Contact PhoneBook[MAX];

//function pointers array//
void (* pFuncs[5])()={registerPhoneData, print, searchByName, deleteByName, sort};

//main function//
int main()
{
	int service;		// a variable for storing user's request
	printf("regist your passward(to 10 charactor) : ");
	fgets(password,PSWD_MAX,stdin);
	do
	{
        printf("============ Telephone Book Management ============");
        printf("\n <<<1. Register\t 2. Print All \t 3. Search by ID \t 4. Delete \t 5. Sort \t 6. Exit >>>\n");
        printf(" Please enter your service number (1-6)> ");
		scanf("%d", &service);
		getchar(); //flush "\n"
		if ( service > 0 && service <= 5 )
		{
			pFuncs[service-1]();
		}
		else if( service ==0 || service > 6)
		{
			printf("You choose a wrong service number\n");
		}
		count_service++;
	} while (service != 6);	// if Exit is not entered, the loop continues
	printf("Thanks for Using! Bye Bye!\n");	
	return 0;
}

//========================================================================//
