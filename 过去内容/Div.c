#include<stdio.h>

int main(void)
{
    int a,b;
    int c = 0;
    int d = 0;
    scanf("%d%d",&a,&b);
    c = a/b;
    d = a%b;
    printf("%d %d\n",c,d);
    return 0;
}