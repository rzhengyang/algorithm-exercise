#include<stdio.h>
int eat(int n);
int main()
{
	int dayNum;
	int sunNum;
	scanf("%d",&dayNum);
	printf("%d\r\n",eat(dayNum));
	return 0;
}
int eat(int n)
{
	if(n==1)
	{
		return 1;
	}
	else{
		return (eat(n-1)+1)*2;
	}
}