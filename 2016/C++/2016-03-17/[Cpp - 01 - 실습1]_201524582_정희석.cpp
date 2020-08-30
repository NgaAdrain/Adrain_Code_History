#include <iostream>
using namespace std;
int main()
{
	int num1,num2,x;
		for (num1 = 1; num1 <= 9; num1++)
		{
			for (num2 = 1; num2 <= 9; num2++)
			{
				if (num2 == 9)
					cout << num2 << "x" << num1 << "=" << num1*num2<<"\n";
				else 
				{
					if (num1*num2<10)
					cout << num2 << "x" << num1 << "=" << num1*num2 << "   ";
					else
					cout << num2 << "x" << num1 << "=" << num1*num2 << "  ";
				}
			}
		}
	cout << "\n";
	return 0;
}
