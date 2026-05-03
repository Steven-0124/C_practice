#include <stdio.h>

int main(void)
{
    int k = 0;
    scanf("%d", &k);
    getchar();//吞换行符
    for(int i = 0; i < k; i++)
    {
        int count = 0;
        int find_m = 0;
        int find_M = 0;
        int find_num = 0;
        int find_ch = 0;
        int aaa = 1;
        int ch = 0;
        char pre_char = 0;
        int bbb = 0;
        while((ch = getchar()) != '\n' && ch != EOF)
        {
            count++;
            if(ch >= 'a' && ch <= 'z') find_m++;
            if(ch >= 'A' && ch <= 'Z') find_M++;
            if(ch >= '0' && ch <= '9') find_num++;
            if(ch=='!' || ch=='@' || ch=='#' || ch=='$' || ch=='%' || ch=='^' || ch =='&' || ch=='*') find_ch++;
            if(ch == pre_char) aaa++;
            else
            {
                bbb = aaa>bbb ? aaa : bbb;
                aaa = 1;
            }
            pre_char = ch;
        }
        bbb = aaa>bbb ? aaa : bbb;
        if(count>=8 && find_m>0 && find_M>0 && find_num>0 && find_ch>0 && bbb<3)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}