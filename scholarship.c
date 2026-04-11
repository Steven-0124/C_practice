#include <stdio.h>
#include <stdlib.h>
struct stu
{    
    int num;    
    int c;    
    int m;    
    int e;    
    int total;
};
int cmp(const void* a, const void* b)
{    
    const struct stu* pa = (const struct stu*)a;    
    const struct stu* pb = (const struct stu*)b;    
    if(pa -> total != pb -> total)        
        return (pb -> total) - (pa -> total);//总分降序    
    if(pa -> c != pb -> c)        
        return (pb -> c) - (pa -> c);//语文降序    
    return (pa -> num) - (pb -> num);//学号升序
}
int main (void)
{    
    int n = 0;    
    scanf("%d", &n);    
    struct stu peo[301];    
    for(int i = 0; i < n; i++)    
    {        
        peo[i].num = i + 1;        
        scanf("%d %d %d", &(peo[i].c), &(peo[i].m), &(peo[i].e));        
        peo[i].total = peo[i].c + peo[i].m + peo[i].e;    
    }    
    qsort(peo, n, sizeof(struct stu), cmp);    
    
    for(int i = 0; i < 5; i++)    
    {        
        printf("%d %d\n", peo[i].num, peo[i].total);    
    }    
    return 0;
}