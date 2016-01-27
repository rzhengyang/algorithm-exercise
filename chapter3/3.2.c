#include<stdio.h>
#include<string.h>
int main(void)
{
        int n,num_flag,mas_sore;
        char s[80],i,j;
        char CHON[]={'C','H','O','N'};
        float CHON123[]={12.01,1.008,16.00,14.01};
        float mas,mas_res,mas_num;
        scanf("%d",&n);
        while(n--)
        {
                scanf("%s",s);
                mas=0;
                mas_res=0;
                mas_num=0;
                mas_sore=0;
                for(i=0;i<strlen(s);i++)
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
                                if(s[i+1]>='A'||s[i+1]=='\0')
                                {
                                        mas_res = mas_res+mas;
                                }
                                else{
                                        ;
                                } 
                                mas_sore=0;
                        }
                        else {
                                        if(s[i]<='9'&&s[i]>='0')
                                        {
                                                mas_num=(s[i]-'0');
                                                mas_sore=mas_num+mas_sore*10;	
						if(s[i+1]>='A'||s[i+1]=='\0')
						{
							mas_res=mas_res+mas*mas_sore;
						}
                                        }
                        }
                }
                printf("%.3f\n",mas_res);
        }
                return 0;
}   
