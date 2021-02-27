#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 20

struct student_info{
	char name[MAX_LINE];
	int score;
};

void swap(struct student_info *st1,struct student_info *st2,int size);

int main()
{
	struct student_info *list1,*list2;
	int *p;
	int students,count;
	printf("입력하실 학생 수를 입력해 주세요 : ");
	scanf("%d",&students);
	list1 = (struct student_info *) malloc (students * sizeof(struct student_info));
	list2 = (struct student_info *) malloc (students * sizeof(struct student_info));
	for (count = 0;count<students;count++)
	{
		printf("학생 #%d 의 정보를 입력해 주세요(이름 & 점수) : \n",count+1);
		scanf("%s %d",list1[count].name,&list1[count].score);
	}
	printf("입력받은 정보를 점수 내림차순으로 정리합니다\n");
	swap(list1,list2,students);
	for(count = students-1;count>=0;count--)
	{
		printf("%-4s %d\n",list2[count].name,list2[count].score);
	}
	return 0;
}

void swap(struct student_info *st1,struct student_info *st2,int size)
{
	int temp,temp2,count1=0,count2;
	for(count1 = 0;count1<size;count1++)
	{
		temp = st1[count1].score;
		temp2 = count1;
		st2[count1].score = st1[count1].score;
		strcpy(st2[count1].name,st1[count1].name);
		for(count2 = count1+1 ;count2<size;count2++)
		{
			if(temp>=st1[count2].score)
			{
				temp2 = count2;
				temp = st1[count2].score;
			}
			else continue;
		}
		st1[temp2].score = st1[count1].score;
		strcpy(st2[count1].name,st1[temp2].name);
		strcpy(st1[temp2].name,st1[count1].name);
		st2[count1].score = temp;
	}	
}