#include <stdio.h>
#include <assert.h>

#define MAX  300000

char primes[MAX], sprimes[MAX];
int cnt[MAX];

int main () {
  for (int i=1;i<MAX;i++)
    for(int j=1;4*i*j+i+j<MAX;j++)
      primes[4*i*j+i+j] = 1;
  for (int i=1;i<MAX;i++)
    for(int j=1;4*i*j+i+j<MAX;j++)
      if (!primes[i] && !primes[j]) 
	sprimes[4*i*j+i+j] = 1;
  int c = 0;
  for(int i=1;i<MAX;i++) {
    if (sprimes[i]) c++;
    cnt[i]=c;
  }
  while (1) {
    int h;
    scanf("%d",&h);
    if (!h) break;
    assert(!((h-1)%4));
    printf("%d %d\n",h,cnt[(h-1)/4]);
  }
}
