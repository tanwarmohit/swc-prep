#include "interface.h"

#define BUFFER 100

static int bufp;
static char buf[BUFFER];

int getch(){
  return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int ch){
  if(bufp < BUFFER)
    buf[bufp++] = ch;
  else
    printf("error: too many characters in buffer\n");
}
