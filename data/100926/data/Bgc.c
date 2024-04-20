#include <stdio.h>
#include <assert.h>

int i,j,n, s[2000];
main(){
   while (1 == scanf("%d",&n) && n) {
      for (i=0;i<n;i++) scanf("%d",&s[i]);
      for (i=0;i<1322;) {
         for (j=0;j < n && (s[j] <= i || s[j] > i+200); j++) {}
         if (j == n) break;
         i = s[j];
      }
      if (i < 1322) printf("IMPOSSIBLE\n");
      else printf("POSSIBLE\n");
   }
   assert(!n);
}
