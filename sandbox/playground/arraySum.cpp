#include<iostream>
int sum(int *arr,int arrSize);

int main()
{
	int arr[10] = {10,10,10,10,10,10,10,10,10,10};
	int result = sum(arr,10);
	std::cout<<result<<std::endl;
}

int sum(int *arr,int arrSize)
{
	int sum;
	for(int i=0; i<arrSize;i++)
	{
		sum += arr[i];
	}
	return sum;
}
