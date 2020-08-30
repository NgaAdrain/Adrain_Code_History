#include <iostream>
using namespace std;

int big(int comp_a, int comp_b, int limit = 100);

int main()
{
    int x = big(3, 5);
    int y = big(300, 60);
    int z = big(30, 60, 50);
    cout << x << ' ' << y << ' ' << z << endl;
    system("pause");
    return 0;
}

int big(int comp_a, int comp_b, int limit)
{
    int result;
    if (comp_a >limit || comp_b > limit)
       result = limit;
    else
    {
        if (comp_a >= comp_b)
            result = comp_a;
        else
            result = comp_b;
    }
    return result;   
}
