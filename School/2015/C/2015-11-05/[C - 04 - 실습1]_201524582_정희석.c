#include <stdio.h>

long culculator(long money,int period);
long money;
int period;

int main()
{
	printf("�󸶳� �Ա��Ͻðڽ��ϱ�? :");
	scanf("%ld",&money);
	printf("�Ⱓ��? <���� : ��> :");
	scanf("%d",&period);
	printf("%d�� �� ����� ������ �ݾ��� :%ld�� �Դϴ�.\n",period,culculator(money,period));
	return 0;
}

long culculator(long money,int period)
{
	int a;
	float interest;
	if (money<10000000)
	{
		interest =1.015+((period-1)*0.001);
		for (a=1;a<=period;a++)
		{
			money = money * interest;
		}
	}
	else if (money<50000000)
	{
		interest = 1.016+((period-1)*0.001);
		for (a=1;a<=period;a++)
		{
			money = money * interest;
		}
	}
	else
	{
		interest = 1.018+((period-1)*0.001);
		for (a=1;a<=period;a++)
		{
			money = money * interest;
		}
	}
	return money;
}
