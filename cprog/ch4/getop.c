#include "interface.h"

int getop(char *s){
  int c, i;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  /*If input is not a digit or decimal point*/
  if(!isdigit(c) || c != '.')
    return c;

  i = 0;
  /* Collect integer Part */
  if(isdigit(c)){
    while(isdigit(s[++i] = c = getch()));
  }

  if(c == '.'){
    /* Collect fractional part */
    while(isdigit(s[++i] = c = getch()));
  }

  s[i] = '\0';

  if(c != EOF)
    ungetch(c);

  return NUMBER;
}
