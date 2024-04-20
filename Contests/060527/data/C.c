#include <stdio.h>
#include <string.h>
#include <assert.h>

char op[101][101];
int i,j,k,n,N,no;

int eval(int x){
   int i,j;
   int stack[101], n=0;
   for (i=0;i<no;i++){
      if (!strcmp(op[i],"x")) {
         stack[n++] = x;
      } else if (!strcmp(op[i],"+")) {
         stack[n-2] = (stack[n-2]+stack[n-1])%N;
         n--;
      } else if (!strcmp(op[i],"*")) {
         stack[n-2] = ((long long)stack[n-2]*stack[n-1])%N;
         n--;
      } else {
         stack[n++] = atoi(op[i]);
      }
   }
   assert (n == 1);
   return stack[0];
}
      
main(){
   int x,xx;
   while (2 == scanf("%d%d",&N,&n)&&N) {
      for (i=0;1 == scanf("%s",op[i]) && strcmp(op[i],"%");i++);
      no = i-1;
      x = xx = n;
      for (j=1;;j++) {
         x = eval(x);
         xx = eval(xx);
         xx = eval(xx);
         if (x == xx) {
            for (k=1;x != (xx=eval(xx));k++);
            printf("%d\n",k);
            break;
         }
      }
   }
}
