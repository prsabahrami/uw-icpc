#define UW (!strcmp(argv[0]+strlen(argv[0])-4,".cmd"))

#define WRONG (UW?1:2)
#define FORMAT (UW?2:1)
#define OK 0

#include <stdio.h>
#include <math.h>

double amt,dist,i,r,x,y,xx,yy,X,Y,dx,dy,dd,c;
char dir[1000],tmp[1000];
int moves;
int result = OK;

main(int argc, char **argv){
   FILE *d;
   if (UW) {
      char tmp[1000];
      strcpy(tmp,argv[0]);
      strcpy(tmp+strlen(tmp)-3,"dat");
      d = fopen(tmp,"r");
   } else {
      d = fopen(argv[1],"r");
   }

   while (5 == fscanf(d,"%lf%lf%lf%lf%lf",&r,&x,&y,&X,&Y)) {
      if (c++) {
         if (!gets(tmp) || tmp[0]) {
            printf("expecting blank line, got: %s\n",tmp);
            result = FORMAT;
         }
      }
      printf("input: %0.10lf %0.10lf %0.10lf %0.10lf %0.10lf\n",r,x,y,X,Y);
      dx = fabs(X-x);
      dy = fabs(Y-y);
      if (dx == 0 || dy == 0 || dx == dy) {
         moves = 1;
         dist = hypot(dx,dy);
      } else {
         moves = 2;
         dd = dx < dy ? dx : dy;
         dist = dd * sqrt(2.0) + dx - dd + dy - dd;
      }
      for (i=0;i<moves;i++) {
         if (!*tmp && !gets(tmp)) {
            printf("short input\n");
            exit(WRONG);
         }
         printf("       %s\n",tmp);
         if (2 != sscanf(tmp,"%s%lf",dir,&amt)) {
            printf("invalid instruction\n");
            exit(WRONG);
         }
         dist -= amt;
         if (!strcmp(dir,"north")) y += amt;
         else if (!strcmp(dir,"south")) y -= amt;
         else if (!strcmp(dir,"east")) x += amt;
         else if (!strcmp(dir,"west")) x -= amt;
         else if (!strcmp(dir,"northeast")) {x+=amt/sqrt(2.0);y+=amt/sqrt(2.0);}
         else if (!strcmp(dir,"southeast")) {x+=amt/sqrt(2.0);y-=amt/sqrt(2.0);}
         else if (!strcmp(dir,"southwest")) {x-=amt/sqrt(2.0);y-=amt/sqrt(2.0);}
         else if (!strcmp(dir,"northwest")) {x-=amt/sqrt(2.0);y+=amt/sqrt(2.0);}
         else {
            printf("invalid instruction\n");
            exit(WRONG);
         }
         if (hypot(x,y) > r+1e-8) {
            printf("off island %0.10lf %0.10lf r %0.10lf hypot %0.10lf\n",x,y,r,hypot(x,y));
            exit(WRONG);
         }
         *tmp = 0;
      }
      if (hypot(x-X,y-Y) > 1e-8) {
         printf("missed! got to %0.10lf %0.10lf instead of %0.10lf %0.10lf\n",
                            x,y,X,Y);
         exit(WRONG);
      }
      if (fabs(dist) > 1e-8) {
         printf("wrong length ... residual %0.10lf\n",dist);
      }
      printf("PASS\n");
   }
   if (r != -1) printf("Invalid terminator\n");
   printf("Judge says %s\n",result==OK?"OK":"Format Error");
   exit(result);
}
