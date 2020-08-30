#include <iostream>
#include <string>
#include "btree.h"
#include "recfile.h"

using namespace std;
const char * keys = "CSDTAMPIBWNGURKEHOLJYQZFXV";
/* 
template��  **.h�� **.cpp�� �и����� �ʰ� **.h�� ���ľ� link error�� �ذ�
buffile.cpp�� open(0, create()�� mode ���� ����
coding exam: data file�� entry-sequenced file�μ� append, Key(record)�� ���Ͽ�b-tree�� insert�ϴ� ���α׷� ����
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
	bt.Remove('L');//���� - redistribute�� merge�� �����Ѵ�.
	//bt.InOrderTraversal(cout); 
	system("pause");
	return 1;
}
