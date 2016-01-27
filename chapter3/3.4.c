#include<stdio.h>
#include<string.h>
int main(void)
{
	int n,num,b,i,j;
	char s[100],s1[100],s2[100];
	scanf("%d",&n);
	while(n--)
	{
 		getchar();  
        	gets(s);
		num= strlen(s);
		for(i=1;i<=num;i++)
		{
			if(num%i==0)
			{
				b=num/i;
				memset(s2,0,100*sizeof(char));
				memset(s1,0,100*sizeof(char));
				strncpy(s1,s,i*sizeof(char));
				for(j=1;j<=b;j++)
				{	
					strcat(s2,s1);
				}
				if(strcmp(s,s2)==0)
				{
					printf("%d\n",i);
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}
