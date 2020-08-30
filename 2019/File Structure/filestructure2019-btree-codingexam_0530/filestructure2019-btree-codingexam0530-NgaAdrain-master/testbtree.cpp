#include <iostream>
#include <string>
#include "btree.h"
#include "recfile.h"

using namespace std;
const char * keys = "CSDTAMPIBWNGURKEHOLJYQZFXV";
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
int main(int argc, char * argv) {
	int result, i;
	BTree <char> bt(BTreeSize);
	cout << "input data = " << keys << endl;
	result = bt.Create("btree.dat", ios::out);
	if (!result) { 
		cout << "Please delete testbt.dat" << endl; 
		system("pause");
		return 0; 
	}
	for (i = 0; i<26; i++)
	{
		cout << "Inserting " << keys[i] << endl;
		result = bt.Insert(keys[i], i);
		bt.Print(cout);
	}
	bt.Search('K');
	bt.Remove('L');//구현 - redistribute와 merge를 구현한다.
	//bt.InOrderTraversal(cout); 
	system("pause");
	return 1;
}
