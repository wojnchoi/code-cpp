#include<iostream>

int fib_iter(int n)
{
	if (n ==0) return 0;
	if (n ==1) return 1;
	
	int pp = 0;
	int p = 1;
	int result = 0;
	
	for(int i=2; i<=n; i++)
	{
		result = p+pp;
		pp = p;
		p = result;
	}
	return result;
}
int main()
{
	int result = fib_iter(3);
	std::cout<<result<<std::endl;
	return 0;
}
