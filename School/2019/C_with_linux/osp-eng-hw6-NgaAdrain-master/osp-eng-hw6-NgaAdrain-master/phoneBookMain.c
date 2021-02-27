#include <stdio.h>
#include "service.h"

static int count_service = 0;	// Total number of service requests
int size = 0;			//global variable
PB PhoneBook[MAX];		//global variable
char password[PSWD_MAX];//global variable by phone.h's extern

int main()
{
	int service;		// a variable for storing user's request
	printf("regist your passward(to 10 charactor) : ");
	fgets(password,PSWD_MAX,stdin);
	do
	{
        printf("============ Telephone Book Management ============");
		printf("\n <<<1. Register\t 2. Print All \t 3. Search \t 4. Delete \t 5. Exit >>>\n");
        printf(" Please enter your service number (1-5)> ");
		scanf("%d", &service);
		getchar();
		switch(service)
		{
			case 1: registerPhoneData(); break;	// invoke find_ID
			case 2: printAll(); break;
            case 3: searchByName(); break;
            case 4: deleteByName(); break;
			case 5: break;
			default : printf("You got wrong Number!\n"); break;	
		}
		count_service++;
	} while (service != 5);	// if Exit is not entered, the loop continues
	return 0;
}

