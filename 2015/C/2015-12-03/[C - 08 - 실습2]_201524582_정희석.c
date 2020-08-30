#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 81

struct gradescore{
	char subject[MAX_LINE];
	int unit;
	char grade1[MAX_LINE];
};
struct scorelist{
	char grade2[MAX_LINE];
	float sco;
};

float score(struct gradescore grad[]);

int main()
{
	struct gradescore list[]={"C프로그래밍", 3, " ", "공학수학",3," ",
		"일반물리학(II)",3," ","일반물리학실험",1," ","전기회로",3," "};
	int count;
	printf("수업명\t\t학점\t등급\n");
	printf("-----------------------------\n");
	for(count=0;count<5;count++)
	{
		printf("%-17s%d	",list[count].subject,list[count].unit);
		gets(list[count].grade1);
	}
	printf("-----------------------------\n");
	printf("\t\t평점 %.2f\n",score(list));
	return 0;
}

float score(struct gradescore grad[])
{
	float gpa=0;
	float totalscore=0,totalgrade=0;
	int count1,count2;
	struct scorelist list[]={"A+",4.5,"A0",4.0,"B+",3.5,"B0",3.0,"C+",2.5,
		"C0",2.0,"D+",1.5,"D0",1.0,"F",0.0};
	for(count1=0;count1<5;count1++)
	{
		for(count2=0;count2<9;count2++)
		{
			if(strcmp(grad[count1].grade1,list[count2].grade2)==0)
			{
				totalscore +=(grad[count1].unit * list[count2].sco);
				totalgrade += grad[count1].unit;
			}
			else continue;
		}
	}
	if (totalscore == 0) gpa = 0;
    else gpa = totalscore/totalgrade;
    return gpa;
}
