#pragma once
// Student.h
// Copyright 1997, Gregory A. Riccardi

#ifndef Student_H
#define Student_H

#include <iostream>
#include "iobuffer.h"
// Tip) 형변환
// int -> char*		: snprintf(저장될 변수, 버퍼의 길이, "%d", int 값);
// float -> char*	: snprintf(저장될 변수, 버퍼의 길이, "%f", float 값);
// char* -> int		: atoi(변수)
// char* -> float	: atof(변수)

class Student
{
public:
	// fields
	char sname[40];
	int age;
	float weight;
	char Address[40];
	//operations
	Student();
	Student(Student &);
	void Clear();
	int Unpack(IOBuffer &);
	int Pack(IOBuffer &) const;
	void Print(ostream &);
	friend istream& operator>>(istream &, Student &);
	friend ostream& operator<<(ostream &, Student &);
};

#endif
