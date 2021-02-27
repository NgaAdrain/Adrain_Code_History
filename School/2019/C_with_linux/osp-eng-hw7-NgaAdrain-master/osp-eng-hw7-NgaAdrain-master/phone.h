// array of sturcure
# ifndef _PHONE_H_
# define _PHONE_H_

//define constants for easy to change value
# define MAX 50
# define N_MAX 10
# define PN_MAX 15
# define PSWD_MAX 10

//function declaration//
void registerPhoneData();
void print();
void printArray(void *arr, int size); 
void searchByName();
void deleteByName();
void sort();

//define type of phonebook//
typedef struct contact_st
{
    char Name[10];
    char PhoneNumber[13];
} Contact;

//define extern variable for using another files
extern Contact PhoneBook[MAX];
extern char password[PSWD_MAX];
extern int size;  // store the actual numbers of PhoneBook

#endif
