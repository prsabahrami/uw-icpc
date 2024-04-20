#include <stdio.h>
#include <string.h>
#include <assert.h>

char op[101][101];
int i,j,k,n,N,no;
int w[100000000];

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
   int x;
   while (2 == scanf("%d%d",&N,&n)&&N) {
      memset(w,0,sizeof(w));
      for (i=0;1 == scanf("%s",op[i]) && strcmp(op[i],"%");i++);
      no = i-1;
      w[x = n] = 1;
      for (j=2;;j++) {
         x = eval(x);
         if (w[x]) {
            printf("%d\n",j-w[x]);
            break;
         }
         w[x] = j;
      }
   }
}
