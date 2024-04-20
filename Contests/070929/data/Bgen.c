#include <stdio.h>
#include <stdlib.h>

int i,j,k,m,n;

dump(){
   int q = random() % 1000;
   if (q>470) printf("%d",random()-0x3fffffff);
   else {
      printf("(%0.6lf ",(double)random()/0x7fffffff);
      dump();
      printf(" ");
      dump();
      printf(")");
   }
}

main(){
   printf("0\n1238\n");
   printf("(0 100 1000)\n");
   printf("(1 100 1000)\n");
   for (i=0;i<20;i++){
      dump(); printf("\n");
   }
   printf("()\n");
}
