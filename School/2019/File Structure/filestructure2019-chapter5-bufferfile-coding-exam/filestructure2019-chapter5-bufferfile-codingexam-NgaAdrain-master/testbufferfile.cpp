//학번: 201524582
//이름: 정희석
//github id: NgaAdrain
#include "teststudent.h"
#include "buffile.h"
#include "length.h"

int main(int argc, char ** argv)
{
	cout << "\nTesting FixedTextBuffer" << endl;
	int count, select;
	char filename[20];
	Student student;
	Student *stable[10];
	cout << "\nTesting LengthTextBuffer" << endl;
	LengthFieldBuffer Buff;
	int result;
	int recaddr;
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1://Complete
			//to store a array of Student objects by inputing
			cout << "the number of Student object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> student;//OK
				student.Print(cout); //OK
				stable[i] = new Student(student);			// copy constructor should be implemented			}
			}
				break;
		case 2: //complete
			// to display the array of Student objects into screen  
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];// operator<< (operator overloading) should be implemented
			}	//OK
			break;
		case 3:
		{
			// to write the array of Student objects into a file
			//Buff . Print (cout);
			//student = *stable[0];
			//student.Pack(Buff);
			BufferFile TestOut(Buff);
			result = TestOut.Create(filename, ios::out);
			cout << "create file " << result << endl;
			if (!result)
			{
				cout << "Unable to create file " << filename << endl;
			}
			TestOut.Close();
			result = TestOut.Open(filename, ios::out);
			cout << "open file " << result << endl;
			if (!result)
			{
				cout << "Unable to open file " << filename << endl;
				return 1;
			}
			//}
			//Buff . Print (cout);
			recaddr = TestOut.Write();
			cout << "write at " << recaddr << endl;
			for (int i = 0; i < count; i++)
			{
				stable[i]->Print(cout);
				stable[i]->Pack(Buff);
				TestOut.Rewind();
				recaddr = TestOut.Append();
				cout << "Student R[" << i << "] at recaddr " << recaddr << endl;
				delete(stable[i]);//return the object created by new()
			}
			TestOut.Close();
			break;
		}
		case 4://Complete
		{
			// to read the array of Student records from the file
			BufferFile TestIn(Buff);
			TestIn.Open(filename, ios::in);
			recaddr = -1;
			//result = TestIn . ReadHeader ();
			//cout <<"read header "<<result<<endl;
			TestIn.Read(recaddr);
			student.Unpack(Buff);//OK
			student.Print(cout, "First record(Empty):");//OK
			for (int i = 0; i < count; i++)
			{
				stable[i] = new Student();
				recaddr = TestIn.Read();
				stable[i]->Unpack(Buff);
				stable[i]->Print(cout);
			}
			TestIn.Close();
			if (result != -1) cout << "Read past end of file! Error." << endl;
			else cout << "Read past end of file failed! Correct." << endl;
			break;
		}
		case 5:
			// others
			cout << "Bye Bye~" << endl;
			exit(0);
			break;
		default:
			cout << "You got wrong Command!" << endl;
			break;
		}
	}
	return 1;
}
