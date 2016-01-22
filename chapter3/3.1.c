#include<stdio.h>
#include<string.h>
int main(void)
{
	char i;
	char s[80];
	int j,count;
	memset(s,sizeof(s),0);
	scanf("%s",s);
	count=0;
	j=0;
	for(i=0;i<80;i++)
	{
		
		if(s[i]=='O')
		{
			j++;
		}
		else
		{
			count=count+j;
			j=0;
		}
		
	}
	printf("%d\n",count);
	return 0;
}
