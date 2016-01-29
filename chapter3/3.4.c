#include <stdio.h>
#include <string.h>

int main()
{
    char s[85];
    int n;
    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int k, i;
        for(i = 1; i <= len; ++i)
        {
            if(len % i == 0)
            {
                for(k = i; k < len; ++k)
                {
                    if(s[k] != s[k % i])
                        break;
                }
                if(k == len)
                {
                    printf("%d\n", i);
                    break;
                }
            }
        }
        if(n) printf("\n");
    }
    return 0;
}
