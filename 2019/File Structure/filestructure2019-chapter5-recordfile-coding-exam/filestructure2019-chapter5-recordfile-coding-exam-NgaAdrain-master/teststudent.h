#pragma once
// Student.h
// Copyright 1997, Gregory A. Riccardi

#ifndef Student_H
#define Student_H

#include <iostream>
#include "iobuffer.h"
// Tip) ����ȯ
// int -> char*		: snprintf(����� ����, ������ ����, "%d", int ��);
// float -> char*	: snprintf(����� ����, ������ ����, "%f", float ��);
// char* -> int		: atoi(����)
// char* -> float	: atof(����)

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
