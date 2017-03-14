#include <stdio.h>
#include <ctype.h>

int atoi(char *s)
{
  int i, sign, n;
  for(i = 0; isspace(s[i]); i++) ;

  sign = s[i] == '-' ? -1 : 1;
  if(s[i] == '+' || sign == '-')
    i++;

  for(n = 0; isdigit(s[i]); i++)
    n = n * 10 + (s[i] - '0');

  return sign * n;
}
