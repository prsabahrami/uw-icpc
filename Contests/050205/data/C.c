#include <stdio.h>
#include <stdlib.h>

struct thing {
   int run, win; double p;
} p1[1000000], p2[1000000];

comp(struct thing *a, struct thing *b){
   if (a->run != b->run) return a->run - b->run;
   if (a->win != b->win) return a->win - b->win;
   return 0;
}

int pwr[] = {1,2,4,8,16,32,64,128,256,512,1024};

int i,j,k,m,n,l,n1,n2,n3,bet;

double prob, sumprob;

dump(struct thing *x, int nx, char *msg){
   int i;
   return 0;
   printf("--- %s %d\n",msg,nx);
   for (i=0;i<nx;i++){
      printf("%5d %5d %0.8lf\n",x[i].run, x[i].win,x[i].p);
   }
}

main(){
   scanf("%d",&n);
   while (n--) {
      scanf("%d%d%d",&k,&m,&l);
      n1 = 1;
      p1[0].win = 0;
      p1[0].run = 0;
      p1[0].p = 1;
      prob = 1;
      for (i=1;i<=m;i++) {
         n2 = 0;
         for (j=0;j<n1;j++) {
            bet = pwr[p1[j].run];
            // lose 10/14 of the time
            p2[n2].run = bet*2 <= l ? p1[j].run + 1 : 0;
            p2[n2].win = p1[j].win - bet;
            p2[n2++].p = p1[j].p * 10/14;
            // win 1 (2 cases)
            p2[n2].run = 0;
            p2[n2].win = p1[j].win + bet;
            p2[n2++].p = p1[j].p * 2/14;
            // win 2
            p2[n2].run = 0;
            p2[n2].win = p1[j].win + bet * 2;
            p2[n2++].p = p1[j].p * 1/14;
            // win 3
            p2[n2].run = 0;
            p2[n2].win = p1[j].win + bet * 3;
            p2[n2++].p = p1[j].p * 1/14;
         }
         dump(p2,n2,"new");
         qsort(p2,n2,sizeof(struct thing),comp);
         dump(p2,n2,"newsort");
         n1 = 0;
         sumprob = 0;
         for (j=0;j<n2;) {
            p1[n1].win = p2[j].win;
            p1[n1].run = p2[j].run;
            p1[n1].p = p2[j].p;
            for (j++;p2[j].win == p1[n1].win && p1[n1].run == p2[j].run;j++){
               p1[n1].p += p2[j].p;
            }
            if (p1[n1].win <= 0 || i < k) {
               sumprob += p1[n1].p;
               n1++; 
            }
         }
         for (j=0;j<n1;j++) p1[j].p /= sumprob;
         if (i >= k) prob *= sumprob;
         dump(p1,n1,"newer");
      }
      printf("%0.4lf\n",1-prob);
   }
}
