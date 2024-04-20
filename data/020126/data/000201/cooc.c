#include <stdio.h>

char s[1000001];
char buf[100];
int n;
char key[128];
int count[128];
int need;
int mini,minlen,mincnt;

main(){
   int i,j,k,m;
   while (*gets(s)) {
      n = strlen(s);
      while (*gets(s+n)) n += strlen(s+n);
      gets(buf);

      for (i=0;i<128;i++) key[i] = count[i] = 0;
      for (i=0;buf[i];i++) key[buf[i]] = 1;
      need = strlen(buf);
      minlen = 999999999;
      mini = 999999999;
      mincnt = 0;
 
      for (i=j=0;s[j];j++){
         if (!key[s[j]]) continue;
         if (0 != count[s[j]]++ || --need) continue;
         for(;!need;i++) {
            /* i to j is a solution */
            if (j-i+1 < minlen) {
               minlen = j-i+1;
               mini = i;
               mincnt = 1;
            } else if (j-i+1 == minlen) mincnt++;
              
            if (!key[s[i]]) continue;
            if (0 == --count[s[i]]) ++need;
         }
      }
      printf("%d\n\n",mincnt);
      if (mincnt) {
         while (minlen > 72) {
            strncpy(buf,s+mini,72);
            buf[72] = 0;
            printf("%s\n",buf);
            mini+=72;
            minlen-=72;
         }
         strncpy(buf,s+mini,minlen);
         buf[minlen] = 0;
         printf("%s\n",buf);
         printf("\n");
      }

      gets(buf); /* blank line */
   }
}
