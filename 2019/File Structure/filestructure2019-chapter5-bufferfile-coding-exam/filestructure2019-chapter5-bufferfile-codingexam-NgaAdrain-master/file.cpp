#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	fstream test("delfile.dat",ios::app|ios::out|ios::in);
	test <<"abcdefg";
	test.seekp(0,ios::beg);
	test <<"xyz";
	return 1;
}
