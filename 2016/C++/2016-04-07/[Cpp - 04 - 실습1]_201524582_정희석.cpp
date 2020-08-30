#include <iostream>
#include <iomanip> // setw(n)
#define NUM_STUDENT 5
using namespace std;

typedef struct List{
       int id;
       int score[4];
}STD_INFO;

int cal_Total(int list[]);
double cal_Avg(int list[]);

int main(){
    //const int STUDENT = 5;
    STD_INFO l_Std[5];
    int List[NUM_STUDENT][4]={100,90,80,95,97,98,99,87,100,98,78,98,78,89,76,98,
                              90,100,87,86};
    int count_F,count_S;
    cout << "StdId" << "  " << "C++" << "    " << "DMath"
         << "  " << "OpenSw" << " " << "LinAlg" << " "
         << "Tot" << "    " << "Avg" << endl;
    for (count_F = 0; count_F < NUM_STUDENT; count_F++)
    {
        l_Std[count_F].id = 101+count_F;
        for (count_S = 0; count_S < 4; count_S++)
            l_Std[count_F].score[count_S] = List[count_F][count_S];
    }
    for(count_F = 0;count_F < NUM_STUDENT; count_F++)
    {
        cout.setf(ios::left);                    
        cout << setw(7) << l_Std[count_F].id ;
        for(count_S = 0; count_S < 4; count_S++)
        {        
            cout << setw(7) << l_Std[count_F].score[count_S];
        }
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << setw(7)<< cal_Total(l_Std[count_F].score);
        cout << setw(7)<< cal_Avg(l_Std[count_F].score)<<endl;
    } 
    system("pause");
    return 0;
}

int cal_Total(int list[])
{
    int totalResult=0,count_F;
    for(count_F=0;count_F<4;count_F++)
        totalResult += list[count_F];
    return totalResult;
}

double cal_Avg(int list[])
{
    double avgResult=0;
    avgResult = (double) cal_Total(list) / 4;
    return avgResult;
}
