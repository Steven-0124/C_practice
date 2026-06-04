#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int is0;
}Num;

int main (void)
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    Num (*num)[m] = (Num(*)[m])calloc(n*m, sizeof(Num));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &num[i][j].num);
            if(num[i][j].num == 0)
            {
                num[i][j].is0 = 0;
            }
            else
            {
                num[i][j].is0 = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(num[i][j].is0 == 0)
            {
                for(int x = 0; x < n; x++)
                {
                    num[x][j].num = 0;
                }
                for(int y = 0; y < m; y++)
                {
                    num[i][y].num = 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ", num[i][j].num);
        }
        printf("\n");
    }
    free(num);
    return 0;
}