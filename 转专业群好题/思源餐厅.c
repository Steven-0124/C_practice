#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int* cuisine = (int*)calloc(n, sizeof(int));
    int* initial = (int*)calloc(n, sizeof(int));
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &cuisine[i]);
        initial[i] = cuisine[i];
    }
    
    while(1)
    {
        char option[20];
        scanf("%s", option);
        if(strcmp(option, "end") == 0) break;

        if(strcmp(option, "order") == 0)
        {
            int type = 0;
            int num = 0;
            scanf("%d %d", &type, &num);
            if(type>n || type < 1)
            {
                printf("Failed\n");
                continue;
            }
            cuisine[type-1] -= num;
            if(cuisine[type-1] >= 0) printf("Success\n");
            else
            {
                cuisine[type-1] += num;
                printf("Failed\n");
            }
        }
        
        if(strcmp(option, "cancel") == 0)
        {
            int type = 0;
            int num = 0;
            scanf("%d %d", &type, &num);
            if(type>n || type < 1)
            {
                printf("Failed\n");
                continue;
            }
            cuisine[type-1] += num;
            if(cuisine[type-1] <= initial[type-1]) printf("Success\n");
            else
            {
                cuisine[type-1] -= num;
                printf("Failed\n");
            }
        }

        if(strcmp(option, "print") == 0)
        {
            for(int i = 0; i < n; i++)
            {
                printf("%d", cuisine[i]);
                if(i < n-1) printf(" ");
            }
            printf("\n");
        }
    }

    free(cuisine);
    free(initial);
    return 0;
}