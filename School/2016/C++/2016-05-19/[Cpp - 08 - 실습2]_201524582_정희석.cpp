#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class person
{
	public : 
		void inp_name();
		void inp_phoneNumber();
		void inp_memo();
		void out_info();
		void search_name(string st1);
	private :
		string name;
		string phoneNumber;
		string memo;
};

int main(){
	string s_name;
	person *list;
	int num_element,count_1,selection;
	cout << "This program is telephone directory program" << endl;
	cout << "How many people you will input the information in directory? : ";
	cin >> num_element;
	list = new person[num_element];
	for(count_1 = 0 ; count_1 < num_element; count_1++ ){
		cout << "Person info #" << count_1+1 << " : " << endl;
		fflush(stdin);
		list[count_1].inp_name();
		fflush(stdin);
		list[count_1].inp_phoneNumber();
		fflush(stdin);
		list[count_1].inp_memo();
		fflush(stdin);
	}
	do{
		cout << "Menu : " << endl;
		cout << "1. Display all" << endl;
		cout << "2. Search One" << endl;
		cout << "3. Quit" << endl;
		cout << "Select >> " ;
		cin >> selection;
		switch(selection){
			case 1:
				cout.width(17);
				cout.setf(ios::left);
				cout << "Name" ;
				cout.width(17);
				cout.setf(ios::left);
				cout << "Phone Number" ;
				cout.width(17);
				cout.setf(ios::left);
				cout << "Memo" << endl;
				for(count_1 = 0; count_1 < num_element; count_1++)
					list[count_1].out_info();
				break;
			case 2:
				cout << "Name for search ? : " ;
				fflush(stdin);
				getline(cin,s_name);
				for(count_1 = 0; count_1 < num_element; count_1++)
					list[count_1].search_name(s_name);
				break;
		}		
	}while(selection ==1 || selection ==2);
	cout << "Thank you for using this program >.<" << endl;
	system("pause");
	return 0;
}

void person::inp_name(){
	cout << "Name : ";
	getline(cin,name);
}
void person::inp_phoneNumber(){
	cout << "Phone Number : ";
	getline(cin,phoneNumber);
}
void person::inp_memo(){
	cout << "Memo : ";
	getline(cin,memo);
}
void person::out_info(){
	cout.width(17);
	cout.setf(ios::left);
	cout << name ;
	cout.width(17);
	cout.setf(ios::left);
	cout << phoneNumber ;
	cout.width(17);
	cout.setf(ios::left);
	cout << memo << endl;
}
void person::search_name(string st1){
	if(name == st1){
		cout.width(17);
		cout.setf(ios::left);
		cout << "Name" ;
		cout.width(17);
		cout.setf(ios::left);
		cout << "Phone Number" ;
		cout.width(17);
		cout.setf(ios::left);
		cout << "Memo" << endl;
		out_info();
	}
}

