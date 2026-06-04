#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char num[101];
    int sum;
    int len;
}Num;

int cmp(const void* a, const void* b);

int main (void)
{
    int n = 0;
    scanf("%d", &n);
    Num* num = (Num*)calloc(n, sizeof(Num));
    for(int i = 0; i < n; i++)
    {
        scanf("%s", num[i].num);
        num[i].len = strlen(num[i].num);
        for(int j = 0; j < num[i].len; j++)
        {
            num[i].sum += num[i].num[j] - '0';
        }
    }
    
    qsort(num, n, sizeof(Num), cmp);
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", num[i].num);
    }
    return 0;
}

int cmp(const void* a, const void* b)
{
    const Num* pa = (const Num*)a;
    const Num* pb = (const Num*)b;
    
    if(pa->sum != pb->sum) return (pa->sum - pb->sum);
    if(pa->len != pb->len) return (pa->len - pb->len);    
    for(int i = 0; i < pa->len; i++)
    {
        if(pa->num[i] != pb->num[i])
            return (pa->num[i] - pb->num[i]);
    }
    return 0;
}