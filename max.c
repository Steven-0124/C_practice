#include<stdio.h>

int main(void)
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    //调用求最大值的函数
    printf("Max: %d\n", max(a, b));
    return 0;
}


//设求两数最大值的函数
int max(int a, int b)
{
    int max;
    if (a > b)
        max = a;
    else
        max = b;
    return max;
}