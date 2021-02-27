#include <stdio.h>

int main()
{
	char count,asc2=97,a,b,c;
	c=24;
	for(count = 1 ; count <= 26 ; count++)
	{
		for(a=1 ; a <= c+1 ; a++)
		{
			printf(" ");
		}
		for(b=1 ; b-count<=0 ; b++)
		{
			printf("%c",asc2+c+b);
		}
		c = c - 1;
		printf("\n");
		
	}
	return 0;
}