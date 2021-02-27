// person.h
// Copyright 1997, Gregory A. Riccardi

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
// Tip) ����ȯ
// int -> char*		: snprintf(����� ����, ������ ����, "%d", int ��);
// float -> char*	: snprintf(����� ����, ������ ����, "%f", float ��);
// char* -> int		: atoi(����)
// char* -> float	: atof(����)

class Person  //complete
{
  public:
	// fields
	char Name[20];
	int age; //3�ڸ�
	float weight; // �Ҽ��� 2°�ڸ����� 5�ڸ�
	char Address [40];
	char ZipCode [5];
	//operations
	Person ();
	Person(Person &);
	void Clear ();
	static int InitBuffer (FixedTextBuffer &);
	int Unpack (FixedTextBuffer &);
	int Pack (FixedTextBuffer &) const;
	static int InitBuffer (LengthTextBuffer &);
	int Unpack (LengthTextBuffer &);
	int Pack (LengthTextBuffer &) const;
	static int InitBuffer (DelimTextBuffer &);
	int Unpack (DelimTextBuffer &);
	int Pack (DelimTextBuffer &) const;
	void Print (ostream &);
	friend istream& operator>>(istream &, Person &);
	friend ostream& operator<<(ostream &, Person &);
};

#endif
