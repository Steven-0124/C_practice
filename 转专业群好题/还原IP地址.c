#include <stdio.h>
#include <string.h>

int main (void)
{
    char s_inp[40] = {0};
    char s_out[40] = {0};
    scanf("%s", s_inp);
    int len_inp = strlen(s_inp);

    for(int i = 0; i < 39; i++)
    {
        if(i==4 || i==9 || i==14 || i==19 || i==24 || i== 29 || i==34)
        {
            s_out[i] = ':';
        }
        else
            s_out[i] = '0';
    }
    int count = 0;
    int flag = 0;
    s_inp[len_inp] = ':';
    s_inp[len_inp+1] = '\0';
    for(int i = 0; i <= len_inp; i++)//ÅÐ·ÇÈ«0¶ÎÊý
    {
        if(s_inp[i] != ':')
        {
            flag = 1;
        }
        else if(flag == 1)
        {
            count++;
            flag = 0;
        }
    }

    int count_ch = 0;
    int lastidx = 38;
    for(int i = len_inp-1; i >= 0; i--)
    {
        if(s_inp[i] != ':')
        {
            count_ch++;
            s_out[lastidx--] = s_inp[i];
        }
        if(s_inp[i] == ':')
        {
            if(count_ch == 4) lastidx--;
            else if(count_ch == 3) lastidx -= 2;
            else if(count_ch == 2) lastidx -= 3;
            else if(count_ch == 1) lastidx -= 4;
            count_ch = 0;
        }
        if(s_inp[i] == ':' && s_inp[i] == s_inp[i-1])
        {
            lastidx = lastidx - ((8-count)*5);
            i--;
        }
    }

    printf("%s", s_out);
    return 0;
}