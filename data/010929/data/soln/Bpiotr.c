#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  const int *ap = a, *bp = b;
  if (*ap < *bp) return -1;
  if (*ap > *bp) return 1;
  return 0;
}

int main () {
  int n, i, j, k, l, cmb, cpb, c, found;
  int len, s[100], w[100], res[20];
  while(scanf("%d", &n) == 1) {
    len = n*(n-1)/2;
    for (i=0;i<len;i++) {
      scanf("%d",&s[i]);
    }
    qsort(s,len,sizeof(int),cmp);
    cmb = s[1]-s[0];
    for(i=2;i<len;i++) {
      cpb = s[i];
      if ((cmb+cpb)%2 == 0) {
	res[2] = c = (cmb+cpb)/2;
	res[1] = cpb-c;
	res[0] = s[0]-res[1];
	for(j=2;j<len;j++) w[j] = 0;
	w[i] = 1;
	for(k=3; k<n;k++) {
	  for(j=2;j<len;j++)
	    if (!w[j]) {
	      res[k] = s[j]-res[0];
	      break;
	    }
	  for(l=0;l<k;l++) {
	    found = 0;
	    for(j=2;j<len;j++) 
	      if (!w[j] && (res[l]+res[k] == s[j])) {
		w[j] = 1;
		found = 1;
		break;
	      }
	    if (!found) goto B;
	  }
	}
	goto A;
      }
    B: ;
    }
    printf("Impossible\n");
    continue;
  A: printf("%d", res[0]);
    for(i=1;i<n;i++)
      printf(" %d",res[i]);
    printf("\n");
  }
  return 0;
}
