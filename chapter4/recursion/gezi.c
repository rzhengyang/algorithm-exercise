//µ›πÈ≤‚ ‘
#include<stdio.h>
int foot(int n);
int main()
{
	int sum;
	int n;
	scanf("%d",&n);
	if(n==1||n==2)
	{
		if(n=1)
		{
			printf("3\r\n");
		}
		else{
			printf("7\r\n");
		}
	}
	else{
	printf("%d\r\n",foot(n));
	}
	return 0;
}
int foot(int n)
{
	if(n==1||n==2)
	{
		if(n==1)
		{
			return 3;
		}
		else{
			return 7;
		}
	}
	else{
		return 2*foot(n-1)+foot(n-2);
	}
}