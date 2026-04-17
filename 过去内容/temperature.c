#include<stdio.h>
#pragma execution_character_set("utf-8")

int main(void)
{
    double c,f;
    scanf("%lf", &f);//别漏&
    printf("F: %.2lf\n", f);
    c = 5.0/9*(f - 32);//注意是5.0，不然会出现整数除法，商0余5，最终结果为0
    //%.2lf限定小数点位数，避免精度丢失
    printf("C: %.2lf\n", c);
    return 0;
}