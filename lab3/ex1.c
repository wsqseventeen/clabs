#include <stdio.h>
#define MAXLINE 1000
int p;
int m = 0;
int judge(char source[], char searchfor[]);
int main(void)
{
char s[MAXLINE];
char t[MAXLINE];
int n = 0;
while ((s[m] = getchar()) != EOF)
{
if (s[m] == ' ')
{
break;
}
m++;
}
while (s[m] == ' ' && (t[n] = getchar()) != EOF && t[n] != '\n')
{
if (t[n] == '\n')
{
break;
}
n++;
}
p = n - 1;
if (judge(s, t) >= 0){
printf("%d",judge(s, t) + 1 );
}
else {
printf("no");
}
}
int judge(char s[], char t[])
{
int i, j, k;
for (i = m - 1; i > 0; i--)
{
for (j = i, k = p; s[j] == t[k]; j--, k--)
;
if (k < 0)
{
return j;
}
}
return -1;
}
