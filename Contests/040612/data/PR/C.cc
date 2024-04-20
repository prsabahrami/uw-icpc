#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char name[20];
  int val;
} Ag;

int cmp(const void *a, const void *b) {
  Ag *ap = (Ag *)a, *bp = (Ag *)b;
  if (ap->val < bp->val) return -1;
  if (ap->val > bp->val) return 1;
  return strcmp(ap->name,bp->name);
}

Ag A[150];

int main () {
  int M, N, L, C, w[100005];
  scanf("%d",&C);
  for (int c=1; c<=C; c++) {
    printf("Case %d\n", c);
    scanf("%d%d%d\n",&N,&M,&L);
    assert(1 <= M && M <= N && N <= 100000);
    assert(1 <= L && L <= 100);
    int a,b;
    for(int l = 0; l<L; l++) {
      scanf("%[^:]:%d,%d\n",A[l].name,&a,&b);
      for (int i=M;i<N;i++) w[i]=INT_MAX; 
      w[N]=0;
      for(int i=N;M<i;i--) {
	w[i-1] = min(w[i-1],w[i]+a);
	w[i/2] = min(w[i/2],w[i]+b);
      }
      A[l].val = w[M];
    }
    qsort(A,L,sizeof(Ag),cmp);
    for(int p = 0; p<L; p++) 
      printf("%s %d\n",A[p].name,A[p].val);
  }
  return 0;
}
