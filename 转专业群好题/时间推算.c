#include <stdio.h>

// 判断是否为闰年
int isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取某年某月的天数
int getDaysInMonth(int year, int month) 
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) 
    {
        return 29;
    }
    return days[month - 1];
}

int main(void) 
{
    int n = 0;
    scanf("%d", &n);
    
    // 初始时间：2026-05-03 14:30:30
    int year = 2026;
    int month = 5;
    int day = 3;
    int hour = 14;
    int minute = 30;
    int second = 30;
    
    // 加上秒数
    second += n;
    
    // 处理进位：秒 -> 分
    minute += second / 60;
    second %= 60;
    
    // 处理进位：分 -> 时
    hour += minute / 60;
    minute %= 60;
    
    // 处理进位：时 -> 天
    day += hour / 24;
    hour %= 24;
    
    // 处理进位：天 -> 月
    while (day > getDaysInMonth(year, month)) 
    {
        day -= getDaysInMonth(year, month);
        month++;
        if (month > 12) 
        {
            month = 1;
            year++;
        }
    }
    
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", 
           year, month, day, hour, minute, second);
    
    return 0;
}