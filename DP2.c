#include <stdio.h>

int main (void)
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int coust[n+1];
    coust[0] = m;
    for(int i = 1; i <= n; i++)
    {
        int p = 0;
        scanf("%d", &p);
        coust[i] = coust[i-1] + p;
    }

    int dp[n+1];
    //初始化
    for(int i = 0; i <= n; i++)
    {
        dp[i] = coust[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            int time = dp[j] + m + coust[i-j];//先运j，再运i-j
            dp[i] = (time < dp[i]) ? time : dp[i];//更新最小时间
        }
    }
    printf("%d", dp[n]);
    return 0;
}