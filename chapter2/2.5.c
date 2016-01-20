#include <stdio.h>
#define LOCAL

int main(void)
{
#ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
#endif
        int a,b,c,tmp;
	while(scanf("%d%d%d",&a,&b,&c) != EOF)
    {
	if (a==0 || b==0 ||c==0)
		{break;}
        printf("%d.",a/b);
        a = a%b*10;

        while(c-- >1)
        {
                printf("%d",a/b);
                a=a%b*10;
        }
        tmp = a%b * 10/b;
        if (tmp<5)
                printf("%d\n",a/b);
        else
                printf("%d\n",a/b+1);
	}
return 0;
}
