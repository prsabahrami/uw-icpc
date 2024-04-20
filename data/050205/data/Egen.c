#include <stdio.h>
#include <stdlib.h>

int i,j,k,m,n,perm[75], board[5][5];

seq(){
   for (i=0;i<75;i++) {
      perm[i] = i;
   }
   for (i=0;i<75;i++) {
      j = random()%75;
      m = perm[i];
      perm[i] = perm[j];
      perm[j] = m;
   }
   for (i=0;i<75;i++) {
      printf("%d",perm[i]+1);
      if (i%15 == 14) printf("\n");
      else printf(" ");
   }
}

doboard(){
   for (i=0;i<5;i++) {
      for (j=0;j<5;j++) {
        again:
         k = random()%15 + j*15;
         for (m=0;m<i;m++) {
            if (k == board[m][j]) goto again;
         }
         board[i][j] = k;
      }
   }
   for (i=0;i<5;i++){
      for (j=0;j<5;j++){
         if (i != 2 || j != 2){
            printf("%d",board[i][j]+1);
         }
         if (j == 4) printf("\n");
         else if (i!=2 || j!=2) printf(" ");
      }
   }
}

main(){
   int i;
   printf("25\n");
   for (i=0;i<25;i++) {
      doboard();
      seq();
   }
}
