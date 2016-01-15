#include<stdio.h>
void main()
{
		int a,b,c,i,j;
		j=0;
		scanf("%d%d%d",&a,&b,&c);
		for(i=10;i<=100;i++)
		{
			if(i%3==a && i%5==b && i%7==c)
			{
				printf("%d\n",i);
				j=1;
			}
		}
		if(j==1)
		{;}
		else{
			printf("No answer\n");
		}
}
