#include <stdio.h>

int main()

{
	float cm,ft,in;
	printf("Ű(cm)�� �Է��ϼ��� :");
	scanf("%f",&cm);
	in = cm / 2.54;
	ft = in/12;
	printf("�Է��Ͻ� Ű�� %.2fcm�� %.2f feet �Ǵ� %.2f inch�� �ش��մϴ�.\n",cm,ft,in);
	return 0;
}	
/* 
	//�����Բ��� ¥�� �ڵ�
	float cm;
	const float INCH = 2.54;
	const float FEET = 12 * INCH;
	printf("Ű(cm)�� �Է��ϼ��� :");
	scanf("%f",&cm);
	printf("�Է��Ͻ� Ű�� %.2f�� %.2f feet �Ǵ� %.2f inch�� �ش��մϴ�.\n",cm,cm/INCH,cm/FEET);
	return 0;
*/