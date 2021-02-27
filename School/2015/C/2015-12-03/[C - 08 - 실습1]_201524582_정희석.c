#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 12

struct month {
		char mon[4];
		int day;
	};

enum monType {
	JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};


int main()
{
	enum monType mon;
	struct month m[] = {{"JAN",31},{"FEB",28},{"MAR",31},{"APR",30},{"MAY",31},{"JUN",30},{"JUL",31},
	{"AUG",31},{"SEP",30},{"OCT",31},{"NOV",30},{"DEC",31}};
	int years,mont,days,after;
	int dif=0;
	char str[MAX_LINE],str2[MAX_LINE];
	printf("���س�¥�� �⵵ �� �� �� ���·� �Է��ϼ��� :");
	scanf("%d%d%d",&years,&mont,&days);
	sprintf(str,"%d/%s/%d",years,m[mont-1].mon,days);
	printf("���س�¥ %s���� ���� �ϼ��� �Է��ϼ��� :",str);
	scanf("%d",&after);
	mon = (enum monType) (mont-1);
	dif = after + days;
	while (dif>28)
	{
		if (dif<=m[mon].day) break;
		else
		{
			dif = dif - m[mon].day;
			if (mon==DEC)
			{
				mon = (enum monType) (mon-11);
				years += 1;
				continue;
			}
			else
			{
				mon = (enum monType) (mon+1);
				continue;	
			}
		}
	}
	sprintf(str2,"%d/%s/%d",years,m[mon].mon,dif);
	printf("�Է��Ͻ� ��¥ %s�� ���� %d�� ����� ���� ��¥�� %s�Դϴ�\n",str,after,str2);
	return 0;
}
