#include <iostream>

using namespace std;

double TOL = 1e-6;
int l,w,n,i,j;
int x[105], y[105];
bool visited[105];
double mid;

bool go(int i) {
  //cout << "going " << x[i] << " " << y[i] << endl;
  if(visited[i]) return false;
  visited[i] = true;
  if(w - y[i] < mid) return true;
  for(int j = 0; j < n; j++) {
    double d = ((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]));
    if(d < 4*mid*mid) if(go(j)) return true;
  }
  return false;
}

bool doable() {
  for(i = 0; i < n; i++) visited[i] = false;
  for(i = 0; i < n; i++) {
    //cout << y[i] << " " << mid << endl;
    if(y[i] < mid) if(go(i)) return false;
  }
  return true;
}

int main() {
  cin >> l >> w >> n;
  for(i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  double hi = w, lo = 0;
  while(hi-lo > TOL) {
    mid = .5*(hi+lo);
    //cout << lo << " " << mid << " " << hi << endl;
    if(doable()) lo = mid; else hi = mid;
  }
  cout << mid << endl;
}
