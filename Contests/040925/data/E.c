#include <stdio.h>
#include <string.h>

char c[256][256], d[256], x[256];
int i,j,k,n,t;

main(){
   while (1 == scanf("%d",&n) && n) {
      if (t++) printf("\n");
      memset(c,0,sizeof(c));
      memset(d,0,sizeof(d));
      for (i=0;i<n;i++) {
         for (j=0;j<6;j++) scanf(" %c",&x[j]);
         for (j=0;j<6;j++) c[x[5]][x[j]] = 1;
         for (j=0;j<6;j++) d[x[j]] = 1;
      }
      for (i='A';i<='Z';i++) for (j='A';j<='Z';j++) for (k='A';k<='Z';k++)
         c[j][k] |= (c[j][i] && c[i][k]);
      for (i='A';i<='Z';i++) {
         if (!d[i]) continue;
         d[i] = 0;
         printf("%c",i);
         for (j=i+1;j<='Z';j++) {
            if (c[i][j] && c[j][i]) {
               printf(" %c",j);
               d[j] = 0;
            }
         }
         printf("\n");
      }
   }
   if (n) printf("missing end delimiter\n");
}
