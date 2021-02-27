#include <iostream>

class Student
{
public:
	int snum;
	char name[15];
	float weight;
	char department[15];
	
	Student() { };
	Student(const Student& b) {
		// �ٸ� ��ü�� �����ϴ� �����ڸ� ������ ��.
		strcpy(name, b.name);
		snum = b.snum;
		weight = b.weight; 
		strcpy(department, b.department);
	}//Complete => test
	friend std::istream & operator>> (std::istream& stream, Student& s);
	friend std::ostream & operator<< (std::ostream& stream, Student& s);
};