#include<stdio.h>
#define yes 1
#define no 0
int main()
{
return 0;
}
int htoi(char s[])
{
int hexdigit ,n, inhex,i;
i=0;
if(s[i]=='0')
{
i++;
if(s[i]=='x'||s[i]=='X')
{
i++;
}
}
n=0;
inhex=yes;
for(;inhex==yes;i++)
{
if(s[i]>='0'&&s[i]<='9') hexdigit=s[i]-'0';
else if(s[i]>='a'&&s[i]<='f')hexdigit=s[i]-'a'+10;
else if(s[i]>='A'&&s[i]<='F')hexdigit=s[i]-'A'+10;
else inhex=no;
if(inhex==yes)
n=16*n+hexdigit;
}
return n;
}