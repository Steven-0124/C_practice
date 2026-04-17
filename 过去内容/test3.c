#include <stdio.h>

int main (void)
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int dp[31][31];

    dp[0][1] = 1;//没开始传球第0次，第1个人
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j==1)//特判1号，球是从n和2传来的
				dp[i][j] = dp[i-1][n] + dp[i-1][2];
			else if(j==n)//特判n号，球是从1号和n-1号传来的
				dp[i][j] = dp[i-1][1] + dp[i-1][n-1];
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
        }
    }
    printf("%d", dp[m][1]);
    return 0;
}