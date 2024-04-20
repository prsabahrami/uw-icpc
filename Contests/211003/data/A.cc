#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
  typedef Point P;
  T x, y;
  explicit Point(T x=0, T y=0) : x(x), y(y) {}
  bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
  bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
  P operator+(P p) const { return P(x+p.x, y+p.y); }
  P operator-(P p) const { return P(x-p.x, y-p.y); }
  P operator*(T d) const { return P(x*d, y*d); }
  P operator/(T d) const { return P(x/d, y/d); }
  T dot(P p) const { return x*p.x + y*p.y; }
  T cross(P p) const { return x*p.y - y*p.x; }
  T cross(P a, P b) const { return (a-*this).cross(b-*this); }
  T dist2() const { return x*x + y*y; }
  P perp() const { return P(-y, x); } // rotates +90 degrees
};


template<class T> struct Point3D {
  typedef Point3D P;
  typedef const P& R;
  T x, y, z;
  explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
  explicit Point3D(Point<T> p) : x(p.x), y(p.y), z(0) {}
  bool operator<(R p) const {
    return tie(x, y, z) < tie(p.x, p.y, p.z); }
  bool operator==(R p) const {
    return tie(x, y, z) == tie(p.x, p.y, p.z); }
  P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
  P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
  P operator*(T d) const { return P(x*d, y*d, z*d); }
  P operator/(T d) const { return P(x/d, y/d, z/d); }
  T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
  P cross(R p) const {
    return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
  }
  T dist2() const { return x*x + y*y + z*z; }
  friend ostream& operator<<(ostream& os, R p) {
    return os << "(" << p.x << "," << p.y << "," << p.z << ")"; }
};

using P = Point<ll>;
using Pf = Point<ld>;
using P3 = Point3D<ld>;

ld volume(P3 a, P3 b, P3 c, P3 d) { // signed volume tetrahedron
  b = b - a;
  c = c - a;
  d = d - a;
  return b.cross(c).dot(d);
}

template<class P>
vector<pair<P, P>> tangents(P c1, ld r1, P c2, ld r2) {
  P d = c2 - c1;
  ld dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
  if (d2 == 0 || h2 < 0)  return {};
  vector<pair<P, P>> out;
  for (double sign : {-1, 1}) {
    P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
    out.push_back({c1 + v * r1, c2 + v * r2});
  }
  if (h2 == 0) out.pop_back();
  return out;
}

bool is_reflex(const P& a, const P& b) { auto c = a.cross(b); return c ? (c < 0) : (a.dot(b) < 0); }
bool angle_less(const P& base, const P& s, const P& t) {
  int r = is_reflex(base, s) - is_reflex(base, t);
  if(r) return r < 0;
  if(s.cross(t)) return 0 < s.cross(t);
  return s.dist2() > t.dist2(); // further away = higher first
}


struct M {
  ll x, y, z;
  string name;
  bool operator<(const M& o) const {
    return angle_less(P(0,1), p2(), o.p2());
  }
  P p2() const { return P(-x,y); }
  Pf p2f() const { return Pf(-x,y); }
  P3 p3() const { return P3(-x,y,z); }
};

bool blocks(const M& a, const M& b) { // a blocks b?
  {
      ll dx = a.x-b.x;
      ll dy = a.y-b.y;
      ll d2 = dx*dx+dy*dy;
      ll dh = a.z-b.z;
      assert(dh*dh < d2);
  }

  auto t = tangents(Pf(0,0),0,a.p2f(),a.z);
  assert(sz(t) == 2);
  // mountain "a" covers exactly triangle p0,p1,p2
  P3 p0 = a.p3();
  P3 p1 = P3(t[0].second);
  P3 p2 = P3(t[1].second);

  P3 q0 = P3(0,0,0);
  P3 q1 = b.p3();

  // does segment q0,q1 pass through triangle p0,p1,p2?
  if(sgn(volume(q0, p0,p1,p2)) * sgn(volume(q1, p0,p1,p2)) <= 0) {
    // different sides of triangle
    int s0 = sgn(volume(q0,q1, p0,p1));
    int s1 = sgn(volume(q0,q1, p1,p2));
    int s2 = sgn(volume(q0,q1, p2,p0));

    if(s0*s1*s2 == 0) return true; // touching
    if(s0 == s1 && s0 == s2) return true;
  }

  return false;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  vector<M> mountain(n);
  rep(i,0,n) cin >> mountain[i].x >> mountain[i].y >> mountain[i].z >> mountain[i].name;
  sort(all(mountain));

  rep(i,0,n) {
    bool ok = true;
    rep(j,0,n) if(j != i && blocks(mountain[j], mountain[i])) {
      ok = false;
      break;
    }
    if(ok) cout << mountain[i].name << "\n";
  }
}
