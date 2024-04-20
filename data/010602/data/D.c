#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int c,i,j,k,n,wn;

char w[10001][100], buf[1000];

main(){
   
   while (1 == scanf("%d",&n)) {
      if (c++) printf("\n");
      wn = 0;
      for (;;) {
         if (1 != scanf("%[^a-zA-Z]",buf)) break;
         if (1 != scanf("%[a-zA-Z]",buf)) break;
         if (!strcmp(buf,"EndOfText")) break;
         for (i=0;buf[i];i++) buf[i] = tolower(buf[i]);
         strcpy(w[wn++],buf);
      }
      qsort(w,wn,100,strcmp);
      strcpy(w[wn++],"***");
      strcpy(buf,"$$$");
      for (i=j=0;i<wn;i++) {
         if (strcmp(buf,w[i])) {
            if (strcmp(buf,"$$$") && k == n) printf("%s\n",buf),j=1;
            strcpy(buf,w[i]);
            k = 0;
         }
         k++;
      }
      if (!j) printf("There is no such word.\n");
   }
}
