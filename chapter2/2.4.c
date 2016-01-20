#include <stdio.h>
#define LOCAL

int main(void)
{
#ifdef LOCAL
        freopen("data2-4.in","r",stdin);
        freopen("data2-4.out","w",stdout);
#endif
        float n,m,i;
        float sub;
        while(scanf("%f%f",&n,&m) != EOF)
    {
        sub=0;
        if (n==0 || m==0)
                {break;}
                
                for(i=0;i<=(m-n);i++)
                {
                        sub=sub+(float)(1/((n+i)*(n+i)));
                }
                printf("%.5f\n",sub);
    }
return 0;
}
