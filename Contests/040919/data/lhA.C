#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double eps = 1e-12;

string dirs[8] = { "north", "northwest", "west", "southwest", "south", "southeast", "east", "northeast" };
double dx[8] = { +0, -1, -1, -1, +0, +1, +1, +1 };
double dy[8] = { +1, +1, +0, -1, -1, -1, +0, +1 };

double r, x, y, X, Y;
double td;
vector<double> paces;
vector<string> orientations;

void straight( double x1, double y1, double x2, double y2, int rev )
{
    if( fabs(hypot(x2-x1, y2-y1)) < eps ) return;
    paces.push_back(hypot(x2-x1, y2-y1));
    for( int i = 0; i < 8; i += 2 ) {
        double a = (x2-x1)*dx[i], b = (y2-y1)*dy[i];
        if( a>-eps && b>-eps && (a>eps || b>eps) ) {
            orientations.push_back(dirs[(i+rev)%8]);
            break;
        }
    }
}

void go( double x1, double y1, double x2, double y2, int rev )
{
    if( fabs(x1-x2) < eps || fabs(y1-y2) < eps ) {
        td = hypot(x1-x2, y1-y2);
        paces.clear();
        orientations.clear();
        straight(x1, y1, x2, y2, rev);
        return;
    }
    for( int i = 1; i < 8; i += 2 ) {
        double d, t, nx, ny;
        t = (x2-x1) / dx[i], nx = x1+t*dx[i], ny = y1+t*dy[i];
        if( hypot(nx,ny) > r || t < 0 ) goto next;
        d = hypot(nx-x1, ny-y1) + hypot(nx-x2, ny-y2);
        if( d < td ) {
            td = d;
            paces.clear();
            orientations.clear();
            if( !rev ) {
                paces.push_back(hypot(nx-x1, ny-y1));
                orientations.push_back(dirs[(i+rev)%8]);
            }
            straight(nx, ny, x2, y2, rev);
            if( rev ) {
                paces.push_back(hypot(nx-x1, ny-y1));
                orientations.push_back(dirs[(i+rev)%8]);
            }
        }
next:;
        t = (y2-y1) / dy[i], nx = x1+t*dx[i], ny = y1+t*dy[i];
        if( hypot(nx,ny) > r || t < 0 ) continue;
        d = hypot(nx-x1, ny-y1) + hypot(nx-x2, ny-y2);
        if( d < td ) {
            td = d;
            paces.clear();
            orientations.clear();
            if( !rev ) {
                paces.push_back(hypot(nx-x1, ny-y1));
                orientations.push_back(dirs[(i+rev)%8]);
            }
            straight(nx, ny, x2, y2, rev);
            if( rev ) {
                paces.push_back(hypot(nx-x1, ny-y1));
                orientations.push_back(dirs[(i+rev)%8]);
            }
        }
    }
}

int main()
{
    int tn = 0;
    while( cin >> r >> x >> y >> X >> Y ) {
        if( tn++ ) printf("\n");
        td = 1e100;
        go(x, y, X, Y, 0);
        go(X, Y, x, y, 4);
        for( int i = 0; i < paces.size(); i++ ) {
            printf("%s %.10lf\n", orientations[i].c_str(), paces[i]);
        }
    }
}

