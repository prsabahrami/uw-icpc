#include <iostream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

map<string, set<string>> M;
set<string> countries;
map<string, int> neww;
map<string, int> old;

int main() {
  int i, n;
  cin >> n;
  cin.ignore();
  string first;
  for(i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string dst, src;
    string dummy;
    ss >> dst;
    countries.insert(dst);
    if(i==0) first = dst;
    ss >> dummy;
    ss >> dummy;
    ss >> dummy;
    while(ss >> src) {
      M[src].insert(dst);
    }
  }
  neww[first] = 1;
  for(i = 1; i < 350; i++) {
    old = neww;
    for(auto it = countries.begin(); it != countries.end(); ++it) {
      if(old[*it] == i) {
        set<string> dsts = M[*it];
        for(auto it2 = dsts.begin(); it2 != dsts.end(); ++it2) {
          if(!neww[*it2]) neww[*it2] = i+1;
        }
      }
    }
  }
  for(auto it = countries.begin(); it != countries.end(); ++it) {
    cout << neww[*it] << endl;
  }
}
