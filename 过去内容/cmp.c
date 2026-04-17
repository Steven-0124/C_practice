#include <stdio.h>

int main (void)
{
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);
    //1.if else
    int z = 0;
    if(x > y)
    z = x;
    else
    z = y;
    printf("%d", z);

    //类排序
    if(y > x)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }
    printf("%d", x);

    //三目运算（秒杀）
    int z = x > y? x:y;
    printf("%d", z);




    return 0;
}