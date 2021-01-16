#include<iostream>
using namespace std;
void hanoi_tower(int n, char from, char tmp, char to)
{
	if(n==1) cout<<"block: 1 "<<from<<" to "<<to<<endl;
	else
	{
		hanoi_tower(n-1,from,to,tmp);
		cout<<"block: "<<n<<" "<<from<<" to "<<to<<endl;
		hanoi_tower(n-1,tmp,from,to);
	}
}
int main()
{
	hanoi_tower(3,'A','B','C');
	return 0;
}
