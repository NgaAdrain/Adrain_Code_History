#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 12


int main(int argc, char *argv[])
{
	char *Month[]= {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"},
    str[MAX_LINE],str2[MAX_LINE];
	int year,mon,day,after,dif=0;
	if (argc!=4)
	{
		printf("입력형식은 프로그램명 년도 월 일 입니다");
	}
	else 
	{
         year = atoi(argv[1]);
         mon = atoi(argv[2]);
	     day = atoi(argv[3]);
	     sprintf(str,"%s/%s/%s",argv[1],Month[mon-1],argv[3]);
	     printf("How many days after %s?",str);
	     scanf("%d",&after);
	     dif = day + after;
	     while(dif>31)
	     {
         if((mon<=7)&&(mon%2==1))
         {
         dif -= 31;
         mon+=1;
         if ((mon==2)&&(dif>28))
         {
         dif -= 28;
         mon+= 1;
         continue;
         }
         else if((mon<=7)&&(dif==31))
         {
         dif -= 30;
         mon += 1;                        
         continue;
         }
         else continue;
         }
         else if((mon>=8)&&(mon%2==0))
         {
              if(mon==12)
              {
              dif -= 31;
              mon = 1;
              year+= 1;
              continue;
              }
              else
              {
              dif -= 31;
              mon+=1;
              if((mon>8)&&(dif==31))
              {
              dif -= 30;
              mon += 1;                        
              continue;
              }
              else continue;
              }
         }
         else if(mon==2)
         {
         dif -= 28;
         mon+=1;
         continue;
         }
	     else
         {
         dif -= 30;
         mon+= 1;
         continue;
         }        
    }
         sprintf(str2,"%d/%s/%d",year,Month[mon-1],dif);
	     printf("%s로부터 %d일이 지난후의 날짜는 %s이다(윤년제외)",str,after,str2);     
    }
	return 0;
}
