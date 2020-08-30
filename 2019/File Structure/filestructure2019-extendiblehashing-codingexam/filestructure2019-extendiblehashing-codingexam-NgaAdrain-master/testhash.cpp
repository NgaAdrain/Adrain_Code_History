// tsthash.cpp
/*
Page 563: Programming project
1. create a hashed index of the student record file
2. The student record file is the entry-sequenced file
3. For insertion of new appended records, insert key on hashed index
4. Using hashed index, search the corresponding record with the key
*/
#include "direct.h"
#include "bucket.h"
#include "hash.h"
#include <iostream>
#include <conio.h>
using namespace std;
int main(void)
{
	const int numkeys = 15;
	int select = -1, result;
	char removeKey[15];
	Directory Dir(4);
	result = Dir.Create("tsthash");
	if (result == 0)
	{
		cout << "Please delete tsthash.dir and tsthash.bkt" << endl;
		return 0;
	}
	char * keys[] = { "bill", "lee", "pauline", "alan", "julie",
		"mike", "elizabeth", "mark", "ashley", "peter",
		"joan", "john", "charles", "mary", "emily" };
	while (1)
	{
		cout << "\nSelect command 1: insert, 2. search, 3. remove, 4. print all, 5. Quit => ";
		cin >> select;
		switch (select) {
		case 1:
		{
			for (int i = 0; i < numkeys; i++)
			{
				cout << (void *)Hash(keys[i]);//(void*) castingÀº bit string
				cout << endl << endl << keys[i] << "  " << (void*)MakeAddress(keys[i], 16) << endl << endl;
				result = Dir.Insert(keys[i], 100 + i);
				if (result == 0) cout << "Insert for " << keys[i] << " failed" << endl;
				Dir.Print(cout);
			}
			Dir.Close();
			break;
		}
		case 2:
		{
			result = Dir.Open("tsthash");
			if (result == 0)
			{
				cout << "Please create tsthash.dir and tsthash.bkt" << endl;
				return 0;
			}
			cout << "Input key what search : ";
			cin >> removeKey;

			result = Dir.Search(removeKey);
			if (result == -1)
				cout << endl << "Search for " << removeKey << " failed" << endl;
			else
			{
				cout << endl << endl << removeKey << "  " << (void*)MakeAddress(removeKey, 16) << endl;
				cout << "RecAddr : " << result << endl;
			}
			Dir.Close();
			break;
		}
		case 3:
		{
			result = Dir.Open("tsthash");
			if (result == 0)
			{
				cout << "Please create tsthash.dir and tsthash.bkt" << endl;
				return 0;
			}
			cout << "Input key what remove : ";
			cin >> removeKey;
			cout << endl << endl << removeKey << "  " << (void*)MakeAddress(removeKey, 16) << endl << endl;
			result = Dir.Remove(removeKey);
			if (result == 0) cout << "Remove for " << removeKey << " failed" << endl;
			Dir.Print(cout);
			Dir.Close();
			break;
		}
		case 4:
		{
			result = Dir.Open("tsthash");
			if (result == 0)
			{
				cout << "Please create tsthash.dir and tsthash.bkt" << endl;
				return 0;
			}
			Dir.Print(cout);
			Dir.Close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
	system("pause");
	return 1;
}