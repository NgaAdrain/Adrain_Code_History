#include <stdio.h>
int main()
{
	long long budg95, budg15, differ; //budg95:1995년도 예산, budg15:2015년도 예산, differ : 차이
	printf("1995년의 예산을 입력하세요 :");
	scanf("%lld",&budg95);
	printf("입력하신 값은 %lld입니다.\n",budg95);
	printf("2015년의 예산을 입력하세요 :");
	scanf("%lld",&budg15);
	printf("입력하신 값은 %lld입니다.\n",budg15);
	differ = budg15 - budg95;
	printf("1995년의 예산은 %lld원 이고 2015년의 예산은 %lld원 이며\n그차이는 %lld입니다\n",budg95,budg15,differ);
	return 0;
}

