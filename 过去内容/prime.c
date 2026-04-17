#include<stdio.h>
#pragma execution_character_set("utf-8")
int main(void)
{
    int i=0;
    int n=0;
    
    printf("请输入一个正整数: ");
    scanf("%d", &n);
    
    // 处理特殊情况
    if(n <= 1)
    {
        printf("%d 不是素数\n", n);
        return 0;
    }
    
    for (i=2; i*i <= n; i++)  // 更高效的判断条件
    {
        if(n%i == 0)
        {
            break;
        }
    }
    
    if(i*i <= n)  // 相应的判断条件也要改
    {
        printf("%d 不是素数\n", n);
    }
    else
    {
        printf("%d 是素数\n", n);
    }
    
    return 0;
}