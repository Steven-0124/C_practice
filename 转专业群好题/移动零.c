#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int* num = (int*)calloc(n, sizeof(int));

    for(int i = 0, count = 0; count < n; count++)
    {
        int p = 0;
        scanf("%d", &p);
        if(p == 0)
        {
            continue;
        }
        else
        {
            num[i] = p;
            i++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", num[i]);
    }
    free(num);
    return 0;
}