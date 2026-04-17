#include<stdio.h>

int main(void)
{
    int t ,i,max;
    t = 1;
    scanf("%d", &max);
    //计算阶乘
    for (i = 2; i <= max; i++)
    {
        t = t * i;
    }
    printf("Result: %d\n", t);
    return 0;
}