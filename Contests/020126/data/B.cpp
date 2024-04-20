#include <stdio.h>
#include <map>
#include <math.h>

map<unsigned,unsigned> M;

unsigned long
times (unsigned long a, unsigned long b, unsigned long m){
   return (unsigned long long) a * b % m;
}

unsigned long
power (unsigned long val, unsigned long power, unsigned long m){
   unsigned long acc = 1;
   unsigned long p;

   for (p = power; p ; p=p>>1) {
      if (p & 1) acc = times(acc, val, m);
      val = times(val, val, m);
   }
   return acc;
}

main(){
   unsigned P,B,L,N;
   unsigned i,j,k,m,n;
   unsigned jump;
   while (scanf("%d %d %d",&P,&B,&N) == 3) {
      M.clear();
      jump = sqrt(P);
      for (i=0;i<jump && i < P-1;i++){
         M[power(B,i,P)] = i+1;
      }
      for (i=0;i<P-1;i+=jump){
         if (j = M[times(N,power(B,P-1-i,P),P)]) {
            j--;
            L = (i+j)%(P-1);
            if (power(B,L,P) != N) printf("***oops*** %d %d ",i,j);
            printf("%d\n",L);
            goto done;
         }
      }
      printf("no solution\n");
      done:;
   }
} 
