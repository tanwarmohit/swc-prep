#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NKEYS (sizeof keytabs / sizeof(struct key))
#define MAXWORD 100
#define BUF_SIZE 1000

static int getword(char *, int);
static struct key *binsearch(char *, struct key *);
static int getch();
static void ungetch(int);
static int bufp = 0;
static int buffer[BUF_SIZE];

struct key {
  char *word;
  int count;
} keytabs[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "for", 0,
  "int", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

int main(){
  char word[MAXWORD];
  struct key *p = NULL;
  int i;

  while(getword(word, MAXWORD) != EOF){
    if((p = binsearch(word, keytabs)) != NULL)
      p->count++;
  }

  p = keytabs;
  for(i = 0; i < NKEYS; i++){
    printf("%s:%d\n", p->word, p->count);
    p++;
  }
  return 0;
}

static int getword(char *word, int limit){
  int c;
  while(isspace(c = getch()))
    ;

  if(c != EOF)
    *word++ = c;

  /* If its not alphabet, then return. */
  if(!isalpha(c)){
    *word = '\0';
    return c;
  }

  for(; --limit > 0; word++){
    if(!isalnum(*word = getch())){
      ungetch(*word);
      break;
    }
  }

  *word = '\0';
  return word[0];
}

struct key *binsearch(char *word, struct key *keys){
  int cond;
  struct key *low = keys;
  struct key *high = keys + NKEYS;
  struct key *mid = NULL;

  while(low < high){
    mid = low + (high - low) / 2;
    if((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if(cond > 0)
      low = mid + 1;
    else
      return mid;
  }

  return NULL;
}

static int getch(){
  return bufp > 0 ? buffer[--bufp] : getchar();
}

static void ungetch(int ch){
  if(bufp < BUF_SIZE)
    buffer[bufp++] = ch;
  else
    printf("error: buffer overflow");
}
