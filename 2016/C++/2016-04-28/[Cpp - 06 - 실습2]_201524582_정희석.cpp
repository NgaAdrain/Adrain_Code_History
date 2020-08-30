#include <iostream>
#include <vector>
using namespace std;

class IceCreamSundae
{
public:
	void receiveOrder();
	void outputDescription();
	int computePrice();
private:
	int inputFlavor;
	int inputSize;
	int Num_topping;
	int Total_Price;
};

class Order
{
public:
	void vector_back(IceCreamSundae option);
	void output();
private:
	IceCreamSundae order;
	vector<IceCreamSundae> Ice_order_v;
};

int main()
{
	IceCreamSundae order_option;
	Order order;
	int x, y;
	char Y_or_N = 'y', Y_or_N_2;
	cout << "Welcome to Basket Robbers 38 " << endl;
	cout << "Our shop is expert of Ice cream sundae" << endl;
	while ((Y_or_N == 'Y') || (Y_or_N == 'y'))
	{
		Y_or_N_2 = 'y';
		while ((Y_or_N_2 == 'Y') || (Y_or_N_2 == 'y'))
		{
			order_option.receiveOrder();
			order.vector_back(order_option);
			cout << "Continue? (Y or N) : ";
			cin >> Y_or_N_2;
		}
		order.output();
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
	cout << "1 : Vanilla, 2 : Mint) : ";
	cin >> inputFlavor;
	while (inputFlavor <0 || inputFlavor >2)
	{
		cout << "Sorry, we haven't you choice flavor " << endl;
		cout << "Select your favorite flavor (0 : Strawberry, ";
		cout << "1 : Vanilla, 2 : Mint) : ";
		cin >> inputFlavor;
	}
	cout << "Select size of icecream sundae (0 : Small, ";
	cout << "1 : Medium, 2 : Large) : ";
	cin >> inputSize;
	while (inputSize <0 || inputSize >2)
	{
		cout << "Sorry, we haven't you choice size " << endl;
		cout << "Select size of icecream sundae (0 : Small, ";
		cout << "1 : Medium, 2 : Large) : ";
		cin >> inputSize;
	}
	cout << "How many topping do you want? (2$ per topping) : ";
	cin >> Num_topping;
}

void IceCreamSundae::outputDescription()
{
	switch (inputSize)
	{
	case 0:
		cout << "Small ";
		break;
	case 1:
		cout << "Medium ";
		break;
	case 2:
		cout << "Large ";
		break;
	}
	switch (inputFlavor)
	{
	case 0:
		cout << "Strawberry ice cream sundae with " << Num_topping;
		cout << " toppings" << endl;
		break;
	case 1:
		cout << "Vanilla ice cream sundae with " << Num_topping;
		cout << " toppings" << endl;
		break;
	case 2:
		cout << "Mint ice cream sundae with " << Num_topping;
		cout << " toppings" << endl;
		break;
	}
}

int IceCreamSundae::computePrice()
{
	switch (inputSize)
	{
	case 0:
		Total_Price = 10 + (2 * Num_topping);
		break;
	case 1:
		Total_Price = 14 + (2 * Num_topping);
		break;
	case 2:
		Total_Price = 17 + (2 * Num_topping);
		break;
	}
	return Total_Price;
}

void Order::vector_back(IceCreamSundae option)
{
	Ice_order_v.push_back(option);
}

void Order::output()
{
	int x, total = 0, size;
	size = Ice_order_v.size();
	cout << "----------------------Your order is----------------------" << endl;
	for (x = 0; x < size; x++)
	{
		cout << x+1 << ". ";
		order = Ice_order_v[x];
		order.outputDescription();
		total += order.computePrice();
	}
	cout << "Total Price is " << total << "$" << endl;
	cout << "---------------------------------------------------------" << endl;
	Ice_order_v.clear();
}
