#include <stdio.h>

int isPrime(int n);
int main (void)
{
    int n = 0;
    scanf("%d", &n);

    int Primenum[10000] = {0};
    for(int i = 0; i < n; i++)
    {
        if(isPrime(i) == 0) continue;//不是素数
        for(int j = i; j <= n; j *= i)
        {
            Primenum[i] += n/j;//勒让德定理
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(Primenum[i] != 0)
        {
            printf("%d %d\n", i, Primenum[i]);
        }
    }
    return 0;
}
int isPrime(int n)
{
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n%2 == 0) return 0;
    for(int i = 3; i < n; i+=2)
    {
        if(n%i == 0) return 0;
    }
    return 1;
}