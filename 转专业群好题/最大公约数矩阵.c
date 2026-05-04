#include <stdio.h>

int gcd(int x, int y);

int main (void)
{
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d ", gcd(i, j));
        }
        printf("\n");
    }
    return 0;
}

int gcd(int x, int y)//Õ·×ªÏà³ý·¨
{
    int r = 0;
    while( y != 0)
    {
        r = x%y;
        x = y;
        y = r;
    }
    return x;
}