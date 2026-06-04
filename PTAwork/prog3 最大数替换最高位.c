#include <stdio.h>
#include <math.h>

int firstMax(int n);

int main (void)
{
    int n = 0;
    int flag = 1;
    scanf("%d", &n);
    if(n == 0)
    {
        printf("%d", n);
    }
    else if(n < 0)
    {
        flag = -1;
        n = -n;
    }
    n = firstMax(n);
    if(flag == -1)
    {
        printf("-%d", n);
    }
    else printf("%d", n);
    return 0;
}

int firstMax(int n)
{
    int max = 0;
    int tmp = n;
    int count = 0;
    while(tmp != 0)
    {
        int m = tmp%10;
        max = max > m ? max : m;
        tmp /= 10;
        count++;
    }
    int first = n/(int)pow(10, count-1);
    int ans = n+(max-first)*(int)pow(10, count-1);
    return ans;
}