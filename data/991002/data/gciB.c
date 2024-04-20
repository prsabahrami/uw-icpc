#include <stdio.h>

int facts[11000];

int factors(int n, int m){
   int i,j,k;

   for (i=2;i*i<=n;i++){
      while (n%i == 0) {
         facts[i] += m;
         n /= i;
      }
   }
   facts[n] += m;
}

main(){
   int p,q,r,s,i;
   double z;

   while (4 == scanf("%d%d%d%d",&p,&q,&r,&s)){
      if (p-q < q) q = p - q;
      if (r-s < s) s = r - s;

      for (i=0;i<11000;i++) facts[i] = 0;

      for (i=0;i<q;i++){
         factors(p-i,1);
         factors(q-i,-1);
      }

      for (i=0;i<s;i++){
         factors(r-i,-1);
         factors(s-i,1);
      }

      z = 1.0;
      for (i=2;i<11000;i++){
         for (;facts[i]>0;facts[i]--) z *= i;
         for (;facts[i]<0;facts[i]++) z /=i;
      }

      printf("%0.5lf\n",z);
   }
}
         
