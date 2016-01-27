#include<stdio.h>
#include<string.h>
int main(void)
{
	int num[10];
	int i,n,x,j,a;
	scanf("%d",&n);
	while(n--)
	{
		memset(num,0,sizeof(num));
		scanf("%d",&x);
		for(i=1;i<=x;i++)		
		{
			a=i;
			while(a)
			{	
				num[a%10]++;
				a=a/10;
			}
		}
		for(j=0;j<9;j++)
		{
			printf("%d ",num[j]);
		}
		printf("%d\n",num[9]);
	}


}
