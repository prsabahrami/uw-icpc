#include <stdio.h>

int b,i,j,k,n;
long long r,m;

char P[2000], M[10];

dump(int r){
   if (!r) return;
   dump(r/b);
   printf("%d",r%b);
}

main(){
   while ((3 == scanf("%d%s%s",&b,P,M)) && b){
      m = 0;
      for (i=0;M[i];i++) m = m*b + M[i] - '0';
      r = 0;
      for (i=0;P[i];i++) {
         r = r * b + P[i] - '0';
         r %= m;
      }
      if (!r) printf("0");
      dump(r);
      printf("\n");
   }
   if(b) printf("missing end delimiter\n");
}
