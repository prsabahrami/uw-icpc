#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j,k,f,r;
int ff[200], rr[200];

main(){
   for (i=0;i<78;i++) {
      f = random()%5+1;
      r = random()%10+1;
if(i==15) continue;
if(i==62) continue;
if(i==63) continue;
if(i==81) continue;
if(i==82) continue;
      printf("%d %d\n",f,r);
      for (j=0;j<f;j++) {
         while (ff[k=random()%91+10] == i+1);
         ff[k] = i+1;
         if(j) printf(" ");
         printf("%d",k);
      }
      printf("\n");
      for (j=0;j<r;j++) {
         while (rr[k=random()%91+10] == i+1);
         rr[k] = i+1;
         if(j) printf(" ");
         printf("%d",k);
      }
      printf("\n");
   }
   printf("0\n");
}
