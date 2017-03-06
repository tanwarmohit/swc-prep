#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;

  while(low < high)
  {
    //printf("low: %d, high: %d\n", low, high);
    mid = (low + high) / 2;
    if(x <= v[mid])
      high = mid;
    else
      low = mid + 1;
  }

  return x == v[low] ? low : -1;
}

int main(void)
{
  srand(time(NULL));

  int i, N, *v, x;
  N = 20;
  v = (int *) malloc(sizeof(int) * N);

  for(i = 0; i < N; i++)
  {
    v[i] = rand() % 100;
    printf("%d ", v[i]);
  }

  printf("\n");
  qsort(v, N, sizeof(int), cmpfunc);

  for(i = 0; i < N; i++)
    printf("%d ", v[i]);

  printf("\n");

  x = rand() % 100;
  printf("Search for:%d, %d\n", x, binsearch(x, v, N));
  return 0;
}
