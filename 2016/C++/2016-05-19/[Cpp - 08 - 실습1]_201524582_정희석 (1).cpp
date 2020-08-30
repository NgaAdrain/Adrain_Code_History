#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
void anagrams(string i1, string i2);

int main(){
	string First_input, Second_input;
	int count;
	char Y_or_N='y';
	while(Y_or_N=='y'||Y_or_N=='Y'){
	fflush(stdin);
	cout << "This program is anagram finder" << endl;
	cout << "Input First Sentence : ";
	getline(cin,First_input);
	cout << "Input Second Sentence : ";
	getline(cin,Second_input);
	anagrams(First_input, Second_input);
	cout<<"continue? (Y or N) :" ;
	cin >> Y_or_N;
	}
	cout<<"good bye!"<<endl;
	system("pause");
	return 0;
}

void anagrams(string i1, string i2)
{
	int temp_1 = 0, temp_2 = 0, count_1, count_2, size_1, size_2;
	size_1 = i1.length();
	size_2 = i2.length();
	for(count_1 = 0; count_1<size_1; count_1++)
	{
		if(isupper(i1[count_1]))
			i1[count_1] = tolower(i1[count_1]);
		else
			continue;
	}
	for(count_1 = 0; count_1<size_2; count_1++)
	{
		if(isupper(i2[count_1]))
			i2[count_1] = tolower(i2[count_1]);
		else
			continue;
	}
	
	for(count_1=0;count_1<size_1;count_1++){
		if(isalpha(i1[count_1]) == false)
			continue;
		else{
			for(count_2=0;count_2<size_1;count_2++){
				if(i1[count_1]==i1[count_2])
					temp_1++;
			}
			for(count_2=0;count_2<size_2;count_2++)
			{
				if(i1[count_1]==i2[count_2])
					temp_2++;
				else
					continue;
			}
			if(temp_1!=temp_2)
			{
				cout << "They're not anagrams >.<" << endl;
				break;
			}
			else
				continue;
		}
	}
	if(count_1==size_1)
		cout << "Yeah, They're anagrams O.O" << endl;
}

