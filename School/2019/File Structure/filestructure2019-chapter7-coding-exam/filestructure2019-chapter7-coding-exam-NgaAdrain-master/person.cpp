//person.cc
#include "person.h"

Person::Person() { Clear(); }

Person::Person(Person &p) {
	strcpy(PID, p.PID);
	strcpy(Name, p.Name);
	strcpy(Age, p.Age);
	strcpy(City, p.City);
}
Person& Person::Out() {
	FixedFieldBuffer temp(4);
	InitBuffer(temp);
	Pack(temp);
	Person p = Person();
	p.Unpack(temp);
	return p;
}

void Person::Clear()
{
	// set each field to an empty string
	PID[0] = 0; Name[0] = 0; Age[0] = 0; City[0] = 0;
}

int Person::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer.Clear();
	numBytes = Buffer.Pack(PID);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Name);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Age);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(City);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int Person::Unpack(IOBuffer & Buffer)
{
	Clear();
	int numBytes;
	numBytes = Buffer.Unpack(PID);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Unpack(Name);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Unpack(Age);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Unpack(City);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int Person::InitBuffer(FixedFieldBuffer & Buffer)
// initialize a FixedFieldBuffer to be used for Persons
{
	int result;
	result = Buffer.AddField(13); // PID [14];
	result = result && Buffer.AddField(19); // Name [20];
	result = result && Buffer.AddField(2); // Age [3];
	result = result && Buffer.AddField(9); // City [10];
	return result;
}

int Person::InitBuffer(DelimFieldBuffer & Buffer)
// initialize a DelimFieldBuffer to be used for Persons
{
	return TRUE;
}

int Person::InitBuffer(LengthFieldBuffer & Buffer)
// initialize a LengthFieldBuffer to be used for Persons
{
	return TRUE;
}

void Person::Print(ostream & stream, char * label) const
{
	if (label == 0) stream << "Person:";
	else stream << label;
	stream << "\n\t PID '" << PID << "'\n"
		<< "\t Name '" << Name << "'\n"
		<< "\t   Age '" << Age << "'\n"
		<< "\t      City '" << City << "'\n" << flush;
}

istream& operator >> (istream &stream, Person &p) {
	cout << "Enter PID : " << flush;
	stream.getline(p.PID, 14);
	if (strlen(p.PID) == 0) return stream;
	cout << "Enter Name : " << flush; stream.getline(p.Name, 20);
	cout << "Enter Age : " << flush; stream.getline(p.Age, 3);
	cout << "Enter City : " << flush; stream.getline(p.City, 10);
	return stream;
}
//====================================//
//Student//
Student::Student() { Clear(); }

Student::Student(Student &s) {
	//Person::Person(s.Person::Out());
	strcpy(PID, s.PID);
	strcpy(Name, s.Name);
	strcpy(Age, s.Age);
	strcpy(City, s.City);
	strcpy(SID, s.SID);
	strcpy(Department, s.Department);
	strcpy(Grade, s.Grade);
}

void Student::Clear()
{
	Person::Clear();
	SID[0] = 0;//학번 12
	Department[0] = 0;//학과명 10
	Grade[0] = 0;//학년 2
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

char* Student::Key() {
	return SID;
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
