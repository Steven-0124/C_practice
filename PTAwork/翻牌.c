#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int n = 0;
    scanf("%d", &n);
    int* num = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
    {
        num[i] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(num[j] == 0) num[j] = 1;
            else num[j] = 0;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(num[i] == 1) printf("%d ", i+1);
    }
    free(num);
    return 0;
}