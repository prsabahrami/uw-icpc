#include <stdio.h>
#include <string.h>

int n,m,t,i,j,c;
int arr[20000], done[20000], nl, nr, f;
char bank[20000][20],x;

#define mina (arr[nl]<arr[nr]?arr[nl]:arr[nr])

main(){
   char z;
   scanf("%d",&c);
   for (j=0;j<c;j++) {
      if(j) printf("\n");
      if (3 != scanf("%d%d%d",&n,&t,&m)) printf("short input!\n");
      for (i=0;i<m;i++) scanf("%d%s",&arr[i],bank[i]);
      arr[m] = 99999999;
      for (i=0;i<m;i++) done[i] = 0;
      for (nl=0;nl<m && bank[nl][0] != 'l';nl++);
      for (nr=0;nr<m && bank[nr][0] != 'r';nr++);
      for (f=0;nl < m || nr < m;){
         if (f < mina) f = mina;
         for (i=0;i<n && arr[nl] <= f;i++) {
            done[nl] = f+t;  
            for (;++nl<m && bank[nl][0] != 'l';);
         }
         f += t;
 
         if (f < mina) f = mina;
         for (i=0;i<n && arr[nr] <= f;i++) {
            done[nr] = f+t;
            for (;++nr<m && bank[nr][0] != 'r';);
	 }
         f += t;
      }
      for (i=0;i<m;i++) printf("%d\n",done[i]);
   }
   if (1 == scanf( " %c", &x)) printf("extra input!! %c\n",x);
}
