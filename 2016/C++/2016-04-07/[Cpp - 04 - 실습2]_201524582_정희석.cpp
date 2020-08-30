#include <iostream>
#include <cstring>
#define MAX_LINE 16
using namespace std;

char* converter(int inp);

int main()
{
    int user_Input,count,check;
	char *outPut;
    cout << "Input a decimal integer plz >.< : ";
    cin >> user_Input;
	outPut = (char *) malloc (MAX_LINE);
    outPut = converter(user_Input);
	check = strlen(outPut);
    cout << user_Input << " is equal to ";
    for (count = 0; count<check; count++)
            cout << outPut[count] ;
	cout << endl;
    system("pause");
    return 0;
}

char* converter(int inp)
{ 
    int count=0,count_S,result,temp_1,temp_2,List[MAX_LINE];
    char *output;
    output = (char*) malloc (MAX_LINE);
    result = inp;
    while(result/16!=0)
    {
        temp_1 = result%16;
        List[count] = temp_1;
        result = (result - temp_1)/16;
        count++;
    }
	List[count] = result;
    output[0] = '0';
    output[1] = 'x';
	temp_1 = count;
    for(count_S = 2; count_S <= count+2 ; count_S++)
    {
        if(List[temp_1]>=10)
		{
			output[count_S] = List[temp_1]+87;
			temp_1--;
		}
        else
		{
            output[count_S] = List[temp_1]+48;
			temp_1--;
		}
    }
    output[count_S] = NULL;
    return output;
}
