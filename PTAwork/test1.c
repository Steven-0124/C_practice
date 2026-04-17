#include <stdio.h>
#include <string.h>
int isAEIOU (char c);
int main (void)
{
    char s[1001] = {0};
    fgets(s, sizeof(s), stdin);
    int len = strlen(s);
    int sum = 0;
    if(isAEIOU(s[0]) == 2) 
    {
        printf("ÊÇ\n");
        sum++;
    }
    else printf("²»ÊÇ\n");
    for(int i = 1; i < len; i++)
    {
        if(isAEIOU(s[i])) sum++;
    }
    printf("%d", sum);
    return 0;
}
int isAEIOU (char c)
{
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U') return 2;
    else if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
    else return 0;
}