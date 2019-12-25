#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h>
 #define MAXOP 200     
#define NUMBER '0'     
#define MAXVAL 200     
#define BUFSIZE 200 
 
int sp = 0; 
double val[MAXVAL];     
char buf[BUFSIZ];
int bufp = 0;
 
int getop ( char s[] );           
int getch(void);
void ungetch( int c);
void push (double f);   
double pop (void);
 
int main (){ 
	int type; 
	double op2;
	char s[MAXOP];   
	while ( ( type = getop( s )) != EOF ) 
		{ 
			switch (type) 
			{ 
			case NUMBER: 
				push( atof (s) );   
				break; 
			 
			case '+': 
				push ( pop () + pop ()); 
				break; 
 
			case '*': 
				push (pop() * pop() ); 
				break; 
 
			case '-': 
				op2 = pop(); 
				push ( pop() - op2); 
				break ; 
			 
			case '/': 
				op2 = pop(); 
				if( op2 != 0) 
					push (pop() / op2 ); 
				else printf("error : zero divisor\n"); 
				break; 
			 
			case '%': 
				op2 = pop(); 
				if( op2 != 0.0)
				       push((int)pop()%(int)op2);
				else printf("error : zero divisor\n");
				break; 
			 
			case '\n': 
				printf("result = %2.8g\n",pop()); 
				break; 
			default: 
				printf("unknown commond %s\n",s); 
				break; 
		} 
	} 
	return 0; 
} 
 

 
int getop (char s[] ) 
	{ 
	int i,c; 
 
	while ( (s[0] = c = getch()) == ' ' || c == '\t' )   
                                ; 
	s[1] = '\0'; 
	if ( !isdigit(c) && c != '.' && c != '-')   
		return c; 
	i = 0; 
	if ( c == '-' ){ 
		if ( isdigit(s[++i] = c = getch() ) || c == '.') 
			s[i] = c; 
		else { 
			if ( c != EOF ) 
				ungetch(c); 
		return '-'; 
		} 
	}	 
	if ( isdigit(s[i]) )   
		while ( isdigit(s[++i] = c = getch()) ) 
		; 
	if ( c == '.' ) 
		while ( isdigit(s[++i] = c = getch()) ) 
		; 
	s[i] = '\0'; 
	if ( c != EOF )   
		ungetch( c ); 
	return NUMBER; 
} 
 
int getch(void) 
	{ 
	return (bufp > 0) ? buf[--bufp] : getchar() ; 
	} 
 
void ungetch( int c) 
	{ 
	if ( bufp >= BUFSIZ) 
		printf("ungetch : too many characters!\n"); 
	else
		buf[bufp++] = c ; 
        }
void push (double f) 
	{ 
	if ( f < MAXVAL) 
		val[sp++] = f;
	else printf("error : stack full,can not push %g\n",f);
	} 
 
double pop (void) 
	{ 
	if ( sp > 0) 
		return val[--sp]; 
	else printf("error : stack empty!\n"); 
	} 
