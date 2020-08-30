#include "recording.h"
#include <fstream>
#include <iomanip>
#include <string>
#include "iobuffer.h"
#include "fixfld.h"
#include "length.h"
#include "buffile.h"
#include "recfile.h"
#include "indbuff.h"
#include <iostream>
using namespace std;
//학번: 201524582
//이름:	정희석
//github id: NgaAdrain
/*
template은  **.h와 **.cpp를 분리하지 않고 **.h로 합쳐야 link error를 해결
buffile.cpp의 open(0, create()의 mode 설정 변경
coding exam: data file은 entry-sequenced file로서 append, Key(record)에 대하여b-tree에 insert하는 프로그램 구현
	Student student;
	FixedFieldBuffer Buff(6);
	Student::InitBuffer(Buff);
	Recorde<Student> rFile(Buffer, 12, 10);
	int result = rFile.Create(filename, ios::out);
	cout << "Create file " << result << endl;
	if (!result)
	{
		cout << "Unable to Create file " << filename << endl;
		return -1;
	}
	rFile.Append(*stable[i]);
	rFile.Close();

*/
const int BTreeSize = 4;
int main(int argc, char ** argv)
{
	int count, select, resultFile, resultIndex;
	char removeKey;
	Recording record;
	FixedFieldBuffer Buffer(10);
	Buffer.InitFields(); // Add each field size of record to buffer (can change if you need)
	RecordFile<Recording> DataFile(Buffer);

	resultFile = DataFile.Create("datafile.dat", ios::out | ios::in);
	cout << "Create file " << resultFile << endl;
	if (!resultFile)
	{
		cout << "Unable to Create file : datafile.dat" << endl;
		return 0;
	}
	BTree <char> bt(BTreeSize);

	resultIndex = bt.Create("btree.dat", ios::out | ios::in);
	if (!resultIndex) {
		cout << "Unable to Create file btree.dat" << endl;
		return 0;
	}
	Recording * R[10];
	R[0] = new Recording("LON", "2312", "Romeo and Juliet", "Prokofiev", "Maazel");
	R[1] = new Recording("RCA", "2626", "Quartet in C Sharp Minor", "Beethoven", "Julliard");
	R[2] = new Recording("WAR", "23699", "Touchstone", "Corea", "Corea");
	R[3] = new Recording("ANG", "3795", "Symphony No. 9", "Beethoven", "Giulini");
	R[4] = new Recording("COL", "38358", "Nebraska", "Springsteen", "Springsteen");
	R[5] = new Recording("DG", "18807", "Symphony No. 9", "Beethoven", "Karajan");
	R[6] = new Recording("MER", "75016", "Coq d'or Suite", "Rimsky-Korsakov", "Leinsdorf");
	R[7] = new Recording("BOL", "31809", "Symphony No. 9", "Dvorak", "Bernstein");
	R[8] = new Recording("EG", "139201", "Violin Concerto", "Beethoven", "Ferras");
	R[9] = new Recording("FF", "245", "Good News", "Sweet Honey in the Rock", "Sweet Honey in the Rock");
	int recaddr;
	while (1)
	{
		cout << "\nSelect command 1: insert record set, 2. delete a record, 3. print the record set, 4. print sorted records with key, 5. Quit => ";
		cin >> select;

		switch (select) {
		case 1://input data record set //정상작동
			cout << "1. insert the record set" << endl;
			for (int i = 0; i < 10; i++)
			{
				R[i]->Print(cout);
				R[i]->Pack(Buffer);
				recaddr = DataFile.Write(*R[i]);
				cout << "DataFile R[" << i << "] at recaddr " << recaddr << endl;
				char k = R[i]->Key();
				cout << "Inserting with key = " << k << endl;
				int result = bt.Insert(k, recaddr);//1 block = 4 records
				bt.Print(cout);
				delete R[i];
			}
			DataFile.Close();
			bt.Close();
			break;
		case 2://2. delete a record
			resultFile = DataFile.Create("datafile.dat", ios::out );//탈출 => fileclose안됬었음 -> 해결
			if (!resultFile)
			{
				cout << "Unable to open data file" << endl;
				return 0;
			}
			resultIndex = bt.Create("btree.dat", ios::out );//탈출 => fileclose안됬었음 -> 해결
			if (!resultIndex)
			{
				cout << "Unable to open btree file" << endl;
				return 0;
			}
			cout << "2. delete a record with key = ";
			cin >> removeKey;
			cout << endl << "removeKey = " << removeKey << endl;
			if (bt.Search(removeKey, recaddr))
			{
				//2nd
				DataFile.Write(recaddr);//need to debug
				bt.Remove(removeKey);
			}
			DataFile.Close();
			bt.Close();
			break;
		case 3://3. print the record set
			resultFile = DataFile.Open("datafile.dat", ios::in);//탈출 => fileclose안됬었음 -> 해결
			if (!resultFile)
			{
				cout << "Unable to open data file" << endl;
				return 0;
			}
			Recording *rec;
			for (int i = 0; i < 10; i++)
			{
				rec = new Recording;
				//수정...recaddr이 바뀌어야함//
				DataFile.Read(*rec, recaddr);
				rec->Print(cout);
			}
			DataFile.Close();
			break;
		case 4://4. print sorted records with key
			resultFile = DataFile.Create("datafile.dat", ios::out);//탈출 => fileclose안됬었음 -> 해결
			if (!resultFile)
			{
				cout << "Unable to open data file" << endl;
				return 0;
			}
			resultIndex = bt.Create("btree.dat", ios::out);//탈출 => fileclose안됬었음 -> 해결
			if (!resultIndex)
			{
				cout << "Unable to open btree file" << endl;
				return 0;
			}
			//in-order traversal printing of data records
			bt.InOrderTraversal(cout);
			//How to read data record by sequence with key
			DataFile.Close();
			bt.Close();
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 1;
}
