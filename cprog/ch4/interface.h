#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'

int getop(char *);
void push(int);
double pop();
int getch();
void ungetch(char);
