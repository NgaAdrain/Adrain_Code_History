#include <stdio.h>

int main()
{
	int inp,outp;
	printf("�¾ �ظ� �Է��ϼ���:");
	scanf("%d",&inp);
	outp = inp%12;
	switch(outp)
	{
	case 0 ://������
		printf("����� �����̶� �Դϴ�\n");
		break;
	case 1 ://��
		printf("����� �߶� �Դϴ�\n");
		break;
	case 2 ://��
		printf("����� ���� �Դϴ�\n");
		break;
	case 3 ://����
		printf("����� ������ �Դϴ�\n");
		break;
	case 4 ://��
		printf("����� ��� �Դϴ�\n");
		break;
	case 5 ://��
		printf("����� �Ҷ� �Դϴ�\n");
		break;
	case 6 ://ȣ����
		printf("����� ȣ���̶� �Դϴ�\n");
		break;
	case 7 ://�䳢
		printf("����� �䳢�� �Դϴ�\n");
		break;
	case 8 ://��
		printf("����� ��� �Դϴ�\n");
		break;
	case 9 ://��
		printf("����� ��� �Դϴ�\n");
		break;
	case 10 ://��
		printf("����� ���� �Դϴ�\n");
		break;
	case 11 ://��
		printf("����� ��� �Դϴ�\n");
		break;
	}
	return 0;
}