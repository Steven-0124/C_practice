#include<stdio.h>

int main (void)
{
    int a = 10;
    int b = a++;//后置++,先赋值后自增,所以b=10,a=11
    int c = ++a;//这里a=11,前置++,先自增后赋值,所以c=12,a=12
    printf("a = %d, b =%d, c = %d\n",a,b,c);
    return 0;
}