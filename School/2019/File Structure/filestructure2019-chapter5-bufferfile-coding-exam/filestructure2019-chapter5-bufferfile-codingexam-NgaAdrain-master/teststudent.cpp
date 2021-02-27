//Student.cc
#include "teststudent.h"

Student::Student() { Clear(); } //Complete

Student::Student(Student &input) {//OK
	strcpy(sname, input.sname);
	age = input.age;
	weight = input.weight;
	strcpy(Address, input.Address);
}

void Student::Clear()
{
	// set each field to an empty string
	//완성해야 함 //OK
	sname[0] = 0; age = 0; weight = 0; Address[0] = 0;
}

int Student::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	char t_age[4] = "";
	char t_weight[7] = "";
	int numBytes;
	Buffer.Clear();
	// 완성해야 함 //OK
	snprintf(t_age, 3, "%d", age);
	snprintf(t_weight, 7, "%f", weight);
	numBytes = Buffer.Pack(sname); 
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(t_age);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(t_weight);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Address);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int Student::Unpack(IOBuffer & Buffer)
{
	char t_age[4], t_weight[7];
	Clear();
	int numBytes;
	//완성해야 함 //OK
	numBytes = Buffer.Unpack(sname);
	if (numBytes == -1) return FALSE;
	sname[numBytes] = 0;
	numBytes = Buffer.Unpack(t_age);
	if (numBytes == -1) return FALSE;
	t_age[numBytes] = 0;
	age = atoi(t_age);
	numBytes = Buffer.Unpack(t_weight);
	if (numBytes == -1) return FALSE;
	t_weight[numBytes] = 0;
	weight = atof(t_weight);
	numBytes = Buffer.Unpack(Address);
	if (numBytes == -1) return FALSE;
	Address[numBytes] = 0;
	return TRUE;
}


void Student::Print(ostream & stream) const//, char * label) const
{
	//if (label == 0) 
	stream << "Student:";
	//else stream << label;
	stream << "\n\t Student Name : '" << sname << "'" << endl;
	stream << "\t Age : '" << age << "'" << endl;
//수정 필요 //OK
	stream << "\t Weight :'" << weight << "'" << endl;
	stream << "\t  Address :'" << Address << "'" << endl << flush;
}

void Student::Print(ostream & stream, char * label) const //OK
{
	if (label == 0) stream << "Student:";
	else stream << label;
	stream << "\n\t Student Name : '" << sname << "'" << endl;
	stream << "\t Age : '" << age << "'" << endl;
	//수정 필요 //OK
	stream << "\t Weight : '" << weight << "'" << endl;
	stream << "\t Address : '" << Address << "'" << endl << flush;
}

istream& operator>>(istream & stream, Student &s)
{
	//OK
	char t_age[4], t_weight[7];
	cout << "Enter Student Name : " << flush;
	stream.getline(s.sname, 40);
	if (strlen(s.sname) == 0) return stream;
	cout << "Enter Age : " << flush; stream.getline(t_age, 4);
	s.age = atoi(t_age);
	cout << "Enter Weight : " << flush; stream.getline(t_weight, 7);
	s.weight = atof(t_weight);
	cout << "Enter Address : " << flush; stream.getline(s.Address, 40);
	return stream;
	
}
ostream& operator<<(ostream & stream, Student &s)
{
	//OK
	stream << "\n\t Student Name : '" << s.sname << "'" << endl;
	stream << "\t Age : '" << s.age << "'" << endl;
	stream << "\t Weight : '" << s.weight << "'" << endl;
	stream << "\t  Address : '" << s.Address << "'" << endl << flush;
	return stream;
}