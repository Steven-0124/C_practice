#include<stdio.h>

int main (void)
{
    double p0 = 0.0;
    double r1 = 0.0036;//活期
    double r2 = 0.0225;//一年定期
    double r3 = 0.0198;//半年定期
    double p1,p2,p3;
    printf("请输入本金：");
    scanf("%lf",&p0);//不要有换行，及\n
    p1 = p0 * (1 + r1);
    p2 = p0 * (1 + r2);
    p3 = p0 * (1 + r3/2)*(1 + r3/2);
    printf("活期：%.2lf\n", p1);
    printf("一年定期：%.2lf\n", p2);
    printf("半年定期：%.2lf\n", p3);
    return 0;
}