
#include <stdlib.h>
#include <stdio.h>
int mystrlen(char* str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
void mystrcpy(char* str1, char* str2)
{
    int i, a, b;

    for (i = 0; str2[i] != '\0'; i++)
    {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}
int mystrcmp(char* str1, char* str2)
{
    int i= 0;
    while (str1[i] == str2[i] && str1[i])
    {
        i++;
    }
    if (str1[i] < str2[i])
    {
        return -1;
    }
    if (str1[i] > str2[i])
    {
        return 1;
    }
    return 0;
}

void mystrcat(char* str1, char* str2)
{
    int i, len1, len2;
    len1 = mystrlen(str1);
    len2 = mystrlen(str2) + len1 + 1;
    for (len1, i = 0; len1 < len2; len1++, i++)
    {
        str1[len1] = str2[i];
    }
    str1[len1] = '\0';
}
char* mystrstr(char* str1, char* str2)
{
    char* p = str1;
    int i, j;
    for (i = 0; str1[i] != '\0'; i++)
    {
        for (j = 0; str1[i + j] == str2[j]; j++)
        {
            p = &str1[i];
            if (str2[j + 1] == '\0')
            {

                return p;
            }
        }
    }
    return p;
}
void reverse(char* c1, char* c2)
{
    int i, len;
    for (i = 0; c1[i] != '\0'; i++)
    {
        len = i;
    }
    for (i = 0; c1[i] != '\0'; i++)
    {
        c2[i] = c1[len - i];
    }
    c2[i] = '\0';

}
int main(void)
{
    int diff;
    char* p;
    char str1[50] = "abaaaaabaa";
    char str2[50] = "aaab";
    mystrcpy(str1, str2);
    printf("%s\n", str1);
    diff = mystrcmp(str2, str1);
    mystrcat(str1, str2);
    printf("%d\n", diff);
    printf("%s\n", str1);
    p = mystrstr(str1, str2);
    printf("%d\n", p);
    printf("%s\n", p);
    reverse(str1, str2);
    printf("%s\n", str2);
    return 0;
}