#include <stdio.h>

int main()
{
	int x,y,x1,x2;
	printf("Input x and y :");
	scanf("%d %d",&x, &y);
	x1 = x >> y;
	x2 = x << y;
	printf("%d >> %d = %d(%d�� ���������� %d��Ʈ��ŭ �̵�)\n",x,y,x1,x,y);
	printf("%d << %d = %d(%d�� �������� %d��Ʈ��ŭ �̵�)\n",x,y,x2,x,y);
	return 0;
}