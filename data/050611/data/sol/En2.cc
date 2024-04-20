// Too slow, n^2

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;

#define MAXN 200000

int main () {
  int n;
  int x[MAXN], y[MAXN];
  while (1) {
    scanf("%d",&n);
    if (!n) break;
    map<int,int> s, o;
    assert(0 < n && n%2 && n <= MAXN);
    for(int i=0;i<n;i++) {
      scanf("%d%d",&x[i],&y[i]);
      s[x[i]]=MAXN+10; o[x[i]] = 0;
    }
    for(int j = 0; j<n; j++) {
      int xb = x[j], yb = y[j], ss = 0, os = 0;
      for (int i = 0; i<n; i++) {
	if (x[i] < xb && y[i] < yb || x[i] > xb && y[i] > yb) ss++;
	if (x[i] < xb && y[i] > yb || x[i] > xb && y[i] < yb) os++;
      }
      if(ss <= s[x[j]]) {
	s[x[j]] = ss;
	if (os > o[x[j]]) o[x[j]] = os;
      }
    }
    int sm = 0;
    for (map<int,int>::iterator i = s.begin(); i!=s.end(); i++) 
      if (i->second > sm) sm = i->second;
    set<int> om;
    for (map<int,int>::iterator i = o.begin(); i!=o.end(); i++) 
      if (s[i->first] == sm) om.insert(i->second);
    printf("Stan: %d; Ollie:",sm);
    for (set<int>::iterator p=om.begin(); p!=om.end();p++)
      printf(" %d",*p);
    printf(";\n");

  }
  return 0;
}

