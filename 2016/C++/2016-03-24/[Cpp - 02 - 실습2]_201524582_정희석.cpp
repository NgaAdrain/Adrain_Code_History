#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
void Random_10(int inp_R_S_P);
void Random_100(int inp_R_S_P);
void Random_1000(int inp_R_S_P);
int main()
{
    int inputOfUser,count;
    char R[5]="ROCK",S[9]="SCISSORS",P[6]="PAPER";
    cout << "What's your choice ?" << "(0: ROCK, 1: SCISSORS, 2: PAPER)"<<endl;
    cin >> inputOfUser;
    if(inputOfUser>2 || inputOfUser<0)
    {
    while (inputOfUser>2 || inputOfUser<0)
       {
       cout << "Your choice is wrong!" << endl;
       cout << "What's your choice ?" << "(0: ROCK, 1: SCISSORS, 2: PAPER)"<<endl;
       cin >> inputOfUser;
       }
    }
    switch (inputOfUser) {
    case 0:
       cout << "Your choice is " << R << endl;
       break;
    case 1 :
       cout << "Your choice is " << S << endl;
       break;
    case 2 :
       cout << "Your choice is " << P << endl;
       break;
       }
    cout << "After 10 games:" << endl;
    Random_10(inputOfUser);
    cout << "\n"<<endl;
    cout << "After 100 games:" << endl;
    Random_100(inputOfUser);
    cout << "\n"<<endl;
    cout << "After 1000 games:" << endl;
    Random_1000(inputOfUser);
    cout <<"\n"<<endl;
    return 0;
}

void Random_10(int inp_R_S_P)
{
     int win=0,lose=0,draw=0,count,random_R_S_P;
     srand(time(0));
     for (count=0;count<10;count++)
     {
         random_R_S_P = rand() % 3;
         if(inp_R_S_P != random_R_S_P)
         {
             if(inp_R_S_P == 0)
             {
                  if(random_R_S_P == 1)
                       win++;
                  else
                       lose++;
             }
             else if(inp_R_S_P == 1)
             {
                  if(random_R_S_P == 0)
                       lose++;
                  else
                       win++;
             }
             else
             {
                  if(random_R_S_P == 0)
                       win++;
                  else
                       lose++;                 
             }
         }
         else
             draw++;
     }
     cout << "win = " << win << ",";
     cout << "lose = " << lose <<",";
     cout << "draw = " << draw <<",";     
}
void Random_100(int inp_R_S_P)
{
     int win=0,lose=0,draw=0,count,random_R_S_P;
     srand(time(0));
     for (count=0;count<100;count++)
     {
         random_R_S_P = rand() % 3;
         if(inp_R_S_P != random_R_S_P)
         {
             if(inp_R_S_P == 0)
             {
                  if(random_R_S_P == 1)
                       win++;
                  else
                       lose++;
             }
             else if(inp_R_S_P == 1)
             {
                  if(random_R_S_P == 0)
                       lose++;
                  else
                       win++;
             }
             else
             {
                  if(random_R_S_P == 0)
                       win++;
                  else
                       lose++;                 
             }
         }
         else
             draw++;
     }
     cout << "win = " << win << ",";
     cout << "lose = " << lose <<",";
     cout << "draw = " << draw <<",";    
}
void Random_1000(int inp_R_S_P)
{
     int win=0,lose=0,draw=0,count,random_R_S_P;
     srand(time(0));
     for (count=0;count<1000;count++)
     {
         random_R_S_P = rand() % 3;
         if(inp_R_S_P != random_R_S_P)
         {
             if(inp_R_S_P == 0)
             {
                  if(random_R_S_P == 1)
                       win++;
                  else
                       lose++;
             }
             else if(inp_R_S_P == 1)
             {
                  if(random_R_S_P == 0)
                       lose++;
                  else
                       win++;
             }
             else
             {
                  if(random_R_S_P == 0)
                       win++;
                  else
                       lose++;                 
             }
         }
         else
             draw++;
     }
     cout << "win = " << win << ",";
     cout << "lose = " << lose <<",";
     cout << "draw = " << draw <<",";      
}
