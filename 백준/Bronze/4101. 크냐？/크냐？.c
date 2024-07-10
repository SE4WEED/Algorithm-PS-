#include <stdio.h>

int main()
{
    long long a, b;
    while (1)
    {
        scanf("%lld %lld", &a, &b);
        if (a == 0 && b == 0)
        {
            break;
        }
        if (a <= b)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}