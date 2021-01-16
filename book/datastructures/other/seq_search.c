#include<stdio.h>

int seq_search(int list[],int key)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(list[i] == key)
			return i;
	}
	return -1;
}
int main()
{
	int list[] = {1,2,3,4,5,6,7,8,9,0};
	int result = seq_search(list, 5);
	printf("index is %d", result);
	return 0;
}
