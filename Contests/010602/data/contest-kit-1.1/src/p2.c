#include <stdio.h>
#include <stdlib.h>

int set[1000];

struct ss {
   int val, x, y;
} sum[500000], diff[500000];

int i,j,k,n,ab,cd,cc,best,nn;

comp(struct ss *a, struct ss *b) {
   return a->val - b->val;
}

main(){
   while (1 == scanf("%d",&n)) {
      if (!n) break;
      nn = 0;
      for (i=0;i<n;i++) scanf("%d",&set[i]);
      for (i=0;i<n;i++) for (j=i+1;j<n;j++) {
         sum[nn].x = diff[nn].x = set[i];
         sum[nn].y = diff[nn].y = set[j];
         sum[nn].val = set[i]+set[j];
         diff[nn++].val = set[i]-set[j];
      }
      qsort(sum,nn,sizeof(struct ss),comp);
      qsort(diff,nn,sizeof(struct ss),comp);  
      best = 0xffffffff;
      cc = nn-1;
      for (ab=cd=0;ab<nn;ab++) {
         while (cd < nn && diff[cd].val < sum[ab].val) cd++;
         for (i = cd; i < nn && diff[i].val == sum[ab].val; i++) {
            if (diff[i].x <= best) continue;
            if (sum[ab].x == diff[i].x) continue;
            if (sum[ab].x == diff[i].y) continue;
            if (sum[ab].y == diff[i].x) continue;
            if (sum[ab].y == diff[i].y) continue;
            best = diff[i].x;
         }
         while (cc >= 0 && -diff[cc].val < sum[ab].val) cc--;
         for (i = cc; i >= 0 && -diff[i].val == sum[ab].val; i--) {
            if (diff[i].y <= best) continue;
            if (sum[ab].x == diff[i].x) continue;
            if (sum[ab].x == diff[i].y) continue;
            if (sum[ab].y == diff[i].x) continue;
            if (sum[ab].y == diff[i].y) continue;
            best = diff[i].y;
         }
      }
      if (best == 0xffffffff) printf("no solution\n");
      else printf("%d\n",best);
   }
}
