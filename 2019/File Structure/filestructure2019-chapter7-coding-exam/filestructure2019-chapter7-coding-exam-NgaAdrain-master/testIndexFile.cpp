//학번: 201524582
//이름: 정희석
//github ID: NgaAdrain
//7장 index 생성 코딩 시험, 19.5.7
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "iobuffer.h"
#include "person.h"
#include "tindbuff.h"
#include "textind.h"
#include "indfile.h"

/*
Using class Index, the index object should be stored into the RecordFile
// Key는 SID로 대체!
*/
int main(int argc, char ** argv)
{

	char filename[20];
	int count, select, result, n, recaddr;
	Student student;
	Student *stable[10];
	FixedFieldBuffer Buff(6);
	Student::InitBuffer(Buff);

	TextIndex RecIndex(10);

	TextIndexedFile<Student> IndFile(Buff, 12, 10);
	cout << "Testing TextIndex Buffer" << endl;
	TextIndexBuffer T_Buff(12, 3, 0, 0); //=> index의 길이 : 최대 10, index의 개수 최대 3
	T_Buff.Init(2);

	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5. make index file from data file, 6. use index file for reading data file, 7. Quit => ";
		cin >> select;

		switch (select) {
		case 1:
		{
			//to store a array of TextIndex objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> student; //operator >>() should be implemented
				student.Print(cout);
				stable[i] = new Student(student);			// copy constructor should be implemented			
			}
			break;
		}
		case 2:
		{
			// to display the array of TextIndex objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];
			}
			break;
		}
		case 3:
		{
			// to write the array of TextIndex objects into a file
			T_Buff.Print(cout);//
			int result = IndFile.Create(filename, ios::out);
			cout << "Create file " << result << endl;
			if (!result)
			{
				cout << "Unable to Create file " << filename << endl;
				return -1;
			}

			for (int i = 0; i < count; i++)
			{
				IndFile.Append(*stable[i]);
				delete(stable[i]);
			}
			IndFile.Close();
			break;
		}
		case 4:
		{
			int result = IndFile.Open(filename, ios::in);
			if (result < 0)
			{
				cout << "Unable to read IndFile " << result << endl;
				return -1;
			}

			int recaddr = result;
			for (int i = 0; i < count; i++)
			{
				stable[i] = new Student;
				IndFile.Read(*stable[i]);
			}
			break;
		}
		case 5:
		{
			// make an indexed file from a Student file
			char recFilename[50] = { 0, };
			cout << endl << endl << "Input record file name : ";
			cin >> recFilename;

			int result;
			result = IndFile.Create("indfile");
			if (!result)
			{
				cout << "Unable to create indfile " << result << endl;
				return 0;
			}

			Student student;
			int recaddr = -1, count = 0;
			FixedFieldBuffer Buffer(6); // create a buffer
			RecordFile<Student> RecFile(Buffer);
			result = RecFile.Open(recFilename, ios::in);
			if (!result)
			{
				cout << "Unable to open file " << recFilename << endl;
				return 0;
			}

			cout << "Read Index from Record File \"" << recFilename << "\"" << endl;
			while (1)
			{
				recaddr = RecFile.Read(student);
				if (recaddr < 0)
					break;

				student.Unpack(Buffer);
				IndFile.Append(student);
				cout << recaddr << student << endl;
			}
			cout << "Store index table into IndFile" << endl;
			IndFile.Close();
			cout << endl;
			IndFile.Close();
			cout << "Index saved at \"indfile.ind\"" << endl << endl;

			break;
		}
		case 6:
		{
			// read RecordFile by using index file.
			int count = 0;
			char indFileName[50] = { 0, };
			char key[10] = {0,};
			cout << endl << endl << "Input record file name : ";
			cin >> indFileName;

			int result = IndFile.Open(indFileName, ios::in);
			if (result < 0)
			{
				cout << "Unable to read IndFile \"" << indFileName << "\"" << endl;
				return -1;
			}
			cout << "Input SID : ";
			cin >> key;
			cout << "select " << key << " at recaddr " << RecIndex.Search(key) << endl;
			result = IndFile.Read(key,student);
			cout << "read result: " << result << endl;
			if (result == -1) return false;
			result = student.Unpack(IndFile.GetBuffer());
			cout << result;
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
	return 0;
}
