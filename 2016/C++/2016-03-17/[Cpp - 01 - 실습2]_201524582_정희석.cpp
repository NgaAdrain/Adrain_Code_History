#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	char name[80];
	int count,count2=0,length,countTemp=0,countList[5];
	cout << "Input five names with a semicolon between each other: "<< "\n";
	cout << ">> ";
	gets(name);
	cout << "\n";	
	cout << "The names you input:"<<"\n";
	for (count = 0; count<5;count++)
	{
		cout << count+1 <<":      ";
		while (count2<80)
		{
			if (name[count2]!=';')
			{
				cout<< name[count2];
				count2++;
			}
			else
			{
				cout << "\n" ;
				countList[count] = count2-1;
				count2++;
				break;
			}
		}
	}
	length = countList[0]+1;
	for (count = 0; count<5;count++)
	{
		for (count2 = count+1; count2<5; count2++)
		{
				if((countList[count2]-countList[count2-1]-1)>length)
				{
					length = countList[count2] - countList[count2-1]-1;
					countTemp = countList[count2-1]+1;
				}
		}
	}
	cout << "\nThe longest name is " << "\"";
	for (count = countTemp+1 ; count <= countTemp+length ; count++)
		cout<<name[count];
	cout<<"\".\n";	
	return 0;
}
