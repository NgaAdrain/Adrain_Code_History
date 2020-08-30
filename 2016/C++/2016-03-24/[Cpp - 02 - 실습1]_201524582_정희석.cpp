#include <iostream>
#include <cmath>
using namespace std;
double Gravitational_Force(double mess_1, double mess_2, double distance);
int main()
{
    double inp_mess_1, inp_mess_2;
    double distance;
    char Y_or_N='y';
    do
    {
    cout << "Mess of the 1st body(g) : ";
    cin >> inp_mess_1;
    cout << "Mess of the 2nd body(g) : ";
    cin >> inp_mess_2;
    cout << "Distance between the two bodies(cm) : ";
    cin >> distance;
    cout << "The gravitation force between them is " << Gravitational_Force(inp_mess_1,inp_mess_2,distance) <<"." << endl;
    cout << "continue? (Y/N)";
    cin >> Y_or_N;
    } while((Y_or_N == 'Y')||(Y_or_N == 'y'));
    return 0;
}
double Gravitational_Force(double mess_1, double mess_2, double distance)
{
    
    const double G=6.673*pow(10.0,-8.0);
    double G_Force;
    G_Force = G*(mess_1*mess_2)/pow(distance,2);
    return G_Force;   
}
       
