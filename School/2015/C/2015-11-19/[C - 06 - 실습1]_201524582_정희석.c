#include <stdio.h>
#include <string.h>

void counting(char *s,int size);

int main()
{
	char *str = "do you wanna build a snowman?";
	int length = strlen(str);
	printf("In \"%s\",\n",str);
	counting(str, length);
	return 0;
}

void counting(char *s,int size)
{
	int asc,j,count;
	for (asc='a';asc<='z';asc++)
	{
		count = 0;
		for(j = 0; j<size; j++)
		{
			if (asc == *(s+j))
				count+=1;
			else continue;
		}
		if (count!=0)
			printf("'%c' appears %d times.\n",asc,count);
		else continue;
	}
}
