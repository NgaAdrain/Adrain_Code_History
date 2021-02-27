#include <iostream> //Electrical Engineering and Computer Science 
#include "Matrix.h" //Computer Science Major Undergraduate Course 
#include <ctime>	//sophomore 201524582 Á¤Èñ¼®(Jeong Hee Seok) 

using namespace std;

int main()
{
	int n = 1;
	clock_t previousTime, operatingTime;
	while (n <= 10000) { //for check runtime when n=1 to n=10000 
		previousTime = clock();
		Matrix a(n, n);

		Matrix b(n, n);

		Matrix c_Multiply(n, n);

		Matrix d_Transpose(n, n);

		a.GetData();	//for initialize Matrix a
		b.GetData();	//for initialize Matrix b

		cout << "Display first matrix: " << endl;

		a.Display();

		cout << "Display second matrix: " << endl;

		b.Display();

		d_Transpose = b.Transpose();
		cout << "Transpose() of Matrix b" << endl;

		d_Transpose.Display();

		if (a.CompareRowCol(b))
		{
			cout << "Error! column of first matrix not equal to row of second.";

			cout << "Enter rows and columns for first matrix: ";

		}
		c_Multiply = a.Multiply(b);
		cout << "Multiply of Matrix a,b" << endl;

		c_Multiply.Display();
		operatingTime = clock() - previousTime;
		cout << "operating time when n = " << n << " is "
			<< (float)operatingTime << "ms" << endl;
		n++;
		system("pause");
	}
	//system("pause");
	return 0;

}