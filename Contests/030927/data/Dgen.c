#include <stdio.h>
#include <string.h>

#define N 100

int z,i,j,k,m,n;

int c[100][100];
int e[100];

main(){
   for (z=0;z<30;z++) {
      memset(c,0,sizeof(c));
      for (i=0;i<N;i++) e[i] = random()%201-100;
      for (i=50;i<N;i++) e[i] = -100;
      e[0] = e[N-1] = 0;
      for (i=1;i<N;i++) c[i-1][i] = 1;
      for (k=0;k<100;k++){
         i = random()%100; 
         j = random()%100;
         if (i > j) c[i][j] = 1;
      }
      for (m=0;m<1+(z==10);m++){
         printf("100\n");
         if (m>0) {
            c[50][51] = 0;
         }
         for (i=0;i<100;i++) {
            for (j=k=0;j<100;j++) k += c[i][j];
            printf("%d %d",e[i],k);
            for (j=0;j<100;j++) if (c[i][j]) printf(" %d",j+1);
            printf("\n");
         }
      }
   }
   printf("-1\n");
}
