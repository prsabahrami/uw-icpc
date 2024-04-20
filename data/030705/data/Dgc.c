#include <math.h>
#include <stdio.h>

double Pl, Pr, C[1100], c;  // C[m] is cost to build m in a row

int i,l,k,m,n,r;

main(){
   while (3 == scanf("%d%lf%lf",&n,&Pl,&Pr)) {
      if (Pl+Pr == 0) {
         printf("%d.00\n",n);
         continue;
      }
      C[0] = 0;
      for (i=1;i<=n;i++) C[i] = 1e19;
      for (m=1;m<=n;m++) { 
         for (l=0;l<m;l++) {   // l dominoes on the left
            r = m-l-1;
            c = 1 + C[l] + C[r] + 
                (1/(1-Pr-Pl)-1) * (1+ Pl/(Pr+Pl)*C[l] + Pr/(Pr+Pl)*C[r]);
            if (c < C[m]) C[m] = c;
         }
      }
      printf("%0.2lf\n",C[n]);
   }
}
