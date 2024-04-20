#include <stdio.h>

char sz[550000];
int nbot,amt;
int minb[200], maxb[200];

int i,j,k,m,n;

main(){
   scanf("%d%d",&amt,&nbot);
   amt *= 1000;
   if (amt >= 500000) {
      printf("0\n");
      return 0;
   }
   for (i=0;i<nbot;i++) scanf("%d%d",&minb[i],&maxb[i]);

   sz[0] = 1;

   for (i=0;i<500000;i++){
      if (!sz[i]) continue;
      for (j=0;j<nbot;j++){
         for (k=minb[j];k<=maxb[j];k++)  sz[i+k] = 1;
      }
   }

   for (i=amt;!sz[i];i--);

   printf("%d\n",amt-i);
}
