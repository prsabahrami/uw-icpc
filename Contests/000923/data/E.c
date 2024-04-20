#include <stdio.h>
#include <stdlib.h>

#define dup xdup

struct s {
   int i;
   char *s;
};

struct s wd[50000], subs[400000], ins[400000];
int nw, ns, ni;

int d[50000], prev[50000];

char buf[20];

cmp(struct s *a, struct s *b){
   if (strcmp(a->s,b->s) > 0) return 1;
   if (strcmp(a->s,b->s) < 0) return -1;
   return a->i - b->i;
}

struct s dup(int i, char *s){
   struct s t;
   t.s = (char *) malloc(strlen(s)+1);
   strcpy(t.s,s);
   t.i = i;
   return t;
}

struct s sub(int i, char *s, int j){
   struct s t;
   t.s = (char *) malloc(strlen(s)+1);
   strcpy(t.s,s);
   t.s[j] = '*';
   t.i = i;
   return t;
}

struct s in(int i, char *s, int j){
   struct s t;
   t.s = (char *) malloc(strlen(s)+2);
   strncpy(t.s,s,j);
   t.s[j] = '*';
   strcpy(t.s+j+1,s+j);
   t.i = i;
   return t;
}

look(int from, char *s, struct s *t){
   int i,j,k,hi,lo,mid;
   hi = (t==subs?ns:ni)-1;
   lo = 0;
   while (hi >= lo) {
      mid = (hi+lo)/2;
      i = strcmp(s,t[mid].s);
      if (i > 0) lo = mid+1;
      else if (i < 0) hi = mid-1;
      else if (from >= t[mid].i) lo = mid+1;
      else hi = mid-1;
   } 
   for (i=lo;!strcmp(s,t[i].s);i++) {
      0&&printf ("found %s (%s) from %s\n", t[i].s, wd[t[i].i].s, wd[from].s);
      if (d[from]+1 > d[t[i].i]){
         d[t[i].i] = d[from]+1;
         prev[t[i].i] = from;
      }
   }
}

main(){
   int i,j,k;
   for (nw=0;gets(buf);nw++){
      wd[nw] = dup(nw,buf);
      for (i=0;i<strlen(buf);i++) subs[ns++] = sub(nw,buf,i);
      for (i=0;i<=strlen(buf);i++) ins[ni++] = in(nw,buf,i);
      subs[ns].s = ins[ni].s = "";
   }
   qsort(subs,ns,sizeof(struct s),cmp);
   qsort(ins,ni,sizeof(struct s),cmp);

   for (i=0;i<nw;i++){
      for (j=0;j<strlen(wd[i].s);j++) look(i,sub(i,wd[i].s,j).s,subs);
      for (j=0;j<strlen(wd[i].s);j++) look(i,sub(i,wd[i].s,j).s,ins);
      for (j=0;j<=strlen(wd[i].s);j++) look(i,in(i,wd[i].s,j).s,subs);
   }

   for (i=j=0;i<nw;i++) {
      if (d[i] > d[j]) j=i;
   }

   printf("%d\n",d[j]+1);
   0&&dump(j);
}

dump(int i){
   if (d[i] > 0) dump(prev[i]);
   printf("%s\n",wd[i].s);
}

