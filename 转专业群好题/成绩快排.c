#include <stdio.h>
#include <stdlib.h> 
typedef struct peo
{
    int A;
    int B;
    int C;
    int sum;
    int is_pass;
}Peo;
int cmp(const void* a, const void* b);
int main (void)
{
    int n = 0;
    int lim_a = 0, lim_b = 0, lim_c = 0;
    int k = 0;
    scanf("%d", &n);
    scanf("%d %d %d", &lim_a, &lim_b, &lim_c);
    scanf("%d", &k);
    int pass_rate = n * (double)k/100;
    Peo* peo = (Peo*)malloc(n*sizeof(Peo));
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &peo[i].A, &peo[i].B, &peo[i].C);
        peo[i].sum = peo[i].A + peo[i].B + peo[i].C;
        if(peo[i].A>=lim_a && peo[i].B>=lim_b && peo[i].C>=lim_c) peo[i].is_pass = 1;
        else peo[i].is_pass = 0;
    }

    qsort(peo, n, sizeof(Peo), cmp);//快排
    for(int i = 0; i < n; i++)
    {
        printf("%d %d %d\n", peo[i].A, peo[i].B, peo[i].C);
    }
    printf("%d", pass_rate);
    
    return 0;
}
int cmp(const void* a, const void* b)
{
    const Peo* pa = (const Peo*)a;
    const Peo* pb = (const Peo*)b;
    
    if(pa -> is_pass != pb -> is_pass) return (pb->is_pass - pa->is_pass);//优秀在前
    if(pa -> sum != pb -> sum) return (pb->sum - pa->sum);//总分降序
    if(pa -> A != pb -> A) return (pb->A - pa->A);//A项分降序
    if(pa -> B != pb -> B) return (pb->B - pa->B);//B项分降序
    if(pa -> C != pb -> C) return (pb->C - pa->C);//C项分降序
    
}