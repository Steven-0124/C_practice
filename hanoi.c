#include<stdio.h>
void hanoi(int n, char one, char two, char three);
void Move(char one, char three);
int main (void)
{
    int n = 0;//盘子个数
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');//借助B，把A的盘挪到C上
    return 0;
}

void hanoi(int n, char one, char two, char three)
{
    if (n == 1)
    {
        Move(one, three);//直接挪盘子
    }
    else
    {
        //1.将A上的 n - 1 个盘子借助C挪到B上
        hanoi(n - 1, one, three, two);
        //2.将1个盘子由A挪到C上
        Move( one, three);
        //3.将B上的n-1个盘子借助A挪到C上
        hanoi( n - 1, two, one, three);
    }
}
void Move(char one, char three)
{
    printf("%c --> %c\n", one, three);
}
