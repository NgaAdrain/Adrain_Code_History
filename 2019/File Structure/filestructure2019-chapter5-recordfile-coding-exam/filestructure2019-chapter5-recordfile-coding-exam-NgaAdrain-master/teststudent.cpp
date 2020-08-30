//Student.cc
#include "person.h"

Student::Student() { Clear(); }

Student::Student(Student &s) {
	Person p = Person(s.Person::Out());
	Person::Person(p);
	strcpy(SID, s.SID);
	strcpy(Department, s.Department);
	strcpy(Grade, s.Grade);
}

void Student::Clear()
{
	Person::Clear();
	SID[0]=0;//학번 12
	Department[0]=0;//학과명 10
	Grade[0]=0;//학년 2
	// set each field to an empty string
//완성해야 함
}

int Student::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer.Clear();
	numBytes = Person::Pack(Buffer);
// 완성해야 함
	numBytes = Buffer.Pack(SID);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Department);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Grade);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int Student::Unpack(IOBuffer & Buffer)
{
	Clear();
	int numBytes;
	numBytes = Person::Unpack(Buffer);
	//완성해야 함
	numBytes = Buffer.Unpack(SID);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Unpack(Department);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Unpack(Grade);
	if (numBytes == -1) return FALSE;
	return TRUE;
}


void Student::Print(ostream & stream) const
{
	//수정 필요
	Person::Print(stream);
	stream << "Student:";
	stream << "\n\t SID '" << SID << "'\n"
		<< "\t Department '" << Department << "'\n"
		<< "\t   Grade '" << Grade << "'\n";

}

istream& operator>>(istream &stream, Student &s)
{
	// 구현 필요
	Person p;
	cin >> p;
	s.Person::Person(p);
	cout << "Enter Student ID : " << flush;
	stream.getline(s.SID, 12);
	if (strlen(s.SID) == 0) return stream;
	cout << "Enter Department : " << flush;
	stream.getline(s.Department, 10);
	cout << "Enter Grade : " << flush;
	stream.getline(s.Grade, 2);
}
ostream& operator<<(ostream &stream, Student &s)
{
	// 구현 필요
	//s.Person::Print(stream);
	s.Print(stream);
	return stream;
}