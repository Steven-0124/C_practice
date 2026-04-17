#include <stdio.h>
#include <string.h>

void add(const char* a, const char* b, char* res);

int main (void)
{
    char a[502];
    char b[502];
    char res[502];
    scanf("%s %s", a, b);
    add(a, b, res);
    int len = strlen(res);
    for(int i = len-1; i >= 0; i--)
    {
        printf("%c", res[i]);
    }
    return 0;
}

void add(const char* a, const char* b, char* res)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int carry = 0, idx = 0;
    int result[502] = {0};

    for(int i = 0; i < lenA || i < lenB || carry; i++)
    {
        int digitA = i < lenA ? a[lenA-1-i] - '0': 0;
        int digitB = i < lenB ? b[lenB-1-i] - '0': 0;
        int sum = digitA + digitB + carry;
        result[idx++] = sum%10;
        carry = sum/10;
    }
    for(int i = 0; i < idx; i++)
    {
        res[i] = result[i] + '0';
    }
    res[idx] = '\0';
}