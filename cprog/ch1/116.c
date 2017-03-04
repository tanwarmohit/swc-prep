#include<stdio.h>

#define MAX_LINE 50

int get_line(char *line, int limit);
void copy(char *to, char *from);


int main(void){
  int len, max, prev_len;
  char s[MAX_LINE], l[MAX_LINE], t[MAX_LINE];

  max = prev_len = 0;
  while((len = get_line(s, MAX_LINE)) > 0){
    if(prev_len + len > max){
      max = prev_len + len;

      if(prev_len)
        copy(l, t);
      else
        copy(l, s);
    }

    if(s[len - 1] != '\n'){
      if(prev_len == 0)
        copy(t, s);
      prev_len += len;
    }
    else
      prev_len = 0;

  }

  printf("Longest: %d, Line:%s\n", max, l);
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
