#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	clock_t start, stop;
	double duration;
	start = clock();
	int i;
	for(i=0;i<999999999;i++)
	{
		;
	}
	stop = clock();
	duration = (double)(stop-start) / CLOCKS_PER_SEC;
	printf("%f", duration);
	
	return 0;
}
