#include<stdio.h>

#define MAX_LINE 40

int get_line(char *line, int limit);
void copy(char *to, char *from);


int main(void){
  int len, prev_len;
  char s[MAX_LINE];

  prev_len = 0;
  while((len = get_line(s, MAX_LINE)) > 0){
    if(s[len-1] != '\n'){
      printf("%s", s);
      prev_len = 1;
    }else{
      if(prev_len == 1){
        printf("%s", s);
        prev_len = 0;
      }
    }
  }

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
