#include <iostream>
#include <stdio.h>
using namespace std;

void player(char name[], int wins, double ERA); //pitcher
void player(char name[], double batAvg, int RBI); //batter

int main()
{
    player("Ryu", 15, 2.97);
    player("Choo", 3.44, 99);
    system("pause");
    return 0;
}

void player(char name[], int wins, double ERA) //pitcher
{
     int annualSalary;
     annualSalary = 1000*wins + 20000*(1/ERA);
     cout << name << "     Pitcher Annual Salary in 2017 : $"<< annualSalary << endl;      
}
void player(char name[], double batAvg, int RBI) //batter
{
     int annualSalary;
     annualSalary = 10000*batAvg + 100*RBI;
     cout << name << "    Batter  Annual Salary in 2017 : $"<< annualSalary << endl;      
}
