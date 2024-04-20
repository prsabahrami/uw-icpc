#include <iostream>
#include <math.h>
using namespace std;

double EPS = 1e-4;
double pi = acos(0.0)*2;

double slice(double h, double r) {
  if( h <= -r ) return 0.0;
  if( h >= r ) return pi*r*r;
  h <?= r;
  double th = acos(-h/r);
  return (th - sin(2*th)/2)*r*r;
}

main() {
  double K, Hb, Db, Hn, Dn, H;

  while( cin >> K >> Hb >> Db >> Hn >> Dn >> H && K+Hb+Db+Hn+Dn+H > 0 ) {
    double V = 0.0, Hc = H-Hb-Hn;
    V += (K <? Hb) * slice(Db/2, Db/2);
    for( double h = 0; h < K-Hb && h < Hc; h += EPS )
      V += EPS * slice(Db/2, ((Hc-h)*Db + h*Dn)/Hc/2);
    if( K > Hb+Hc ) V += (K-Hb-Hc) * slice(Db/2, Dn/2);
    double Alo = -Db/2, Ahi = Db/2, A;
    for(;;) {
      A = (Ahi+Alo)/2;
      if( Ahi-Alo < EPS ) break;
      double V2 = 0.0;
      V2 += Hb * slice(A, Db/2);
      for( double h = 0; h < Hc; h += EPS )
        V2 += EPS * slice(A, ((Hc-h)*Db + h*Dn)/Hc/2);
      V2 += Hn * slice(A, Dn/2);
      if( V2 < V ) Alo = A; else Ahi = A;
    }
    printf( "%.2lf\n", A+Db/2 );
  }
}
