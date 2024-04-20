/* Work Reduction sample solution */
/* Gilbert Lee */
/* Idea: Dynamic programming for each agency, then sort */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Minimum function */
#define min(a,b) (((a)<(b))?(a):(b))

typedef struct{
  char name[20];
  int cost;
} Agency;

/* Compare first by cost, then by name */
int cmp_A(Agency *a, Agency *b){
  if(a->cost - b->cost) return a->cost - b->cost;
  return strcmp(a->name, b->name);
}

int best[100005];

int main(){
  int tnum, i, j, t, N, M, L, A, B;

  Agency a[105];

  /* Get # of cases */
  scanf("%d", &tnum);

  /* For each test case */
  for(t = 1; t <= tnum; t++){
    printf("Case %d\n", t);
    scanf("%d %d %d", &N, &M, &L);
    for(i = 0; i < L; i++){
      scanf(" %[^:]:%d,%d", a[i].name, &A, &B);
      /* Dynamic programming to determine best cost to get from N to j */
      best[N] = 0;

      for(j = N-1; j >= M; j--){
	best[j] = best[j+1]+A;                                /* reduce by 1 */
	if(j*2   <= N) best[j] = min(best[j], best[j*2]+B);   /* division by 2 */
	if(j*2+1 <= N) best[j] = min(best[j], best[j*2+1]+B); /* division by 2 with rounding */
      }
      /* The best cost of N->M */
      a[i].cost = best[M];
    }
	/* Sort agencies */
    qsort(a, L, sizeof(a[0]), (void *)cmp_A);

    /* Print table */
    for(i = 0; i < L; i++)
      printf("%s %d\n", a[i].name, a[i].cost);

  }
  return 0;
}
