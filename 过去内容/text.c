#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int main (void)
{
    int V = 0;
    int n = 0;
    scanf("%d %d", &V, &n);
    int dp[n+1][V+1];
    int volume[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < V; j++)
        {
            dp[i][j] = 0;//初始化dp表
        }
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &volume[i]);
    }
    for(int i = 1; i <= n; i++)//避免i-1时越界
    {
        for(int j = 0; j < V; j++)
        {// 如果容量足够放第i个物品，比较放与不放的最大值
        // 否则只能选择不放（即dp[i-1][j]）
            dp[i][j] = (j >= volume[i]) ? 
                   max(dp[i-1][j], dp[i-1][j - volume[i]] + volume[i]) 
                   : dp[i-1][j];
        }
    }
    printf("%d", V-dp[n][V]);
    return 0;
}
