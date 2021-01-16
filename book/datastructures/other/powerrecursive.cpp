#include<iostream>

double power(int x, int n)
{
	if(n==0) return 1;
	else if (n%2 == 0)
		return power(x*x,n/2);
	else
		return x*power(x*x,(n-1)/2);
}
int main()
{
	double result = power(2,5);
	std::cout<<result<<std::endl;
	return 0;
}
