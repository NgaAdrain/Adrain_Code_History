#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    ifstream mail("junkMail.txt"), receiver("recList.txt");
    if(receiver.fail()){
        cout << "Input file opening failed" <<endl;
        exit(1);
        }
    ofstream output;
    string temp,temp_2,temp_Fname,temp_Lname,temp_outputname;
    int temp_index, count;
    while(getline(receiver,temp_Fname)){
        temp = "Mail to ";
        temp_2 = ".txt";
        temp_index = temp_Fname.find(" ");
        temp_Lname= temp_Fname.substr(0,temp_index); 
        temp = temp + temp_Lname + temp_2;    
        output.open(temp.c_str());
        while(getline(mail,temp)){
            if(temp.find("#F#")!=-1){
            temp_index = temp.find("#F#");
            temp.erase(temp_index,3);
            temp.insert(temp_index, temp_Fname);
            output << temp << endl;
            }
            else if(temp.find("#N#")!=-1){
            temp_index = temp.find("#N#");
            temp.erase(temp_index,3);
            temp.insert(temp_index, temp_Lname);
            output << temp << endl;     
            }
            else{
            output << temp << endl;
            }
        }
        output.close();
        mail.clear(); //eof �����̹Ƿ� 
        mail.seekg(0,ios::beg); //���� ��Ʈ���� ó������  
        }                       //(g : �Է»����� ��Ʈ������ ���)
    receiver.close();
    mail.close();
    system("pause");
    return 0;    
}
    
