#include <stdio.h>

int cperg[] = {9,4,4,4,7};

int i,j,k,m,n,q[5];
double cals, percent, totfat, totcal;
char u[5];

main(){
   for (;;) {
      totfat = totcal = 0;
      for (n=0;;n++){
         cals = percent = 0;
         for (i=0;i<5;i++) {
            if (2 != scanf("%d%c",&q[i],&u[i])) break;
            if (u[i] == 'C') cals += q[i];
            if (u[i] == 'g') cals += q[i]*cperg[i];
            if (u[i] == '%') percent += q[i];
         }
         if (i == 0) break;
         cals = cals * 100 / (100-percent);
         totcal += cals;
         if (u[0] == 'C') totfat += q[0];
         if (u[0] == 'g') totfat += q[0]*9;
         if (u[0] == '%') totfat += q[0]*cals/100;
      }
      if (n == 0) break;
      printf("%0.0lf%%\n",100*totfat/totcal);
   }
}
