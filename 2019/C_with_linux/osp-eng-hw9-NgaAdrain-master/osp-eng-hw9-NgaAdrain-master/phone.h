// array of sturcure
# ifndef _PHONE_H_
# define _PHONE_H_

//define constants for easy to change value
# define N_MAX 10
# define PN_MAX 15
# define PSWD_MAX 10

//function declaration//
void registerFromFile();
void writeToFile();
void registerPhoneData();
void print();
void searchByName();
void deleteByName();
void sort();


//define type of phonebook//
typedef struct contact_st
{
    char Name[N_MAX];
    char PhoneNumber[PN_MAX];
} Contact;

//defin type of Nodes//
typedef struct ContactNode
{
	Contact info;
	struct ContactNode *next;
} Node;

//define extern variable for using another files
//Nodes//
extern Node *PhoneBook;
extern Node *head;
extern Node *tail;
//Anothers//
extern char password[PSWD_MAX];
extern int size;  // store the actual numbers of PhoneBook

#endif
