#include<stdio.h>
int main (void)
{
    int a = 0;
    int hun = 0,dec = 0,uni = 0;//hundreds , decade , unit
    scanf("%d",&a);
    hun = a / 100;
    dec = a / 10 - hun*10 ;
    uni = a % 10;
    int reversed = uni * 100 + dec * 10 + hun;
    printf("%d", reversed);
    return 0;
}