#include <stdio.h>

int main(void)
{
    int ch1 = 0;
    int num = 0;
    while((ch1 = getchar()) != '\n' && ch1 != EOF)
    {
        num = 0;
        int tmp_num = 0;
        while((tmp_num = getchar()) >= '0' && tmp_num <= '9')
        {
            num = num*10 + tmp_num-'0';
        }
        for(int i = 0; i < num; i++)
        {
            printf("%c", ch1);
        }
        
        //处理多读的字符
        if(tmp_num == '\n' || tmp_num == EOF)
            break;
        // 如果读到的是下一个字母，放回输入流
        ungetc(tmp_num, stdin);
    }
    return 0;
}

/*
给定一个压缩字符串 s。字符串由若干段组成，每一段的形式为一个小写英文字母 s 
i
?
  后面跟着一个正整数 n 
i
?
  ，表示这个字母连续出现的次数。

请你输出解压缩后的原字符串。

a3b2c1
aaabbc
*/