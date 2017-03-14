#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIMIT 1000
#define BUFFER_SIZE 1000


struct tnode {
  char *data;
  int count;
  struct tnode *left;
  struct tnode *right;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
char *_strdup(char *);
struct tnode *talloc();

int getch();
void ungetch(int);


int main(){
  char word[MAX_LIMIT];
  struct tnode *root = NULL;
  while(getword(word, MAX_LIMIT) != EOF){
    root = addtree(root, word);
  }

  treeprint(root);
  return 0;
}

int bufp = 0;
int buffer[BUFFER_SIZE];



int getch(){
  return bufp > 0 ? buffer[--bufp] : getchar();
}

void ungetch(int ch){
  if(bufp < BUFFER_SIZE)
    buffer[bufp++] = ch;
  else
    printf("error: buffer overflow\n");
}

int getword(char *word, int limit){
  int c;

  while(isspace(c = getch())) ;

  if(c != EOF)
    *word++ = c;

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

struct tnode *talloc(){
  return (struct tnode *)malloc(sizeof(struct tnode));
}

char *_strdup(char *word){
  char *p = (char *)malloc(strlen(word) + 1);
  p = strcpy(p, word);
  return p;
}


struct tnode *addtree(struct tnode *root, char *word){
  int cond;
  if(root == NULL){
    root = talloc();
    root->data = _strdup(word);
    root->count = 1;
    root->left = root->right = NULL;
  }else if((cond = strcmp(word, root->data)) == 0)
    root->count++;
  else if(cond < 0)
    root->left = addtree(root->left, word);
  else
    root->right = addtree(root->right, word);

  return root;
}

void treeprint(struct tnode *root){
  if(root != NULL){
    treeprint(root->left);
    printf("%s %d\n", root->data, root->count);
    treeprint(root->right);
  }
}
