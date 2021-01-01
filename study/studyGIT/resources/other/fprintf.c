#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp;
	fp = fopen("fprintffunction","w+");
	fprintf(fp, "%s %s %s %d", "We", "are", "in", 2020);

	fclose(fp);
	return 0;
}
