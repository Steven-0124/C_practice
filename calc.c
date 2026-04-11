#include <stdio.h>
int LeapYear(int year);
int get_Day(int year, int month);
int DayFromJan1 (int year, int month);
int formatWeekday(int weekday);
int main (void)
{
    int month = 0;
    scanf("%d", &month);
    int year = 2025;
    int jan1weekday = 3;//1号是周三，周天0，周一1，周二2...
    int days = DayFromJan1 (2025, month);
    int firstDayWeekday = (jan1weekday + days) % 7;//计算所求月份星期
    int firstDay = formatWeekday(firstDayWeekday);

    printf("MON TUE WED THU FRI SAT SUN\n");//表头
    
    int daysInMonth = get_Day(year, month);
    // 打印1号前面的空格
    for (int i = 1; i < firstDay; i++) {
        printf("    ");
    }
    
    // 打印日期
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%3d", day);
        
        // 判断是否换行（周日之后换行）
        if ((firstDay + day - 1) % 7 == 0) {
            printf("\n");
        } else if (day < daysInMonth) {
            printf(" ");
        }
    }
    
    // 补换行
    if ((firstDay + daysInMonth - 1) % 7 != 0) {
        printf("\n");
    }
    
    return 0;
}


int LeapYear(int year)//闰年判定
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_Day(int year, int month)//获取天数
{//设置储存每月天数的数组
    int DayInMonth[12] = {31, 28+LeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return DayInMonth[month - 1];//返回所求月份的天数
}

int DayFromJan1 (int year, int month)//获取该月份到1月1号差的天数
{
    int total = 0;
    for(int m = 1; m < month; m++)//从1月开始，一直加到前一个月
    {
        total += get_Day(year, m);
    }
    return total;
}
int formatWeekday(int weekday) 
{
    // weekday: 0=星期日, 1=星期一, ..., 6=星期六
    // B4414要求：1=MON, 2=TUE, 3=WED, 4=THU, 5=FRI, 6=SAT, 7=SUN
    if (weekday == 0) return 7;
    return weekday;
}