#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>
#define NUMBER '0'
#define BUFSIZE 1000
int getch();
void ungets(char *s);
void ungetch();
double pop();
void push(double a );
int top();
int getop(char s[]);
double stack[100];
int main(int argc,char *argv[]){
int type;
int op2;
int t,n,i;
char s[100];
for (i=1,t=0;i<argc;i++)
while (--argc > 0)
{
ungets(" ");
ungets(*++argv);
switch (getop(s))
{
case NUMBER:
push(atof(s));
break;
case '+':
push(pop() + pop());
break;
case '-':
op2 = pop();
push(pop() - op2);
break;
case '*':
push(pop() * pop());
break;
case '/':
op2 = pop();
if (op2 != 0.0)
push(pop() / op2);
else
printf("error:zeor divisor\n");
break;
}
}
printf("\t%.8g\n", pop());
return 0;
}
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
if (bufp >= BUFSIZ)
{
printf("ungetch : too many characters\n");
}
else
{
buf[bufp++] = c;
}
}
int topindex = 0;
int getch(void);
void ungetch(int);
int getop(char s[])
{
int i, c;
while ((s[0] = c = getch()) == ' ' || c == '\t')
;
s[1] = '\0';
i = 0;
if (!isdigit(c) && c != '.' && c != '-')
return c;
if (c == '-')
{
if (isdigit(c = getch()))
s[++i] = c;
else{
if(c!=EOF){
ungetch(c);
}
return '-';
}
}
if (isdigit(c))
while (isdigit(s[++i] = c = getch()))
;
if (c == '.')
while (isdigit(s[++i] = c = getch()))
;
s[i] = '\0';
if (c != EOF)
ungetch(c);
return NUMBER;
}
void push(double a)
{
if (topindex <= 98)
{
stack[topindex++] = a;
}
else
{
printf("full\n");
}
}
double pop(void)
{
if (topindex >= 0)
{
return stack[--topindex];
}
else
{
printf("empty \n");
}
}
int top(void)
{
if (topindex > 0)
{
return stack[topindex];
}
else
{
printf("no number");
printf("/n");
}
}
void ungets(char *s){
int i=strlen(s);
while(i>0)
ungetch(s[--i]);
}