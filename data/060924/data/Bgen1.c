#include <stdio.h>
#include <stdlib.h>

#define N 2000
#define G 40

int i,j;

main(){
   printf("%d\n",2 + 2*N + N/G * (N-G-1) * 2);
   for (i=0;i<=N-G;i+=G) {
      for (j=1;j<=N-G;j++) {
         printf("%d %d\n",i,j);
      }
      for (j=N-G;j>=1;j--) {
         printf("%d %d\n",i+1,j);
      }
      for (j=2;j<G;j++) {
         printf("%d %d\n",i+j,1);
      }
   }
   printf("%d %d\n",N,1);
   for (i=N;i>=0;i--){
      printf("%d %d\n",i,0);
   }
   printf("%d\n",2 + 2*N + N/G * (N-G-1) * 2);
   for (i=N;i>=G;i-=G) {
      for (j=0;j<G/2-1;j++){
         printf("%d %d\n",i-j,N-1);
      }
      for (j=N-1;j>=G;j--){
         printf("%d %d\n",i-G/2+1,j);
      }
      for (j=G;j<=N-1;j++) {
         printf("%d %d\n",i-G/2,j);
      }
      for (j=G/2+1;j<G;j++) {
         printf("%d %d\n",i-j,N-1);
      }
   }
   printf("%d %d\n",0,N-1);
   for (i=0;i<=N;i++) {
      printf("%d %d\n",i,N);
   }
   printf("0\n");
}
