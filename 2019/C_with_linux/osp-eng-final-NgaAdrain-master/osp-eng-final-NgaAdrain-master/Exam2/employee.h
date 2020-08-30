#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#define N_MAX 20
#define PSWD_MAX 10

void registerEmp();
void printAll();
void searchByName();
void save();

typedef struct employee{
	char name[N_MAX];
	int score;
	struct employee *next;
} empNode;

typedef struct list{
	empNode *head;
	empNode *tail;
} empList;

#endif
