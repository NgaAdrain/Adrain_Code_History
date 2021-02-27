#include <stdio.h>
#define NUM 10
void read_array(int n[],int size);
double average(int n[],int size);
double variance(int n[],int size,double avg);

int main()
{
	int arr[NUM];
	int lenarr = NUM;
	read_array(arr, lenarr);
	printf("Average = %.2f\n",average(arr,lenarr));
	printf("Variance = %.2f\n",variance(arr,lenarr,average(arr,lenarr)));
	return 0;
}

void read_array(int n[],int size)
{
	int a = 1;
	printf("Input %d integers : ",size);
	for (a = 0;a<size;a++)
		scanf("%d", &n[a]);
}

double average(int n[], int size)
{
	int a;
	double total = 0, total_average = 0;
	for (a=0;a<size;a++)
	{
		total += n[a];
	}
	total_average = total/size;
	return total_average;
}

double variance(int n[],int size,double avg)
{
	int a;
	double total_variance = 0;
	double total_difference = 0;
	double difference=0;
	for (a=0;a<size;a++)
	{
		difference = (n[a]-avg)*(n[a]-avg);
		total_difference += difference;
	}
	total_variance = total_difference / size;
	return total_variance;
}