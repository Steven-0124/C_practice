#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b);

int main (void)
{
    char s[1001] = {0};
    scanf("%s", s);
    int len = strlen(s);

    char* suffix[1001] = {0};//收集后缀
    for(int i = 0; i < len; i++)
    {
        suffix[i] = s+i;
    }
    qsort(suffix, len, sizeof(char*), cmp);

    for(int i = 0; i< len; i++)
    {
        printf("%s\n", suffix[i]);
    }
    return 0;
}

int cmp(const void *a, const void *b)
{
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    return strcmp(str1, str2);
}
/*
每个非空字符串都有非空后缀子串，比如字符串 "abcd" 的非空后缀子串就有 "abcd","bcd","cd","d" 四个。乐乐想对给定字符串的所有非空后缀子串按字典序排序，请你给出排序结果。

我们保证字符串只含大小写字母，不含空格。

输入格式
仅一行，长度为 n 的字符串。

输出格式
共 n 行，按照字典序从小到大排序的 n 个后缀子串。

gain

ain
gain
in
n
*/