#include <stdio.h>
#include <assert.h>

#define MAXK 11000

int main () {
  int d, s, i, gd, price;
  int A[MAXK];
  for (i=1;i<MAXK;i++) A[i]=5000;
  for (i=1;i<=100;i++) A[i] = 0;
  scanf("%d",&d);
  assert(1 <= d && d <= 10000);
  while(scanf("%d%d",&gd,&price) == 2) {
    assert(gd <= d);
    for(i=1;i<=200;i++) 
      if(A[gd+i] > price)
	A[gd+i] = price;
  }
  s = 0;
  for(i=1;i<=d+100;i++) {
    if (A[i] == 5000) {
      printf("Impossible\n");
      return 0;
    }
    s+=A[i];
  }
  printf("%d\n",s);
  return 0;
}
