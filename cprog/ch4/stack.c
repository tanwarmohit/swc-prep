#include "interface.h"

#define MAXVAL 100

static int sp;
static double stack[MAXVAL];

void push(double value){
  if(sp < MAXVAL)
    stack[sp++] = value;
  else
    printf("error: Stack Full\n");
}

double pop(){
  if(sp == 0)
    printf("error: cannot pop, Stack is empty\n");
  else
    return stack[--sp];
}
