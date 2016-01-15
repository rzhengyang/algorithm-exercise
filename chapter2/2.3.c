#include <stdio.h>
void main()
{
		int i,j,a,b;
		scanf("%d",&i);
		a=i;
		while(i--)
		{
			j=2*i+1;
			b=a-i-1;
			while(b--)
			{
				printf(" ");
			}
			while(j--)
			{
				printf("#");
			}
			
			printf("\n");
		}
}
