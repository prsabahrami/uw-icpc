#include <stdlib.h>
#include <stdio.h>

int i,j,k,m,n,c;

char proj[123];

main(){
   for (i=0;i<100;i++){
      sprintf(proj,"%d",random()+123);
      for (j=0;proj[j];j++) proj[j] += 'A'-'0';
      printf("%s\n",proj);
      n = random()%100;
      while (n--){
         sprintf(proj,"%d",random()%10000+999999);
         for (j=0;proj[j];j++) proj[j] += 'a'-'0';
         printf("%s\n",proj);
      }
   }
   printf("1\n");
   printf("0\n");
}
