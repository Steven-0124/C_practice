#include<stdio.h>
int main(void)
{
    double a = 0.0, b = 0.0, c = 0.0;
    scanf("%lf %lf %lf", &a, &b, &c);
    double tmp = 0.0;
    //a b
    if(a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    //b c
    if(b > c)
    {
        tmp = b;
        b = c;
        c = tmp;
    }
    //a c
    if(a > c)
    {
        tmp = a;
        a = c;
        c = tmp;
    }
    printf("a = %lf\tb = %lf\tc = %lf\n", a, b, c);
    return 0;
}