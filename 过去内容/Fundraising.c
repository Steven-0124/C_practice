#include <stdio.h>

int main (void)
{
    int num = 0;
    double money = 0.0;
    int i = 0;
    double total = 0.0;
    for (i = 0; i <1000 ; i++)
    {
        printf("请输入捐款钱数：");
        scanf("%lf",&money);
        total += money;
        num++;
        if(total >= 100000)
        {
            break;
        }
    }
    if(i < 1000 || total >= 100000)
    {
        printf("募捐成功\n");
        printf("募捐人数%d\n",num);
        printf("每人平均捐款%lf\n",total / num);
        printf("总募捐钱数%lf\n",total);
    }
    else
    {
        printf("募捐失败\n");
        printf("总募捐钱数%lf\n",total);
    }
    return 0;
}