#include <stdio.h>
#define asizex 2
#define asizey 3
#define bsizex 3
#define bsizey 4

int main()
{
	int a1,a2,b1,b2,A[asizex][asizey],B[bsizex][bsizey],C[asizex][bsizey]={0,0,0,0,0,0,0,0};
	printf("Matrix A:\n");
	for (a1=0;a1<asizex;a1++)
	{
		for (a2=0;a2<asizey;a2++)
		{
			printf("a[%d][%d] = ",a1,a2);
			scanf("%d",&A[a1][a2]);
		}
	}
	printf("\nMatrix B:\n");
	for (b1=0;b1<bsizex;b1++)
	{
		for (b2=0;b2<bsizey;b2++)
		{
			printf("b[%d][%d] = ",b1,b2);
			scanf("%d",&B[b1][b2]);
		}
	}
	printf("\nResult :\n");
	
	for (a1=0;a1<asizex;a1++)
	{
		for (b2=0;b2<bsizey;b2++)
		{
			for (a2=0;a2<asizey;a2++)
			{
				for (b1=0;b1<bsizex;b1++)
				{
					if (a2==b1)
					{
						C[a1][b2]+=A[a1][a2]*B[b1][b2];
					}
					else continue;
				}
			}
			if (a2 == 3)
				{
					if (b2 == 0)
					{
						printf("%3d",C[a1][b2]);
					}
					else if (b2 == 3)
						printf("%8d\n",C[a1][b2]);
					else 
					{
						printf("%8d",C[a1][b2]);
					}
				}
		}
	}
	return 0;
}
