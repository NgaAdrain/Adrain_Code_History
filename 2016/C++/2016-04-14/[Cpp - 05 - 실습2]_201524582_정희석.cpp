#include <iostream>
using namespace std;

class IceCreamSundae
{
      public :
          void receiveOrder();
          void outputDescription();
          void computePrice();             
      private :
          int inputFlavor;
          int inputSize;
          int Num_topping;
          int Total_Price;      
};

int main()
{
    IceCreamSundae order;
    int x,y;
    char Y_or_N = 'y';
    cout << "Welcome to Basket Robbers 38 " << endl; 
    cout << "Our shop is expert of Ice cream sundae" << endl;
    while((Y_or_N == 'Y') || (Y_or_N == 'y'))
    {
    order.receiveOrder();
    order.computePrice();
    order.outputDescription();
    cout << "Continue? (Y or N) : ";
    cin >> Y_or_N;
    }
    cout << "Thank you for your order! Have a Nice Day!" << endl;
    system("pause");    
    return 0;
}

void IceCreamSundae::receiveOrder()
{
    cout << "Select your favorite flavor (0 : Strawberry, ";
    cout << "1 : Vanilla, 2 : Mint) : " ;
    cin >> inputFlavor;
    while(inputFlavor <0 || inputFlavor >2)
    {
        cout << "Sorry, we haven't you choice flavor ";
        cout << "Select your favorite flavor (0 : Strawberry, ";
        cout << "1 : Vanilla, 2 : Mint) : " ;
        cin >> inputFlavor;
    }
    cout << "Select size of icecream sundae (0 : Small, ";
    cout << "1 : Medium, 2 : Large) : " ; 
    cin >> inputSize;
    while(inputSize <0 || inputSize >2)
    {
        cout << "Sorry, we haven't you choice size ";
        cout << "Select size of icecream sundae (0 : Small, ";
        cout << "1 : Medium, 2 : Large) : " ;
        cin >> inputSize;
    }
    cout << "How many topping do you want? (2$ per topping) : ";
    cin >> Num_topping;
}

void IceCreamSundae::outputDescription()
{
    cout << "----------------------Your order is----------------------" << endl;
    switch (inputSize)
    {
        case 0 :
             cout << "Small ";
             break;
        case 1 :
             cout << "Medium ";
             break;
        case 2 :
             cout << "Large ";
             break;
    }
    switch (inputFlavor)
    {
        case 0 :
             cout << "Strawberry ice cream sundae with "<< Num_topping ;
             cout << " toppings" << endl;
             break;
        case 1 :
             cout << "Vanilla ice cream sundae with " << Num_topping ;
             cout << " toppings" << endl;
             break;
        case 2 :
             cout << "Mint ice cream sundae with " << Num_topping ;
             cout << " toppings" << endl;
             break;
    }     
    cout << "Total Price is " << Total_Price << "$" << endl;
    cout << "---------------------------------------------------------" << endl; 
}

void IceCreamSundae::computePrice()
{
    switch (inputSize)
    {
        case 0 :
             Total_Price = 10 + (2 * Num_topping);
             break;
        case 1 :
             Total_Price = 14 + (2 * Num_topping);
             break;
        case 2 :
             Total_Price = 17 + (2 * Num_topping);
             break;
    }
}
