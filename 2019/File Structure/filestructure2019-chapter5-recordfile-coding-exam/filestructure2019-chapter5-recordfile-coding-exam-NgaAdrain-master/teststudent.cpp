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
	SID[0]=0;//�й� 12
	Department[0]=0;//�а��� 10
	Grade[0]=0;//�г� 2
	// set each field to an empty string
//�ϼ��ؾ� ��
}

int Student::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer.Clear();
	numBytes = Person::Pack(Buffer);
// �ϼ��ؾ� ��
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
	//�ϼ��ؾ� ��
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
	//���� �ʿ�
	Person::Print(stream);
	stream << "Student:";
	stream << "\n\t SID '" << SID << "'\n"
		<< "\t Department '" << Department << "'\n"
		<< "\t   Grade '" << Grade << "'\n";

}

istream& operator>>(istream &stream, Student &s)
{
	// ���� �ʿ�
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
	// ���� �ʿ�
	//s.Person::Print(stream);
	s.Print(stream);
	return stream;
}