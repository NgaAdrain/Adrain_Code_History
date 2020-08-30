#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Converter {
    protected :
        double ratio;
        virtual double convert(double src)=0;
        virtual string getSourceString()=0;
        virtual string getDestString()=0;
    public :
           Converter(double r){ratio = r;}
           void run(){
               double src;
               cout << getSourceString() << "������ ";
               cout << getDestString()<< "������ �ٲߴϴ�." <<endl;
               cout << "��ȯ�� " << getSourceString() ;
               cout << "�� �Է��ϼ���. : ";
               cin >> src;
               cout << "��ȯ ��� : " << src << getSourceString() <<"�� " ;
               cout << convert(src) << getDestString() << "�Դϴ�."<<endl;
               }
};

class MileToKm : public Converter {
     public :
         MileToKm();
         MileToKm(double base);
         string getSourceString();
         string getDestString();   
         double convert(double src); 
    };
    
int main(){
    MileToKm mk(1.609344);
    mk.run();
    system("pause");
    return 0;
}

MileToKm::MileToKm(double base) : Converter(base){}
string MileToKm::getSourceString(){
    string Mile;
    Mile = "miles(����)";
    return Mile;
}

string MileToKm::getDestString(){
    string Km;
    Km = "km(ų�ι���)";
    return Km;
} 

double MileToKm::convert(double src){
    return (src*ratio);
}
