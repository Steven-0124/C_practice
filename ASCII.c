#include<stdio.h>

int main(void)
{
    printf("%c\n",'\141');//八进制表示,对应字符是a,ASCII码97
    printf("%c\n",'\x61');//十六进制表示,对应字符是a,ASCII码97
    return 0;
}