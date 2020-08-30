//person.cc
// Copyright 1997, Gregory A. Riccardi
// Tip) 형변환
// int -> char*		: snprintf(저장될 변수, 버퍼의 길이, "%d", int 값);
// float -> char*	: snprintf(저장될 변수, 버퍼의 길이, "%f", float 값);
// char* -> int		: atoi(변수)
// char* -> float	: atof(변수)
#include "person.h"

Person::Person ()
{
	Clear ();
	//char Name[20];
	//int age;//3자리
	//float weight;// 소수점 2째자리까지 5자리
	//char Address[40];
	//char ZipCode[5];
}
Person::Person(Person &s) //complete
{
//
	strncpy(Name, s.Name, 20);
	age = s.age;
	weight = s.weight;
	strncpy(Address, s.Address, 40);
	strncpy(ZipCode, s.ZipCode, 5);
}
istream& operator>> (istream &stream, Person &s) //Complete //this operator for user input & not for file input
{
//
	char temp[7];
	cout << "Enter Name : " << flush;
	stream.getline(s.Name, 20);
	if (strlen(s.Name) == 0) return stream;
	cout << "Enter Age : " << flush; stream >> s.age; stream.clear(); stream.ignore(INT_MAX, '\n');
	cout << "Enter Weight : " << flush; stream.getline(temp, 7); s.weight = atof(temp);
	cout << "Enter Address : " << flush; stream.getline(s.Address, 40);
	cout << "Enter ZipCode : " << flush; stream.getline(s.ZipCode, 5);
	return stream;
}

ostream& operator<< (ostream &stream, Person &s)//complete //this operator for display & not for file output
{
//
	stream << "<information of " << s.Name << ">" << endl;
	stream << "=========================" << endl;
	stream << "Name : " << s.Name << endl;
	stream << "Age : " << s.age << endl;
	stream << "Weight : " << s.weight << endl;
	stream << "Address : " << s.Address << endl;
	stream << "Zipcode : " << s.ZipCode << endl;
	stream << "=========================" << endl;
	return stream;
}
void Person::Clear ()//complete
{
	// set each field to an empty string
	Name [0] = 0;
	age = 0;
	weight = 0;
	Address [0] = 0;
	ZipCode [0] = 0;
}

int Person::Pack (FixedTextBuffer & Buffer) const//complete
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	char temp_weight[7], temp_age[4];
	snprintf(temp_age, 4, "%d", age);
	snprintf(temp_weight, 7, "%.2f", weight);
	Buffer . Clear ();
	result = Buffer . Pack (Name);
	result = result && Buffer . Pack (temp_age);
	result = result && Buffer . Pack (temp_weight);
	result = result && Buffer . Pack (Address);
	result = result && Buffer . Pack (ZipCode);
	return result;
}

int Person::Unpack (FixedTextBuffer & Buffer)//complete
{
	Clear(); 
	int result;
	char temp_weight[7], temp_age[4];
	result = Buffer . Unpack (Name);
	result = result && Buffer . Unpack (temp_age);
	age = atoi(temp_age);
	result = result && Buffer . Unpack (temp_weight);
	weight = atof(temp_weight);
	result = result && Buffer . Unpack (Address);
	result = result && Buffer . Unpack (ZipCode);
	return result;
}

int Person::InitBuffer (FixedTextBuffer & Buffer) //compete
// initialize a FixedTextBuffer to be used for Persons
{
	int result;
	Buffer.Reset();
	result = Buffer . AddField (19); // LastName [20];
	result = result && Buffer . AddField (3); // Age [4];
	result = result && Buffer.AddField(6); // Weight [7];
	result = result && Buffer . AddField (39); // Address [40];
	result = result && Buffer . AddField (4); // ZipCode [5];
	return result;
}

int Person::Pack (LengthTextBuffer & Buffer) const//complete
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	char temp_weight[7], temp_age[4];
	snprintf(temp_age, 4, "%d", age);
	snprintf(temp_weight, 7, "%.2f", weight);
	Buffer.Clear();
	result = Buffer.Pack(Name);
	result = result && Buffer.Pack(temp_age);
	result = result && Buffer.Pack(temp_weight);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(ZipCode);
	return result;
}

int Person::Unpack (LengthTextBuffer & Buffer)//complete
{
	Clear();
	int result;
	char temp_weight[7], temp_age[4];
	result = Buffer.Unpack(Name);
	result = result && Buffer.Unpack(temp_age);
	age = atoi(temp_age);
	result = result && Buffer.Unpack(temp_weight);
	weight = atof(temp_weight);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(ZipCode);
	return result;
}

int Person::InitBuffer (LengthTextBuffer & Buffer)
// initialize a LengthTextBuffer to be used for Persons
{
	return TRUE;
}

int Person::Pack (DelimTextBuffer & Buffer) const //complete
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	char temp_weight[7], temp_age[4];
	snprintf(temp_age, 4, "%d", age);
	snprintf(temp_weight, 7, "%.2f", weight);
	Buffer.Clear();
	result = Buffer.Pack(Name);
	result = result && Buffer.Pack(temp_age);
	result = result && Buffer.Pack(temp_weight);
	result = result && Buffer.Pack(Address);
	result = result && Buffer.Pack(ZipCode);
	return result;
}

int Person::Unpack (DelimTextBuffer & Buffer)//complete
{
	Clear();
	int result;
	char temp_weight[7], temp_age[4];
	result = Buffer.Unpack(Name);
	result = result && Buffer.Unpack(temp_age);
	age = atoi(temp_age);
	result = result && Buffer.Unpack(temp_weight);
	weight = atof(temp_weight);
	result = result && Buffer.Unpack(Address);
	result = result && Buffer.Unpack(ZipCode);
	return result;
}

int Person::InitBuffer (DelimTextBuffer & Buffer)
// initialize a DelimTextBuffer to be used for Persons
{
	return TRUE;
}

void Person::Print (ostream & stream) //complete
{
	stream << "Person:"
		<< "\t      Name '"<<Name<<"'\n"
		<< "\t       Age '"<<age<<"'\n"
		<< "\t    Weight '"<<weight<<"'\n"
		<< "\t   Address '"<<Address<< "'\n"
		<< "\t  Zip Code '"<<ZipCode<<"'\n" <<flush;
}



