#include <stdio.h>

int main()
{
	int x,y,x1,x2;
	printf("Input x and y :");
	scanf("%d %d",&x, &y);
	x1 = x >> y;
	x2 = x << y;
	printf("%d >> %d = %d(%d를 오른쪽으로 %d비트만큼 이동)\n",x,y,x1,x,y);
	printf("%d << %d = %d(%d를 왼쪽으로 %d비트만큼 이동)\n",x,y,x2,x,y);
	return 0;
}