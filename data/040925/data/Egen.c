#include <stdio.h>
#include <stdlib.h>

int ii,z,i,j,k,m,n,x[6],a[26];

main(){
   for (ii=1;ii<=250;ii++) {
      i = ii/5+2;
      printf("%d\n",i);
      for (z=0;z<i;z++) {
         for (j=0;j<26;j++) a[j] = 'A'+ j;
         for (j=0;j<5;j++) {
            m = random()%(26-j);
            x[j] = a[m];
            for (m;m+1<26;m++) a[m] = a[m+1];
            if (j) printf(" ");
            printf("%c",x[j]);
         }
         printf(" %c\n",x[random()%5]);
      }
   }
   printf("0\n");
}
