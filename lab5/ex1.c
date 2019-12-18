#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 1000
int swap(char *s,char *p)
{
   int i = 0;
   char temp;
   if(*++p != '\0')
      i = swap(s,p);
   if((s+i) <= (--p))
   {
      temp = *(p);
      *(p) = *(s+i); *(s+i) = temp;
   }
   return ++i;
}
char *reverse(char *s)
{
   char *p,*q;
   q = p = s;
   swap(q,p);
   return s;
}
int get_line(char *s, int lim)
{
 int c, i;
 i=0;
 while (--lim>0&&(c=getchar())!=EOF&&c!='\n')
  s[i++]=c;
 if (c=='\n')
  s[i++]='\0';
 return i;
}
int main(void)
{
 char s[MAX_LINE];
 char c;
 int i=0;
 while(1)
 {
  get_line(s, MAX_LINE);
  //printf("%s\n", s);
  printf("%s\n",reverse(s));
 }
 return 0;
}