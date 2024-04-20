#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char g[100][100], s[101];

int n,i,j,k;

main(){
   for (i=0;i<20;i++){
      for (k=0;k<100;k++) g[random()%100][random()%100] = 1;
      n = 0;
      for (j=0;j<99;j++) for (k=0;k<99;k++) n += g[j][k];
      printf("%d\n",n);
      for (j=0;j<99;j++) for (k=0;k<99;k++) {
         if (g[j][k]) printf("%d %d\n",j+1,k+1); 
      }
      n = random()%98+2;
      memset(s,0,sizeof(s));
      s[0]=s[99]=1;
      for (j=0;j<n;j++) s[random()%100] = 1;
      for (n=j=0;j<100;j++) n += s[j];
      printf("%d",n);
      for (n=j=0;j<100;j++) if (s[j]) printf(" %d",j+1);
      printf("\n%d\n",random()%98+2);
   }
   printf("-1\n");
}
