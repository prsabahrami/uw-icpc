#include <stdio.h>

#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

FILE *f;

int i,j,k,K;
double t,a,v,w,r,vb, vw, vr, vc, avg, amt, resid;
main(int argc, char **argv){
   if (UW) {
      char buf[100];
      strcpy(buf,argv[0]);
      strcpy(buf+strlen(buf)-3,"dat");
      f = fopen(buf,"r");
   } else f = fopen(argv[1],"r");
   while (5 == fscanf(f,"%d%lf%lf%lf%lf",&k,&vb,&vw,&vr,&vc)) {
      printf("%d %0.3lf %0.3lf %0.3lf %0.3lf ==> ",k,vb,vw,vr,vc);
      scanf("%d",&K); printf("%d",K);
      amt = vb + vw - vr;
      if (amt < 0) {
         if (K > k) {
            printf("\ntoo many rinses\n");
            exit(WRONG);
         }
         if (K == 0) {printf("\n");continue;}
         for (i=t=0;i<K;i++) {
            scanf("%lf",&a); 
            printf(" %0.2lf",a);
            if (a < 0) {
               printf("\nnegative amt\n");
               exit(WRONG);
            }
            t += a;
         }
         if (t <= vb) {printf("\n");continue;}
         printf("\ntoo much rinse water\n");
         exit (WRONG);
      }
      if (k != K) {
         printf("\nwrong number of rinses %d\n",K);
         exit(WRONG);
      }
      avg = amt/k;
      if (avg >= vc-vr) avg = vc-vr;
      if (avg >= vw-vr) {
         //printf("%d %0.2lf",k,avg-vw+vr);
         scanf("%lf",&a);
            printf(" %0.2lf",a);
         if (fabs(a-(avg-vw+vr)) > .005) {
            printf("\nwrong rinse amt %0.2lf\n",a);
            exit(WRONG);
         }
         for (i=1;i<k;i++) {
            //printf(" %0.2lf",avg);
            scanf("%lf",&a);
            printf(" %0.2lf",a);
            if (fabs(a-avg) > .005) {
               printf("\nwrong rinse amt %0.2lf\n",a);
               exit(WRONG);
            }
         }
      } else {
         avg = vb/(k-1);
         scanf("%lf",&a);
            printf(" %0.2lf",a);
         if (a) { 
            printf("\nwrong rinse amt %0.2of\n",a);
            exit(WRONG);
         }
         for (i=1;i<k;i++) {
            //printf(" %0.2lf",avg);
            scanf("%lf",&a);
            printf(" %0.2lf",a);
            if (fabs(a-avg) > .005) {
               printf("\nwrong rinse amt %0.2lf\n",a);
               exit(WRONG);
            }
         }
      }
      printf("\n");
   }
   printf("judge says OK\n");
   exit(OK);
}
