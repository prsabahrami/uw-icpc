// #include <sys/resource.h>

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> edges[200010];
int edge_src[2010010];
int edge_dst[2010010];
bool visited[2010010];
int enter[2010010];
int low[2010010];
char label[2010010];

int tim;

int dst(int e) {
  if(e>0) return edge_dst[e]; else return edge_src[-e];
}

void mark(int e) { 
  if(e>0) label[e] = '>';
  else label[-e] = '<';
}

void bidi(int e) {
  if(e>0) label[e] = '=';
  else label[-e] = '=';
}

bool labelled(int e) {
  if(e>0) return label[e];
  else return label[-e];
}

void dfs(int v, int ine) {
  //cout << "dfs(" << v << "," << ine << ")" << endl;
  visited[v] = true;
  tim++;
  enter[v] = tim;
  low[v] = tim;
  for(auto it = edges[v].begin(); it != edges[v].end(); ++it) {
    int e = *it;
    if(labelled(e)) continue;
    mark(e);
    int w = dst(e);
    //cout << "e" << e << " w" << w << endl;
    if(visited[w]) {
      low[v] = min(low[v], enter[w]);
    } else {
      dfs(w, e);
      low[v] = min(low[v], low[w]);
      if(low[w] > enter[v]) bidi(e);
    }
  }
}

int main() {
  //struct rlimit rl;
  //int result = getrlimit(RLIMIT_STACK, &rl);
  //rl.rlim_cur = 256*1024*1024;
  //setrlimit(RLIMIT_STACK, &rl);
  cin >> n;
  cin >> m;
  cin.ignore();
  if(!m) return 0;
  for(int i = 1; i <= m; i++) {
    int a,b;
    cin >> a;
    cin >> b;
    cin.ignore();
    edges[a].push_back(i);
    edges[b].push_back(-i);
    edge_src[i] = a;
    edge_dst[i] = b;
  }
  dfs(1,0);
  for(int i = 1; i <= m; i++) {
    cout << label[i] << endl;
  }
}
