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
               cout << getSourceString() << "단위를 ";
               cout << getDestString()<< "단위로 바꿉니다." <<endl;
               cout << "변환할 " << getSourceString() ;
               cout << "을 입력하세요. : ";
               cin >> src;
               cout << "변환 결과 : " << src << getSourceString() <<"은 " ;
               cout << convert(src) << getDestString() << "입니다."<<endl;
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
    Mile = "miles(마일)";
    return Mile;
}

string MileToKm::getDestString(){
    string Km;
    Km = "km(킬로미터)";
    return Km;
} 

double MileToKm::convert(double src){
    return (src*ratio);
}
