#include <stdio.h>
#include <math.h>

FILE *dat;

char reach[1<<24];

double w[24], x[24], used[24], len, wt, xx, ww;
int thing[24];
int n,t;

int solve(int m) {
   int i;
   double sumt1, sumt2;
   if (reach[m]) return 0;
   reach[m] = 1;
   //printf("solve %x\n",m);
   sumt1 = 1.5 * wt;
   sumt2 = -1.5 * wt;
   for (i=0;i<n;i++) {
      if (m & (1<<i)) {
         sumt1 += w[i] * (x[i]+1.5);
         sumt2 += w[i] * (x[i]-1.5); 
      }
   }
   //printf("sumt1 %lg sumt2 %lg\n",sumt1,sumt2);
   if (sumt1 < 0 || sumt2 > 0) return 0;
   //printf("passed\n");
   if (m == 0) return 1;
   t--;
   for (i=0;i<n;i++) {
      if ((t<0 || thing[n-t-1]==i) && (m & (1<<i)) && solve(m-(1<<i))) {
          //printf("ret1\n");
         return 1;
      }
   }
   return 0;
}

char buf[1000], buf1[1000];

main(){
   int cc,i,j;
   if (NULL == (dat = fopen("/u/acm00/data/A.1.dat","r"))) perror("dat file"),exit(1);
   for (cc=1; 3 == fscanf(dat,"%lf%lf%d",&len,&wt,&n) && n; cc++) {
      memset(reach,0,1<<n);
      for (i=0;i<n;i++) fscanf(dat,"%lf%lf",&x[i],&w[i]);
      printf("Case %d:\n",cc);
      gets(buf);
      sprintf(buf1,"Case %d:",cc);
      if (strcmp(buf,buf1)) printf("Bad header %s\n",buf),exit(1); 
      t = -1;
      if (1 == scanf("%[A-Za-z] ",buf)) {
         if (strcmp(buf,"Impossible")) printf("junk in input %s\n",buf),exit(1);
         else if (solve((1<<n)-1)) printf("said Impossible but soln exists\n"),exit(1);
      }else{
         memset(used,0,sizeof(used)); 
         for (i=0;i<n;i++) {
            if (2 != scanf("%lf%lf ",&xx,&ww)) printf("bad input\n"),exit(1);
            for (j=0;j<n && (used[j]||(x[j]!=xx||w[j]!=ww));j++);
            if (j == n) printf("bad x,w %lg %lg\n",xx,ww),exit(1);
            thing[i] = j;
            used[j] = 1;
         }
         memset(reach,0,1<<n);
         t = n;
         if (!solve((1<<n)-1)) printf("not solved\n"),exit(1);
      }
   }
   printf("Judge says OK\n");
   exit(0);
}
