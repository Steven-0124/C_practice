#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
typedef struct a
{
    int full;
    int left;//向左最大延伸数
    int up;//向上最大延伸数
    int max;//最大边长
}square;

int main (void)
{
    int n = 0, m = 0;
    int ans = 0;
    scanf("%d %d", &n, &m);
    square (*dp)[m+1] = (square(*)[m+1])calloc((n+1)*(m+1), sizeof(square));
    if(dp == NULL)
    {
        printf("开辟失败");
        return -1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &dp[i][j].full);
            //处理向上延伸数
            if(dp[i][j].full != dp[i-1][j].full)
            {
                dp[i][j].up = dp[i-1][j].up + 1;//与上面填充状态不一样，延伸数加一
            }
            else dp[i][j].up = 1;//重置
            //处理向左延伸数
            if(dp[i][j].full != dp[i][j-1].full)
            {
                dp[i][j].left = dp[i][j-1].left + 1;
            }
            else dp[i][j].left = 1;//重置
            //处理最大正方形边长数,数据转移
            if(dp[i][j].full == dp[i-1][j-1].full)//左上角的填充状态一样
            {
                int tmp = MIN(dp[i][j].up, dp[i][j].left);//取三个方向的最小值
                dp[i][j].max = MIN(tmp, dp[i-1][j-1].max+1);//+1是和斜角组完的正方形大小
            }
            else dp[i][j].max = 1;//没有则重置为1

            if(dp[i][j].max > ans) ans = dp[i][j].max;//更新最大值
        }
    }

    printf("%d", ans);
    free(dp);//释放空间
    return 0;
}

