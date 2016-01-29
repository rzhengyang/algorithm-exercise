#include<stdio.h>
#include<string.h>
int main(void)
{
#ifdef LOCAL
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
#endif
	char s[5][5],str[80],i;
	int j,spc_i,spc_j,errFlag,endFlag,count;
	count=0;
	while(1)
	{
		count++;
		endFlag = 0;
		errFlag = 0;
		for(i=0;i<5;i++)
		{
			gets(s[i]);
			if(strlen(s[i])==0)
			{
				gets(s[i]);
			}
			if(strlen(s[i])==1)
			{
				if(s[i][0] =='Z')
				{
					printf("\n");
					return 0;
				}
			}
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(s[i][j]==' ')
					{
						spc_i=i;
						spc_j=j;
					}
			}
		}	
		while(endFlag == 0)
		{
			scanf("%s",str);
			for(i=0;i<strlen(str);i++)
			{
				switch(str[i])
				{
					case 'A':	s[spc_i][spc_j]=s[spc_i-1][spc_j];s[spc_i-1][spc_j]=' ';spc_i=spc_i-1;	break;
					case 'B':	s[spc_i][spc_j]=s[spc_i+1][spc_j];s[spc_i+1][spc_j]=' ';spc_i=spc_i+1;	break;
					case 'R':	s[spc_i][spc_j]=s[spc_i][spc_j+1];s[spc_i][spc_j+1]=' ';spc_j=spc_j+1;	break;
					case 'L':	s[spc_i][spc_j]=s[spc_i][spc_j-1];s[spc_i][spc_j-1]=' ';spc_j=spc_j-1;	break;
					case '0':	endFlag=1;		 break;
					default:	endFlag=1;errFlag=1;	 break;
				}
				if(spc_i<0||spc_j<0||spc_i>4||spc_j>4)
				{
					errFlag=1;endFlag=1;
				}			
			}
		}
		if(count!=1)
		{
			printf("\n");
		}					
		printf("Puzzle #%d:\n",count);
		if(errFlag==1)
		{
			printf("This puzzle has no final configuration.\n");
		}
		else
		{
			for(i=0;i<5;i++)
				{
					for(j=0;j<5;j++)
					{
						printf("%c",s[i][j]);
						if( j<4 )
						{
							printf(" ");
						}
						else{
							;
						}
					}
					printf("\n");
				}
		}
	}
	return 0;
}
