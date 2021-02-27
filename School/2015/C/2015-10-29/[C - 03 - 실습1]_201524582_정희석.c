#include <stdio.h>

int main()
{
	int inp,outp;
	printf("태어난 해를 입력하세요:");
	scanf("%d",&inp);
	outp = inp%12;
	switch(outp)
	{
	case 0 ://원숭이
		printf("당신은 원숭이띠 입니다\n");
		break;
	case 1 ://닭
		printf("당신은 닭띠 입니다\n");
		break;
	case 2 ://개
		printf("당신은 개띠 입니다\n");
		break;
	case 3 ://돼지
		printf("당신은 돼지띠 입니다\n");
		break;
	case 4 ://쥐
		printf("당신은 쥐띠 입니다\n");
		break;
	case 5 ://소
		printf("당신은 소띠 입니다\n");
		break;
	case 6 ://호랑이
		printf("당신은 호랑이띠 입니다\n");
		break;
	case 7 ://토끼
		printf("당신은 토끼띠 입니다\n");
		break;
	case 8 ://용
		printf("당신은 용띠 입니다\n");
		break;
	case 9 ://뱀
		printf("당신은 뱀띠 입니다\n");
		break;
	case 10 ://말
		printf("당신은 말띠 입니다\n");
		break;
	case 11 ://양
		printf("당신은 양띠 입니다\n");
		break;
	}
	return 0;
}