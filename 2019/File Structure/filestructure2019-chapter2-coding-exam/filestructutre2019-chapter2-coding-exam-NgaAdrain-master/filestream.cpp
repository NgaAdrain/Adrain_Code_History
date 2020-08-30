// �й� : 201524582	
// �̸� : ����
// ����� ���� : NgaAdrain (adrainnga@gmail.com)
//
// filestream - ���� ���� �ڵ� ���� 19.3.21
// �ҽ��ڵ� ���� �� �ٿ� �й�, �̸�, ����� ������ �ݵ�� �ۼ��� ��.
//
// Q. Switch���� ������ ��ɵ��� �����Ͽ� ���������� �۵��ϴ� ���α׷��� �ϼ��Ͻÿ�.
//
//
// Tip) ����ȯ
// int -> char*		: snprintf(����� ����, ������ ����, "%d", int ��);
// float -> char*	: snprintf(����� ����, ������ ����, "%f", float ��);
// char* -> int		: atoi(����)
// char* -> float	: atof(����)

#define _CRT_SECURE_NO_WARNINGS

#include "student.h"
#include <fstream>
#include <string.h>
using namespace std;

istream& operator>> (istream& stream, Student& p)
{ // read fields from input
	char snum[10], weight[10];
	cout << "Enter Name, or <cr> to end: " << flush;
	stream.getline(p.name, 30);
	if (strlen(p.name) == 0) return stream;
	cout << "Enter Student Number : " << flush; stream.getline(snum, 30); p.snum = atoi(snum);
	cout << "Enter Weight: " << flush; stream.getline(weight, 10); p.weight = atof(weight);
	cout << "Enter city: " << flush; stream.getline(p.department, 15);
	return stream;
}

ostream& operator<< (ostream& stream, Student& p)
{
	stream << p.name << '|' << p.snum << '|';
	stream << p.weight << '|' << p.department << '|' << endl;
	return stream;
} //Complete => test

const int MaxBufferSize = 200;

// ��� ��Ʈ�� ���ۿ� Student Ŭ������ ��ü�� �Է��Ͽ��� ��.
// buffer�� ���� ������ ���Ҹ� ���̰�, �����ڴ� '|'�� ��� �Ѵ�.
int WriteStudent(ostream & stream, Student & p)
{
	char buffer[MaxBufferSize] = { 0 };
	char temp_buffer[MaxBufferSize] = { 0 };
	strcpy(buffer, p.name); strcat(buffer, "|"); //�̸�
	snprintf(temp_buffer, 10, "%d", p.snum); 
	strcat(buffer, temp_buffer); strcat(buffer, "|");//num
	snprintf(temp_buffer, 10, "%.4f", p.weight);//weight
	strcat(buffer, temp_buffer); strcat(buffer, "|");
	strcat(buffer, p.department); strcat(buffer, "|");//department
	strcat(buffer, "\n");
	// buffer�� ������ �����͵� �� �� �ֵ��� �ڵ带 �ۼ�.
	short length = strlen(buffer);
	stream.write((const char*)&buffer, length);
	return 1;
} //Complete => test
int ReadStudent(istream & stream, Student & p)
{
	short length = 0;
	char temp[15] = { 0 };
	char temp_snum[10];
	char temp_name[15];
	char temp_weight[10];
	char temp_department[15];
	stream.getline(temp_name, 15, '|');
	stream.getline(temp_snum, 10, '|');
	stream.getline(temp_weight, 10, '|');
	stream.getline(temp_department, 15, '|');
	if (strstr(temp_name, "\n") != nullptr) {
		memcpy(temp, temp_name + 1, strlen(temp_name) - 1);
		strcpy(temp_name, temp);
	}
	strcpy(p.name, temp_name);
	p.snum = atoi((const char*)temp_snum);
	p.weight = atof((const char*)temp_weight);
	strcpy(p.department, temp_department);
	// ������ �ڵ�, WriteStudent()���� ���� ����� �ݿ��� �б�
	return 1;
}
int main() {
	int count, select;
	char filename[20];
	Student p;
	Student *stable[10];
	cout << "Enter the file name:" << flush;
	cin.getline(filename, 19);

	while (1)
	{
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;
		
		switch (select) {
		case 1:
			// ���ڵ带 �Է¹޾Ƽ� Student�� �迭�� �����ϴ� �ڵ� 
			cout << "���ڵ带 ����� Ƚ���� �Է� : "; 
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> p;
				stable[i] = new Student(p);			// ���� ������ ���� �ʿ� //Complete => test
			}
			break;
		case 2:
			// Student�� �迭�� ȭ�鿡 ����ϴ� �ڵ�   
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];					// operator<< (������ �����ε�) ���� �ʿ� //Complete => test
			}
			break;
		case 3:
		{
			// ��ü�� ���� ���Ͽ� �����ϴ� �ڵ�. //Complete => test
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			for (int i = 0; i < count; i++)
			{
				WriteStudent(fostream, *stable[i]);	// ���� ��� �ڵ� ���� �ʿ� //Complete => test
				delete(stable[i]);//new()�� ��ȯ
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// ���Ϸκ��� ���� �о���� �ڵ�. 
				ifstream fistream(filename, ios::in);
				if (fistream.fail()) {
					cout << "File open failed!" << endl;
					return 0;
				}
				for (int i = 0; i < count; i++)
				{
					stable[i] = new Student();
					ReadStudent(fistream, *stable[i]);
					cout << *stable[i];// ���� �Է� �ڵ� ���� �ʿ� //Complete => test
				}
				fistream.close();
			break;
		}
		default:
			// ����
			exit(0);
			break;
		}
		//*/
	}
}