// 학번: 201524582
// 이름: 정희석
// Github ID: NgaAdrain
// 19.4.30 Test coding exam about recordFile and Header
// Use class RecordFile, ReadHeader(), WriteHeader()
// person.h에 정의된 class Student : public Person 를 사용하여 record  file에 저장한다.
#include "recfile.h"
#include "buffile.h"
#include "fixfld.h"
#include "person.h"
int main(int argc, char ** argv)
{
	cout << "\nTesting Header Record" << endl;
	int count, select, result, n, recaddr;
	char filename[20];
	Student student;
	Student *stable[10];
	FixedFieldBuffer Buff(7);
	Student::InitBuffer(Buff);
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5. direct read from file, 6. Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Student objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> student;
				student.Print(cout);
				stable[i] = new Student(student);
			}// copy constructor should be implemented			}
				break;
		case 2:
			// to display the array of Student objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];// operator<< (operator overloading) should be implemented
			}
			break;
		case 3:
		{
			// to write the array of Student objects into a file
			RecordFile<Student> TestOut(Buff);
			result = TestOut.Create(filename, ios::out);
			cout << "Create file " << result << endl;
			if (!result)
			{
				cout << "Unable to Create file " << filename << endl;
				return 1;
			}

			recaddr = TestOut.Write(*stable[0]);
			stable[0]->Print(cout);
			for (int i = 1; i < count; i++)
			{
				stable[i]->Print(cout);
				recaddr = TestOut.Write(*stable[i]);
				cout << "write at " << recaddr << endl;
				delete(stable[i]);//return the object created by new()
			}
			//int n = TestOut.WriteHeader();//protected 이므로 RecordFile에서 호출
			break;
		}
		case 4:
		{
			// to read the array of Student records from the file
			RecordFile<Student> TestIn(Buff);
			TestIn.Open(filename, ios::in);
			//int n = TestOut.ReadHeader();//protected 이므로 RecordFile에서 호출
			//numRecords = extractHeader();// should extract the number of records from header string
			
			Student::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				stable[i] = new Student();
				TestIn.Read(*stable[i], recaddr);
				stable[i]->Print(cout);
			}
			if (result == -1) cout << "Read past end of file! Error." << endl;
			else cout << "Read past end of file failed! Correct." << endl;

			break;
		}
		case 5://Direct read from file
		{
			/*
			RecordFile<Student> TestOut(Buff);
			result = TestOut.Open(filename, ios::in);
			///int n = TestOut.ReadHeader();//protected 이므로 RecordFile에서 호출
			cout << "read header " << result << endl;
			int RRN;
			cin >> RRN;
			Buff.DRead(TestIn, RRN);
			student.Unpack(Buff);
			student.Print(cout, "First record:");
			cin >> RRN;
			Buff.DRead(TestIn, RRN);
			student.Unpack(Buff);
			student.Print(cout, "Second record:");
			*/
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