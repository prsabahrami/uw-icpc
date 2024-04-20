#include <stdio.h>
#include <math.h>

int g,i,j,k,m,n,term,rep,q,num,den;
int bestn, bestd;
char d[10], a[10], b[10], c[10];

gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b,a%b);
}

main(){
   while (1 == scanf(" 0.%[0-9]...",d)) {
      bestn=bestd=1000000000;
      for (i=0;d[i];i++) {
         strncpy(a,d,i);
         a[i] = 0;
         strcpy(b,d+i);
         num = atoi(a) * (pow(10,strlen(b))-1) + atoi(b);
         den = pow(10,i) * (pow(10,strlen(b))-1);
         g = gcd(num,den);
         num /= g; den /=g;
         if (den < bestd) {
            bestn = num; bestd = den;
         }
      }
      printf("%d/%d\n",bestn,bestd);
   }
}
