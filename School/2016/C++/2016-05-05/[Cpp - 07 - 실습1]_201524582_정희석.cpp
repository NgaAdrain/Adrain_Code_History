#include <iostream>
#include <cstdlib>
using namespace std;

class PrimeNumber{
    public :
        PrimeNumber();
        PrimeNumber(int inp_Prime);
        PrimeNumber operator++();
        PrimeNumber operator--();
        int Get_Prime();
    private :
        int prime_Number;
};
void testprime(int input);

int main(){
    PrimeNumber Result;
    int select,inp_temp;
    cout << "Input a Prime Number : " ;
    cin >> inp_temp;
    testprime(inp_temp);
    PrimeNumber Prime(inp_temp);
    cout << "------------------------Menu------------------------" << endl;
    cout << "1. the next larger prime number" << endl;
    cout << "2. the next smaller prime number" << endl;
    cout << "Input : ";
    cin >> select;
    switch(select){
        case 1 :
             Result = ++Prime;
             cout << "The next larger prime number of "<< inp_temp ;
             cout << " is " << Result.Get_Prime() << endl;
             break;
        case 2 :
             if (inp_temp==2){
                  cout << inp_temp << " is the smallest prime number" <<endl;
                  break;
             }
             else{
             Result = --Prime; 
             cout << "The next smaller prime number of "<< inp_temp ;
             cout << " is " << Result.Get_Prime() << endl;
             break;
             }
        default :
             cout << "You've got the wrong selection" << endl;
             break;
    }
    system("pause");
    return 0;
}

PrimeNumber::PrimeNumber()
                          : prime_Number(1)
{}

PrimeNumber::PrimeNumber(int inp_Prime)
                             : prime_Number(inp_Prime)
{}

PrimeNumber PrimeNumber::operator++( )
{
    int index;
    prime_Number++;
    while(1){
    for(index = 2; index < prime_Number; index++){
        if (prime_Number%index == 0)
            break;
        else
            continue;
        }
    if(index == prime_Number)
        break;
    else
        prime_Number++;
    }
    return prime_Number;    
}

PrimeNumber PrimeNumber::operator--( )
{
    int index;
    prime_Number--;
    while(1){
    for(index = 2; index < prime_Number; index++){
        if (prime_Number%index == 0)
            break;
        else
            continue;
        }
    if(index == prime_Number)
        break;
    else
        prime_Number--;
    }
    return prime_Number;        
}

int PrimeNumber::Get_Prime()
{
    return prime_Number;
}

void testprime(int input){
     int index;
     for(index = 2; index < input; index++){
         if (input % index == 0){
             cout << input << " is not prime number -.-"<< endl;
             break;
         }
         else
             continue;
     }
}
