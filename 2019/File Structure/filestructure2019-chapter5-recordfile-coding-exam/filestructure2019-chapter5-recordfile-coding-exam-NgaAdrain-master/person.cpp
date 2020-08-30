//person.cc
#include "person.h"

Person::Person (){Clear ();}

Person::Person(Person &p) {
	strcpy(PID, p.PID);
	strcpy(Name, p.Name);
	strcpy(Age, p.Age);
	strcpy(City, p.City);
}
Person Person::Out() {
	FixedFieldBuffer temp(4);
	InitBuffer(temp);
	Pack(temp);
	Person p = Person();
	p.Unpack(temp);
	return p;
}

void Person::Clear ()
{
	// set each field to an empty string
	PID[0] = 0; Name[0] = 0; Age[0] = 0; City [0] = 0;
}

int Person::Pack (IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	Buffer . Clear ();
	numBytes = Buffer . Pack (PID);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (Name);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (Age);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Pack (City);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int Person::Unpack (IOBuffer & Buffer)
{
	Clear ();
	int numBytes;
	numBytes = Buffer . Unpack (PID);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Unpack (Name);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Unpack (Age);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer . Unpack (City);
	if (numBytes == -1) return FALSE;
	return TRUE;
}

int Person::InitBuffer (FixedFieldBuffer & Buffer)
// initialize a FixedFieldBuffer to be used for Persons
{
	int result;
	result = Buffer . AddField (13); // PID [14];
	result = result && Buffer . AddField (19); // Name [20];
	result = result && Buffer . AddField (2); // Age [3];
	result = result && Buffer . AddField (9); // City [10];
	return result;
}

int Person::InitBuffer (DelimFieldBuffer & Buffer)
// initialize a DelimFieldBuffer to be used for Persons
{	return TRUE;}

int Person::InitBuffer (LengthFieldBuffer & Buffer)
// initialize a LengthFieldBuffer to be used for Persons
{	return TRUE;}

void Person::Print (ostream & stream, char * label) const
{
	if (label == 0) stream << "Person:";
	else stream << label;
	stream << "\n\t PID '"<<PID<<"'\n"
		<< "\t Name '"<<Name<<"'\n"
		<< "\t   Age '"<<Age<<"'\n"
		<< "\t      City '"<<City<<"'\n"<<flush;
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
