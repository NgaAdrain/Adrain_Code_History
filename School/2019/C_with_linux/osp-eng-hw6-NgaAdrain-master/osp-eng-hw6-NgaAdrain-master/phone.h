// array of sturcure
#ifndef _PHONE_H_
#define _PHONE_H_

# define MAX 50
# define N_MAX 10
# define PN_MAX 15			//include \n & \0 // can save maximum 13
# define PSWD_MAX 10
typedef struct Contact
{
    char Name[N_MAX];
    char PhoneNumber[PN_MAX];
}PB;

extern PB PhoneBook[MAX]; //phonebook can store maximum 50 PB
extern char password[PSWD_MAX]; //use for phoneBookregistration
extern int size;  // store the actual numbers of PhoneBook

#endif
