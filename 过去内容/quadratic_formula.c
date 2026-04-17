#include<stdio.h>
#include<math.h>

int main(void)
{
    double a = 0.0, b = 0.0, c = 0.0;
    scanf("%lf %lf %lf", &a, &b, &c);
    double disc = b * b - 4 * a * c;
    if(disc < 0.0)
    {
        printf("无实数解\n");
        return 0;
    }
    else
    {
    double x1 = (-b + sqrt(disc)) / (2 * a);
    double x2 = (-b - sqrt(disc)) / (2 * a);
    printf("x1 = %lf\tx2 = %lf\n", x1, x2);
    }
    return 0;
}