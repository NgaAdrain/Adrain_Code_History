// person.h
// Copyright 1997, Gregory A. Riccardi

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
// Tip) 형변환
// int -> char*		: snprintf(저장될 변수, 버퍼의 길이, "%d", int 값);
// float -> char*	: snprintf(저장될 변수, 버퍼의 길이, "%f", float 값);
// char* -> int		: atoi(변수)
// char* -> float	: atof(변수)

class Person  //complete
{
  public:
	// fields
	char Name[20];
	int age; //3자리
	float weight; // 소수점 2째자리까지 5자리
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
