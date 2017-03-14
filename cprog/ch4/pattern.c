#include<stdio.h>

#define MAX_LIMIT 1000

int get_line(char *, int);
int strindex(char *, char *);

int main(){
  char s[MAX_LIMIT];
  char *to_match = "";
  int total_found = 0;

  while(get_line(s, MAX_LIMIT) > 0){
    if(strindex(s, to_match) >= 0){
      printf("%s", s);
      total_found++;
    }
  }

  printf("Total_Found: %d\n", total_found);
}
