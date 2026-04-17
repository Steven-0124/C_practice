#include<stdio.h>
int main(void)
{
    double sum,deno,sign,term;
    sum =1.0;
    deno =2.0;
    sign =1.0;
    while (deno<=100)
    {
        sign = -sign;
        term = sign / deno;
        sum = sum + term;
        deno = deno + 1.0;
    }
    printf("Result: %lf\n", sum);
    return 0;
}