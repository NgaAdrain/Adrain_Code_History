#include <stdio.h>
int main()
{
	long long budg95, budg15, differ; //budg95:1995�⵵ ����, budg15:2015�⵵ ����, differ : ����
	printf("1995���� ������ �Է��ϼ��� :");
	scanf("%lld",&budg95);
	printf("�Է��Ͻ� ���� %lld�Դϴ�.\n",budg95);
	printf("2015���� ������ �Է��ϼ��� :");
	scanf("%lld",&budg15);
	printf("�Է��Ͻ� ���� %lld�Դϴ�.\n",budg15);
	differ = budg15 - budg95;
	printf("1995���� ������ %lld�� �̰� 2015���� ������ %lld�� �̸�\n�����̴� %lld�Դϴ�\n",budg95,budg15,differ);
	return 0;
}

