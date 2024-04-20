/* There's a 5-case analytic solution but why bother? */

#include <stdio.h>

main(){
   int i,j,k,m,n,s,d;

   while (2 == scanf("%d%d",&s,&d)){
      int best = -9999999, tot;
      for (i=0;i<4096;i++){
         for (j=0;j<8;j++){
            for (tot=k=0;k<5;k++) tot += ((i>>(j+k))&1)?s:-d;
            if (tot >= 0) break;
         }
         if (j<8) continue;
         for (tot=j=0;j<12;j++) tot += ((i>>j)&1)?s:-d;
         if (tot > best) best = tot;
      }
      if (best > 0) printf("%d\n",best);
      else printf("Deficit\n");
   }
}
