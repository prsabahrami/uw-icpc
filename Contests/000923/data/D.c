#include <stdio.h>

int merits,demerits,points,lastoff,nextoff;

main(){
   scanf("%d",&lastoff);
   dump();
   for(;;){
      nextoff = 99999999;
      scanf("%d%d",&nextoff,&points);
      while ((demerits && lastoff+10000 <= nextoff) ||
             (!demerits && merits < 5  && lastoff+20000 <= nextoff)){
         if (demerits) {
            if (demerits > 2) demerits /=2; else demerits = 0;
            lastoff += 10000;
         } else {
            merits++;
            lastoff += 20000;
         }
         dump();
      }
      if (nextoff == 99999999) break;
      lastoff = nextoff;
      if (merits*2 <= points) {
         demerits += (points - merits*2);
         merits = 0;
      } else {
         merits -= ((points+1)/2);
      }
      dump();
   }
}

dump(){
   printf("%04d-%02d-%02d ",lastoff/10000,lastoff/100%100,lastoff%100);
   if (merits) printf("%d merit point(s).\n",merits);
   else if (demerits) printf("%d demerit point(s).\n",demerits);
   else printf("No merit or demerit points.\n");
}
