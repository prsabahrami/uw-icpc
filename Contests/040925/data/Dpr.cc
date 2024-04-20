#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[1000010];
int s[1000010];

int main (int argc, char **argv) {
  int n;
  while (scanf("%d:",&n) != EOF) {
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    memset(s,-1,n*sizeof(int));
    for(int i=0;i<n;i++) s[a[i]] = i;
    for(int i=0;i<n;i++)
      for(int d=-n+1;d<n;d++)
	if(0<=a[i]+d && a[i]+d<n && i < s[a[i]+d] &&
	   0<=a[i]+d+d && a[i]+d+d<n && s[a[i]+d] < s[a[i]+d+d]) {
	  printf("no\n");
	  goto A;
	}
    printf("yes\n");
  A: ;
  }
}
