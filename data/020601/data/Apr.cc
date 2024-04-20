#include <stdio.h>
#include <string.h>

int main () {
  int n,m, v[2000];
  char k[2000][20];
  scanf("%d%d ",&m,&n);
  for (int i = 0; i < m; i++)  scanf("%s %d", &k[i], &v[i]);

  char w[20];
  for (;n;n--) {
    int sum = 0;
    while (1) {
      scanf("%s", w);
      if (!strcmp(w,".")) { printf("%d\n",sum); break; }
      for (int i = 0; i < m; i++) 
	if (!strcmp(w,k[i]))
	  sum += v[i];
    }
  }
  return 0;
}
