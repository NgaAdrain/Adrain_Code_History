#include <stdio.h>
#include <string.h>
#include "phone.h" 

void printAll(){
	printf("<<Print all contents in the PhoneBook>>\n");
	for(int x = 0; x < size; x++){
		if(strlen(PhoneBook[x].Name)>6)	//control line tab's
			printf("%s \t %s \n",PhoneBook[x].Name,PhoneBook[x].PhoneNumber);
		else	
			printf("%s \t\t %s \n",PhoneBook[x].Name,PhoneBook[x].PhoneNumber);
	}
}


