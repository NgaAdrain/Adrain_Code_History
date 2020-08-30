#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Random
{
      public :
          Random(int limit)
                     :randomMax(limit)
{}
          Random()
                     :randomMax(RAND_MAX)
{}
          void generate(int numOfInput);   
      private :
          int randomMax;
};

int main()
{
     Random r1, r2(1000);
     int num;
     cout << "How many random numbers are needed? : ";
     cin >> num;
     r1.generate(num);
     r2.generate(num);
     system("pause");
     return 0;
}

void Random::generate(int numOfInput)
{
     int count_1;
     srand(time(0));
     cout << "-- " << numOfInput << " random numbers between 0 and ";
     cout << randomMax<< " --" << endl;
     for (count_1=0;count_1 < numOfInput;count_1++)
         cout << rand()%randomMax << " ";
     cout << endl;
     cout << endl;
}
