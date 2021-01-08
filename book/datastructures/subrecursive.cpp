#include<iostream>

int sub(int n)
{
	int a = 0, i;
	for(i = n; i>0; i-=3)
		a += i;
	return a;
}
int main()
{
	int i = sub(10);
	std::cout<<i<<std::endl;
	return 0;
}
