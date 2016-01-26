#include<stdio.h>
#include<string.h>
int main(void)
{
	int  i,n;
	char s[80];
	 int j,count,flag;
	scanf("%d",&n);
	while(n--)
	{
		memset(s,80,0);
		scanf("%s",s);
		count=0;
		j=0;
		flag=1;
		for(i=0;i<=strlen(s);i++)
		{
		
			if(s[i]=='O')
			{
				j=j+flag;
				flag++;
			}
			else
			{
				count=count+j;
				flag=1;
				j=0;
			}

		
		}
		printf("%d\n",count);
	}
	return 0;
}
