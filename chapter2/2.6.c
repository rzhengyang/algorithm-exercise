#include <stdio.h>
void main(void)
{
        int i,j,a,b,c,m;
	int k[10]= {0};	
	for(m=100;m<321;m++)
        {
		a=m;
                b=2*a;
                c=3*a;
				
		k[a%10]=k[a/10%10]=k[a/100]=1;
		k[b%10]=k[b/10%10]=k[b/100]=1;
		k[c%10]=k[c/10%10]=k[c/100]=1;
		j=0;
		for(i=1;i<10;i++)
		{
			j=j+k[i];
			if(j==9)
			{
				printf("%d %d %d\n",a,b,c);
			}
		}
		for(i=0;i<10;i++)
		{
			k[i]=0;
		}
	}
}
