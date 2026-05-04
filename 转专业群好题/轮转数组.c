#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    
    int* num = (int*)calloc(n ,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    k = k%n;
    for(int i = n-k; i < n; i++)
    {
        printf("%d ", num[i]);
    }
    for(int i = 0; i < n-k; i++)
    {
        printf("%d ", num[i]);
    }
    free(num);
    return 0;
}