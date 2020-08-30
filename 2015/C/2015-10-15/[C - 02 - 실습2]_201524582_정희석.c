#include <stdio.h>

int main()
{
	int num,a1000,b100,c10,d1;
	printf("네 자리 정수를 입력하세요 : ");
	scanf("%d",&num);
	a1000 = num / 1000;
	b100 = (num % 1000)/100;
	c10 = (num % 100)/10;
	d1 = (num % 10);
	printf("입력하신 수는 %d천%d백%d십%d입니다.\n",a1000,b100,c10,d1);
	return 0;
}
/*    //처음에 짠 코드
{
	int num,a1000,b100,c10,d1;
	printf("네 자리 정수를 입력하세요 : ");
	scanf("%d",&num);
	a1000 = num / 1000;
	b100 = (num - a1000*1000)/ 100;
	c10 = (num - a1000*1000 - b100*100)/ 10;
	d1 = (num - a1000*1000 - b100*100 - c10*10);
	printf("입력하신 수는 %d천%d백%d십%d입니다.\n",a1000,b100,c10,d1);
	return 0;
}
*/