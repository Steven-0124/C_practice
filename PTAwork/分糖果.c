#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int candies[n];  // 存储每个小朋友的糖果数
    
    // 读入初始糖果数
    for (int i = 0; i < n; i++) {
        scanf("%d", &candies[i]);
    }
    
    // 从1号小朋友(索引0)到n号小朋友(索引n-1)依次处理
    for (int i = 0; i < n; i++) {
        int give = candies[i] / 3;  // 每份的数量（整除3）
        // 注意：candies[i] % 3 就是被吃掉的，直接没了
        
        // 自己保留一份
        candies[i] = give;  // 原来的糖果全部重新分配
        
        // 分给左边的小朋友 (i-1+n)%n 处理环形
        int left = (i - 1 + n) % n;
        candies[left] += give;
        
        // 分给右边的小朋友
        int right = (i + 1) % n;
        candies[right] += give;
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        printf("%d", candies[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}