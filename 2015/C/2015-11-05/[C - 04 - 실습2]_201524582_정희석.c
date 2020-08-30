#include <stdio.h>

int amenu = 4000, bmenu = 2500;
int totalPrice(char a);

int main()
{
	
	printf("현재까지의 누적금액은 %d원 입니다.\n",totalPrice('A'));
	printf("현재까지의 누적금액은 %d원 입니다.\n",totalPrice('B'));
	printf("현재까지의 누적금액은 %d원 입니다.\n",totalPrice('A'));
	printf("현재까지의 누적금액은 %d원 입니다.\n",totalPrice('A'));
	printf("현재까지의 누적금액은 %d원 입니다.\n",totalPrice('B'));
	return 0;
}

int totalPrice(char a)
{
	static int price;
	if (a == 65)
	{
		price+=amenu;
	}
	else if (a == 66)
	{
		price+=bmenu;
	}
	return price;
}