#include <stdio.h>
#include <string.h>

char buf[101000], cb1[101000], cb2[101000], *c[101000];

int comp(char **a, char **b) {
   return strcmp(*a,*b);
}

struct ss {
   char *p;
   int len;
} s[101000];

int comps(struct ss *a, struct ss *b) {
   if (a->len != b->len) return b->len - a->len;
   return a->p - b->p;
}

int n1, n2, ns, i, j, k, m, prev, hi, lo, mid, other, C;

main(){
   while (1 == scanf("%d ",&k) && k) {
      if (C++) printf("\n");
      printf("CASE %d\n",C);
      gets(buf);
      n1 = n2 = ns = 0;
      while (gets(buf) && strcmp(buf,"END TDP CODEBASE")) {
         strcpy(cb1+n1,buf);
         n1 += strlen(buf);
         strcpy(cb1+n1++,"\n");
      }
      gets(buf);
      while (gets(buf) && strcmp(buf,"END JCN CODEBASE")) {
         strcpy(cb2+n2,buf);
         n2 += strlen(buf);
         strcpy(cb2+n2++,"\n");
      }
      for (i=0;i<n1;i++) c[i] = cb1+i;
      qsort(c,n1,sizeof(char *),comp);
      prev = 0;
      for (i=0;i<n2;i++) {
         lo = 1;
         hi = n1-2;
         while (hi >= lo) {
            mid = (hi + lo)/2;
            int t = strcmp(cb2+i, c[mid]);
            if (t < 0) hi = mid-1;
            else lo = mid+1;
         }
         if (lo > mid) other = lo;
         else other = hi;
         for (j=0;c[mid][j] && c[mid][j] == cb2[i+j];j++);
         for (m=0;c[other][m] && c[other][m] == cb2[i+m];m++);
         if (m > j) j = m;
         if (j && j >= prev) {
            s[ns].p = cb2+i;
            s[ns++].len = j;
         }
         prev = j;
      }
      qsort(s,ns,sizeof(struct ss),comps);
      for (j=i=0;i<k && i<ns;i++) {
         printf("INFRINGING SEGMENT %d LENGTH %d POSITION %d\n",
               ++j,s[i].len,s[i].p-cb2);
         for (m=0;m<s[i].len;m++) printf("%c",s[i].p[m]);
         printf("\n");
      }
   }
   if (k) printf("missing end delimiter\n");
}
