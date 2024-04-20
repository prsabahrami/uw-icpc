#include <stdio.h>
#include <string.h>

char s[200];
int i,j,vars, bins, uns;

main(){
   while (1 == scanf("%s",s) && strcmp(s,"0")) {
      vars = bins = uns = 0;
      for (i=0;s[i];i++) {
         if (s[i] >='p' && s[i] <= 't') vars++;
         else if (s[i] == 'N') uns++;
         else bins++;
      }
      if (!vars) {
         printf("no WFF possible\n");
         continue;
      }
      if (vars > bins+1) vars = bins+1;
      for (i=0;i<uns;i++) printf("N");
      for (i=j=0;s[i] && j+1 < vars;i++) {
         if (s[i] < 'Z' && s[i] != 'N') {
            printf("%c",s[i]);
            j++;
         }
      }
      for (i=j=0;s[i] && j < vars;i++) {
         if (s[i] > 'a') {
            printf("%c",s[i]);
            j++;
         }
      }
      printf("\n");
   }
   if (strcmp(s,"0")) printf("wrong input\n");
}
