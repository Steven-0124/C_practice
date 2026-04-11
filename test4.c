#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main (void)
{
    double n = 0.0;
    scanf("%lf", &n);
    double min = 0.0;
    int num = 0;
    double p = 0.0;
    for(int i = 1; i <= 8; i++)
    {
        double m = 0.0;
        scanf("%lf", &m);
        if(i == 1)
        {
            num = i;
            min = fabs(m-n);
            p = m;
        }
        else
        {
            if(fabs(m-n) < min)
            {
                num = i;
                min = fabs(m-n);
                p = m;
            }
        }
    }
    printf("%d\n%.1f", num, p);
    return 0;
}