#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

#define FOR(i,n) for (int i=0;i<n;i++)

vector<string> from;
vector<string> to;
void addrule(const char *a, const char *b) {
 from.push_back(a); to.push_back(b);
}

void doit() {
 char buf[222];
 scanf("%s", buf);
 string s = buf;
 while (1) {
  char *p = strdup(s.c_str()), *q;
  for (int i=0;i<from.size();i++) 
   if ((q=strstr(p,from[i].c_str()))) {
    s = string(p,q) + to[i] + string(q+from[i].size());
    goto dun;
   }
  break;
  dun:;
  free(p);
 }
 printf("%s\n", s == "" ? "closed" : "open");
}

int main() {
 addrule("aa","");
 addrule("bb","");
 addrule("cc","");
 addrule("baba","abab");
 addrule("caca","acac");
 addrule("cbcb","bcbc");
 addrule("cbcabab","bcbcaba");
 int n;
 scanf("%i", &n);
 while (n--) doit();
}
