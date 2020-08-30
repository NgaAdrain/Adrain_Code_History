//학번: 201524582
//이름: 정희석
//github id: NgaAdrain

#include <fstream>
#include <string.h>
#include <iomanip>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
#include "person.h"

int testFixText() {
	cout << "\nTesting FixedTextBuffer" << endl;
	int count = 0, select;
	char filename[20];
	Person person;
	Person *stable[10];

	FixedTextBuffer Buff(100);
	Person::InitBuffer(Buff);



	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	cin.clear();
	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> person;
				person.Print(cout);
				stable[i] = new Person(person);
			}
			break;
		case 2:
			// to display the array of Person objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];
			}
			break;
		case 3: //complete //한자 고쳐야함
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				person = *stable[i];
				person.Pack(Buff);
				Buff.Write(fostream);
				Buff.Clear();
				//작성할 코드
			}
			fostream.close();
			break;
		}
		case 4: //해결해야함!
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++) //해결해야함!
			{
				//작성할 코드
				Buff.Read(fistream);
				Buff.Print(cout);
				person.Unpack(Buff);
				cout << person;
				Buff.Clear();
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
		//*/
	}
	return 1;
}
int testLenText() {
	int count = 0, select;
	char filename[20];
	Person person;
	Person *stable[10];

	cout << "\nTesting LengthTextBuffer" << endl;
	LengthTextBuffer Buff(100);
	Person::InitBuffer(Buff);

	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	cin.clear();
	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> person;
				person.Print(cout);
				stable[i] = new Person(person);
			}
			break;
		case 2:
			// to display the array of Person objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];
			}
			break;
		case 3: //complete
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				//작성할 코드
				person = *stable[i];
				person.Pack(Buff);
				Buff.Print(cout);
				Buff.Write(fostream);
				Buff.Clear();
			}
			fostream.close();
			break;
		}
		case 4: //complete
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				//작성할 코드
				Buff.Read(fistream);
				Buff.Print(cout);
				person.Unpack(Buff);
				cout << person << endl;
				Buff.Clear();
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
		//*/
	}
	return 1;
}
int testDelText() {
	int count = 0, select;
	char filename[20];
	Person person;
	Person *stable[10];
	cout << "\nTesting DelimTextBuffer" << endl;
	DelimTextBuffer Buff;
	Person::InitBuffer(Buff);

	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);
	cin.clear();
	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> person;
				person.Print(cout);
				stable[i] = new Person(person);
			}
			break;
		case 2:
			// to display the array of Person objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];
			}
			break;
		case 3://complete
		{
			// to write the array of Person objects into a file
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				//작성할 코드
				person = *stable[i];
				person.Pack(Buff);
				Buff.Print(cout);
				Buff.Write(fostream);
				Buff.Clear();
			}
			fostream.close();
			break;
		}
		case 4: //complete
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			Person::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				//작성할 코드
				Buff.Read(fistream);
				Buff.Print(cout);
				person.Unpack(Buff);
				cout << person;
				Buff.Clear();

			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
		//*/
	}
	return 1;
}

int main(int argc, char ** argv)
{
	cout << "\nTesting Buffer" << endl;
	int select;
	cout << "\nSelect buffer type 1: Fixed Field Buffer, 2. Length Field Buffer, 3. Delim Field Buffer, 4. Quit => ";
	cin >> select;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	switch (select) {
	case 1:
		cout << "Testing Fixed Field Buffer" << endl;
		if (testFixText() == 0) cout << "***" << endl;
		break;
	case 2:
		cout << "\nTesting LengthTextBuffer" << endl;
		testLenText();
		break;
	case 3:
		cout << "\nTesting DelimTextBuffer" << endl;
		testDelText();
		break;
	default:
		break;
	}
	return 1;
}
