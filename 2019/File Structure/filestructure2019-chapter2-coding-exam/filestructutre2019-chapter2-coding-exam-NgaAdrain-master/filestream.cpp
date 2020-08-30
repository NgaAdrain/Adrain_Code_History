// 학번 : 201524582	
// 이름 : 정희석
// 깃허브 계정 : NgaAdrain (adrainnga@gmail.com)
//
// filestream - 파일 구조 코딩 시험 19.3.21
// 소스코드 가장 윗 줄에 학번, 이름, 깃허브 계정을 반드시 작성할 것.
//
// Q. Switch문의 각각의 기능들을 구현하여 정상적으로 작동하는 프로그램을 완성하시오.
//
//
// Tip) 형변환
// int -> char*		: snprintf(저장될 변수, 버퍼의 길이, "%d", int 값);
// float -> char*	: snprintf(저장될 변수, 버퍼의 길이, "%f", float 값);
// char* -> int		: atoi(변수)
// char* -> float	: atof(변수)

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

// 출력 스트림 버퍼에 Student 클래스의 객체를 입력하여야 함.
// buffer의 끝에 각각의 원소를 붙이고, 구분자는 '|'를 사용 한다.
int WriteStudent(ostream & stream, Student & p)
{
	char buffer[MaxBufferSize] = { 0 };
	char temp_buffer[MaxBufferSize] = { 0 };
	strcpy(buffer, p.name); strcat(buffer, "|"); //이름
	snprintf(temp_buffer, 10, "%d", p.snum); 
	strcat(buffer, temp_buffer); strcat(buffer, "|");//num
	snprintf(temp_buffer, 10, "%.4f", p.weight);//weight
	strcat(buffer, temp_buffer); strcat(buffer, "|");
	strcat(buffer, p.department); strcat(buffer, "|");//department
	strcat(buffer, "\n");
	// buffer에 나머지 데이터도 들어갈 수 있도록 코드를 작성.
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
	// 구현할 코드, WriteStudent()에서 쓰기 방식을 반영한 읽기
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
			// 레코드를 입력받아서 Student의 배열에 저장하는 코드 
			cout << "레코드를 기록할 횟수를 입력 : "; 
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cin >> p;
				stable[i] = new Student(p);			// 복사 생성자 구현 필요 //Complete => test
			}
			break;
		case 2:
			// Student의 배열을 화면에 출력하는 코드   
			for (int i = 0; i < count; i++)
			{
				cout << *stable[i];					// operator<< (연산자 오버로딩) 구현 필요 //Complete => test
			}
			break;
		case 3:
		{
			// 객체의 값을 파일에 저장하는 코드. //Complete => test
			ofstream fostream(filename, ios::out);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			for (int i = 0; i < count; i++)
			{
				WriteStudent(fostream, *stable[i]);	// 파일 출력 코드 보충 필요 //Complete => test
				delete(stable[i]);//new()을 반환
			}
			fostream.close();
			break;
		}
		case 4:
		{
			// 파일로부터 값을 읽어오는 코드. 
				ifstream fistream(filename, ios::in);
				if (fistream.fail()) {
					cout << "File open failed!" << endl;
					return 0;
				}
				for (int i = 0; i < count; i++)
				{
					stable[i] = new Student();
					ReadStudent(fistream, *stable[i]);
					cout << *stable[i];// 파일 입력 코드 구현 필요 //Complete => test
				}
				fistream.close();
			break;
		}
		default:
			// 종료
			exit(0);
			break;
		}
		//*/
	}
}