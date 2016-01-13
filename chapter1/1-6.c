#include <stdio.h>

int main()
{
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	if (a>=b && a>=c){ t=c;}
	if (b>=a && b>=c){ t=b;}
	if (c>=a && c>=b){ t=a;}
	if(a+b+c-t<=t)
	{
		printf("not a triangle\n");
	}
	else if((a*a+b*b)==c*c ||(a*a+c*c)==b*b || (c*c+b*b)==a*a)
	{
		printf("yes\n");
	
	}
	else{
		printf("no\n");
	}
	return 0;
}
