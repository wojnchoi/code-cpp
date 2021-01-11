#include<stdio.h>

int main()
{
	int coin[4] = {500,100,50,10};
	int pay = 0, change = 0;
	scanf("%d", &pay);
	for(int i= 0; i < 4; i++) {
		change = pay/coin[i];
		pay %= coin[i];
		printf("%d : %d \n",coin[i],change);	
	}
}
