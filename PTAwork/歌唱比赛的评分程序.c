#include <stdio.h>
int main()
{
  int num1,num2;
  float avg1,avg2;
  float  statistic(int num);
  void print_m( );
  scanf("%d",&num1);       //输入乐理评委的人数
  avg1= statistic(num1);
  printf("乐理知识的平均分是%.2f\n",avg1);
  print_m( );
  scanf("%d",&num2);     //输入演唱评委的人数
  avg2= statistic(num2);
  printf("演唱的平均分是%.2f\n",avg2);
  print_m( );
}

/* 请在这里填写答案 */




double highest = 0.0;
double lowest = 0.0;

float statistic(int num)
{
    double sum = 0.0;
    for(int i = 0; i < num; i++)
    {
        double score = 0.0;
        scanf("%lf", &score);
        if(i == 0) 
        {
            lowest = score;
            highest = score;
        }
        else
        {
        highest = score > highest ? score : highest;
        lowest = score < lowest ? score : lowest;
        }
        sum += score;
    }
    return sum/num;
}

void print_m( )
{
    printf("最高分是%.2lf\n最低分是%.2lf\n", highest, lowest);
    highest = 0.0;
    lowest = 0.0;
}