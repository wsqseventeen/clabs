#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000
int get_line(char *s, int lim);
int strindex(char *s, char *t);
char pattern[MAXLINE];
int main()
{
 char line[MAXLINE];
 int found;
 while (1)
 {
  get_line(line, MAXLINE);
  get_line(pattern, MAXLINE);
  found = strindex(line, pattern);
  if (found != -1)
  {
   printf("%d\n",found) ;
  }
  else
   printf("-1 does not contain t!\n");
 }
 return 0;
}
/*
int main()
{
 char s[100] = "fsafsafafafafaf";
 char t[100] = "s";
 int i;
 i = strindex(s,t);
 printf("i=%d\n", i);
}
*/




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
int strindex(char *s, char *t)
{
 int i, j, k, cc=-1, jud=0;
 for (i=0; s[i]!='\0'; i++)
 {
  for (j=i, k=0; t[k]!='\0'&&s[j]==t[k]; j++, k++)
   {
    jud++;
   }
 
  if (k>0&&t[k]=='\0')
 
   if(i>cc)
   {
    cc=i;
   }
 }
 if (jud!=0)
  return cc;
 else
  return -1;
}