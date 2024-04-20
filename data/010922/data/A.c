#include <stdio.h>

main(){
   int hh, mm, ss, speed=0, newspeed, i, j, k, n, time = 0, now;
   char buf[10000];
   double dist = 0;

   while (gets(buf)) {
      n = sscanf(buf,"%d:%d:%d %d",&hh,&mm,&ss,&newspeed);
      now = hh*3600 + mm*60 + ss;
      dist += (now - time) / 3600. * speed;
      time = now;
      if (n == 3) printf("%02d:%02d:%02d %0.2lf km\n",hh,mm,ss,dist);
      else if (n == 4) speed = newspeed;
      else printf("oops!\n");
   }
}
