#include<iostream>

using namespace std;
int sum(int n)
{
	if(n==1) return 1;
	else return (n+sum(n-1));
}
int sum2(int n)
{
	int sum;
	for(int i=0; i<=n;i++)
		sum += i;
	return sum;
}
int main()
{
	int result = sum(6);
	std::cout<<result<<std::endl;
	result = sum2(6);
	std::cout<<result<<std::endl;
}
