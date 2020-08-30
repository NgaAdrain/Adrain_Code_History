// person.h
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "fixfld.h"
#include "length.h"
#include "delim.h"
using namespace std;

class Person 
{
private: 
	// fields
	char PID[14];//�ֹι�ȣ
	char Name [20];//�̸�
	char Age [3];
	char City[10];
public:
	//operations
	Person ();
	Person(Person&);
	Person Out();
	static int InitBuffer (DelimFieldBuffer &);
	static int InitBuffer (LengthFieldBuffer &);
	static int InitBuffer (FixedFieldBuffer &);
	void Clear ();
	int Unpack (IOBuffer &);
	int Pack (IOBuffer &) const;
	void Print (ostream &, char * label = 0) const;
	friend istream& operator>>(istream &stream, Person &p);
};

class Student : public Person {
private:
	char SID[12];//�й�
	char Department[10];//�а���
	char Grade[2];//�г�
public:
	Student();
	Student(Student &input);
	void Clear();
	int Pack(IOBuffer &Buffer) const;
	int Unpack(IOBuffer &Buffer);
	void Print(ostream &) const;

	friend ostream& operator<<(ostream &stream, Student &s);
	friend istream& operator>>(istream &stream, Student &s);
	// �Լ� �߰��� �� 
};
#endif
