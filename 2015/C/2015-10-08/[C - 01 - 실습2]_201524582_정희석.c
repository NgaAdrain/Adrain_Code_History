#include <stdio.h>
#include "myLang.h"

MAIN()
{
	DEFINE a,b,c,result;
	READ(a);
	READ(b);
	READ(c);
	result = (a+b)-(c*c);
	PRINT(result);
	BYE 0;
}