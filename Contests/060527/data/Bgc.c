#include <stdio.h>
#include <string.h>

int here,nz,i,j,k,m,n,nt,nn,h[100];
char buf[100], t[100][100];

int look(char *s){
   int i;
   for (i=0;i<nt && strcmp(t[i],s);i++);
   if (i == nt) nt++;
   strcpy(t[i],s);
   return i;
}

struct nnn {
   int p[52];
} z[100000];

main(){
   while (1 == scanf("%d",&n) && n) {
      memset(z,0,sizeof(z));
      nz = 0;
      for (i=0;i<n;i++) {
         scanf("%d",&m);
         for (j=0;j<m;j++) {
            scanf("%s",buf);
            h[j] = look(buf);
         }
         here = 0;
         for (j=m-1;j>=0;j--) {
            if (!z[here].p[h[j]]) z[here].p[h[j]] = ++nz;
            here = z[here].p[h[j]];
         }
      }
      printf("%d\n",nz);
   }
}
