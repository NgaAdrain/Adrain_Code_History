#include <stdio.h>

int amenu = 4000, bmenu = 2500;
int totalPrice(char a);

int main()
{
	
	printf("��������� �����ݾ��� %d�� �Դϴ�.\n",totalPrice('A'));
	printf("��������� �����ݾ��� %d�� �Դϴ�.\n",totalPrice('B'));
	printf("��������� �����ݾ��� %d�� �Դϴ�.\n",totalPrice('A'));
	printf("��������� �����ݾ��� %d�� �Դϴ�.\n",totalPrice('A'));
	printf("��������� �����ݾ��� %d�� �Դϴ�.\n",totalPrice('B'));
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