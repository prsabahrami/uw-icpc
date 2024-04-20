#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <cassert>

using namespace std;

int grid[105][105];

//set<int> neg[105];
//set<int> pos[105];

set<pair<int,int>> meet[105];

set<int> caught[105][105];


void printset(set<int> s) {
  for(auto it = s.begin(); it != s.end(); ++it) {
    cout << *it << " ";
  }
}

int n, m, t;

void dumpgrid() {
  for(int person=1; person <= n; person++) {
    for(int day = 0; day <= 101; day++) {
      if(grid[day][person] < 0) cout << "-";
      else if(grid[day][person] > 0) cout << "+";
      else cout << "?";
    }
    cout << endl;
  }
}

void mkneg(int day, int person) {
  assert(person <= n);
  assert(person >= 1);
  if(grid[day][person] > 0) {
    assert(0);
  }
  if(grid[day][person] < 0) return;
  grid[day][person] = -1;
  // cout << "mkneg[" << day << "] " << person << endl;
  if(day > 0) {
    mkneg(day-1, person);
    for(auto it = meet[day-1].begin(); it != meet[day-1].end(); ++it) {
      int a = it->first, b = it->second;
      // cout << "meet[" << day-1 << "] " << a << " " << b << endl;
      if(a == person) mkneg(day-1, b);
      if(b == person) mkneg(day-1, a);
    }
  }
  if(day < 101) {
    for(int other = 1; other <= n; other++) {
      caught[day][other].erase(person);
      if(caught[day][other].empty()) mkneg(day+1, other);
    }
  }
}

void setpos(int day, int person) {
        if(grid[day][person] < 0) {
          assert(0);
        }
        grid[day][person] = 1;
}

bool issubset(set<int> small, set<int> big) {
    for(auto it = small.begin(); it != small.end(); ++it) {
      if(!big.count(*it)) return false;
    }
    return true;
}

int main() {
  int j, i, day;
  cin >> n >> m >> t;
  cin.ignore();
  for(i = 0; i < m; i++) {
    int d, a, b;
    cin >> d >> a >> b;
    cin.ignore();
    meet[d].insert(pair<int,int>(a,b));
    caught[d][a].insert(b);
    caught[d][b].insert(a);
    assert(a > 0);
    assert(b > 0);
  }
  for(day = 0; day < 101; day++) {
    for(j = 1; j <= n; j++) {
      caught[day][j].insert(j);
      assert(j > 0);
    }
  }
  vector<int> posq;
  for(i = 0; i < t; i++) {
    int r;
    cin >> r;
    cin.ignore();
    if(r > 0) posq.push_back(r);
    else mkneg(101, -r);
  }
  // dumpgrid();

  set<int> base[105];

  for(auto person = 1; person <= n; person++) {
    base[person].insert(person);
  }

  for(day = 100; day >= 0; day--) {
    for(auto person = 1; person <= n; person++) {
      set<int> s;
      for(auto it = base[person].begin(); it != base[person].end(); ++it) {
        for(auto it2 = caught[day][*it].begin(); it2 != caught[day][*it].end(); ++it2) {
          s.insert(*it2);
        }
      }
      base[person] = s;
    }
  }
  for(auto person = 1; person <= n; person++) {
    // cout << "b" << person << ": "; printset(base[person]); cout << endl;
    if(grid[101][person] < 0) assert(base[person].empty());
  }
  for(auto it = posq.begin(); it != posq.end(); ++it) {
    setpos(101, *it);
    for(auto person = 1; person <= n; person++) {
      if(issubset(base[*it], base[person])) setpos(101, person);
    }
  }

  /*
  vector<set<int>> old;
  vector<set<int>> neww;
  for(auto it = posq.begin(); it != posq.end(); ++it) {
    set<int> s;
    s.insert(*it);
    neww.push_back(s);
  }
  for(day = 101; day >= 0; day--) {
    cout << neww.size() << endl;
    old = neww;
    neww.clear();
    cout << "d" << day << ": ";
    for(auto it = old.begin(); it != old.end(); ++it) {
      printset(*it); cout << "; ";
    }
    cout << endl;
    for(auto it = old.begin(); it != old.end(); ++it) {
      if(it->size() == 1) {
        int person = *(it->begin());
        setpos(day, person);
      }

      for(int other = 1; other <= n; other++) {
        auto ocot = caught[day][other];
        if(issubset(*it, ocot)) {
          setpos(day+1, other);
        }
      }

      if(day > 0) {
        set<int> s;
        for(auto it2 = it->begin(); it2 != it->end(); ++it2) {
          auto cot = caught[day-1][*it2];
          for(auto it3 = cot.begin(); it3 != cot.end(); ++it3) {
            s.insert(*it3);
          }
        }
        if(s.empty()) {
          assert(0);
        }
        neww.push_back(s);
      }
    }
  }
  for(day = 0; day < 102; day++) {
    for(auto it = meet[day].begin(); it != meet[day].end(); ++it) {
      int a = it->first, b = it->second;
      if(grid[day][a] > 0) setpos(day+1, b);
      if(grid[day][b] > 0) setpos(day+1, a);
    }
    for(int person = 1; person <= n; person++) {
      if(grid[day][person] > 0) setpos(day+1, person);
    }
  }
    dumpgrid();
    */


  for(i = 1; i <= n; i++) {
    if(grid[101][i] > 0) puts("+");
    else if(grid[101][i] < 0) puts("-");
    else puts("?");
  }
}
