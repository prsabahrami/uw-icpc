#include <stdio.h>
#include <stdlib.h>

int z,less,need,more,i,j,k,m,n,s[2];
double r;

main(){
   for (i=2;i<=100;i+=1) {
      for (z=1;z<=10;z*=3){
         printf("%d\n",i);
         r = 1;
         for (j=random()%30;j--;) r *= .5;
         s[0] = s[1] = 0;
         for (j=0;j+1<i;j++) {
            k = (z-1)*1000000+random()%1000000;
            s[random()%2] += k;
            printf("%0.10lf\n",r*k);
         }
         less = s[0]<s[1]?s[0]:s[1];
         more = s[0]>s[1]?s[0]:s[1];
         need = more*.991;
         fprintf(stderr,"%d %d %d\n",need,less,more);
         if (need > less) printf("%0.10lf\n",(need-less)*r);
         else printf("%0.10lf\n",r);
      }
   }
   printf("0\n");
}
