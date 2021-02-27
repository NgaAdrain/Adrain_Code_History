#include <stdio.h>

int main()

{
	float cm,ft,in;
	printf("키(cm)를 입력하세요 :");
	scanf("%f",&cm);
	in = cm / 2.54;
	ft = in/12;
	printf("입력하신 키는 %.2fcm는 %.2f feet 또는 %.2f inch에 해당합니다.\n",cm,ft,in);
	return 0;
}	
/* 
	//교수님께서 짜신 코드
	float cm;
	const float INCH = 2.54;
	const float FEET = 12 * INCH;
	printf("키(cm)를 입력하세요 :");
	scanf("%f",&cm);
	printf("입력하신 키는 %.2f는 %.2f feet 또는 %.2f inch에 해당합니다.\n",cm,cm/INCH,cm/FEET);
	return 0;
*/