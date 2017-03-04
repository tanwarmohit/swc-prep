#include<stdio.h>

#define MAX_LINE 1000

int get_line(char *line, int limit);
void copy(char *to, char *from);


int main(void){
  int len, max;
  char s[MAX_LINE], l[MAX_LINE];

  max = 0;
  while((len = get_line(s, MAX_LINE)) > 0){
    if(max < len){
      max = len;
      copy(l, s);
    }
  }

  printf("Longest: %s\n", l);
  return 0;
}


int get_line(char *line, int limit){
  int c, i;
  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;

  if(c == '\n')
    line[i++] = c;

  line[i] = '\0';
  return i;
}

void copy(char *to, char *from){
  int i = 0;
  while((to[i] = from[i]) != '\0')
    i++;
}
