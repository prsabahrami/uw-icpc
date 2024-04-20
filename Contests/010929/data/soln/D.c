#include <stdio.h>
#include <math.h>

double w,h,l,H,bw,bh,bl;

int easy(double, double, double);

main(){
   while (4 == scanf("%lf%lf%lf%lf",&w, &h, &l, &H)) {
      scanf("%lf%lf%lf",&bw,&bh,&bl);
      if (easy(bw,bh,bl) || easy(bw,bl,bh) || easy(bh,bw,bl) ||
          easy(bh,bl,bw) || easy(bl,bw,bh) || easy(bl,bh,bw)) 
             printf("The box goes on the truck.\n");
      else   printf("The box will not go on the truck.\n");
   }
}

easy(double bw, double bh, double bl){
   double theta, phi, height, width, length, skew, diag;
   //printf("easy whl %lf %lf %lf %lf %lf %lf H %lf\n",w,h,l,bw,bh,bl,H);
   if (bw > w || bh > h || bl > l) return 0;
   if (bh <= H) return 1;
   //printf("flunked H test\n");
   if (bl <= H) {  // tilt forward
      theta = asin(bl/H);
      height = hypot(bh,bl);
      length = bh * sin(theta);
      //printf("bw %lf bh %lf bl %lf H %lf theta %lf height %lf length %lf\n",bw,bh,bl,H,theta,height,length);
      //printf("try forward tilt\n");
      if (height <= h && length <= l) return 1;
      if (height > h) fprintf(stderr,"truck not high enough to tilt forward\n");
      if (length > l) fprintf(stderr,"truck not long enough to tilt forward\n");
   }
   diag = hypot(bw,bh);
   if (diag <= h && bw <= H) {
      skew = atan(bw/bh);
      phi = acos(H/diag);
      theta = skew + phi;
      width = bw * cos(theta) + bh * sin(theta);
      height = hypot(bw,bh);
      //printf("try sideways tilt\n");
      if (width <= w && height <= h) return 1;
      if (width > w) fprintf(stderr,"truck not wide enough to tilt sideways\n");
      if (height > h) fprintf(stderr,"truck not high enough to tilt sideways\n");
   } else {
      if (diag > h) fprintf(stderr,"truck not high enough to tilt sideways\n");
      if (bw > H) fprintf(stderr,"door not high enough to tilt sideways\n");
   }
   return 0;
}
