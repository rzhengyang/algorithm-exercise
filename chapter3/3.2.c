#include<stdio.h>
#include<string.h>
int main(void)
{

	char s[80],i;
	char CHON[]={'C','H','O','N'};
	float CHON123[]={12.01,1.008,16.00,14.01};
	float mas,mas_res;
	scanf("%s",s);
	mas=0;
	mas_res=0;
	for(i=0;i<sizeof(s);i++)
	{
		if(s[i]<='Z'&&s[i]>='A')
		{
			switch(s[i])
			{
			
				case 'C':mas=CHON123[0];break;
				case 'H':mas=CHON123[1];break;
				case 'O':mas=CHON123[2];break;
				case 'N':mas=CHON123[3];break;
				default:printf("error input\n");break;
			}
			mas_res=mas_res+mas;
		}
		else {
				if(s[i]<='9'&&s[i]>'0')
				{
					mas_res=mas_res+mas*(s[i]-'1');
				}
		}
	}
	printf("%f\n",mas_res);
	return 0;
}
