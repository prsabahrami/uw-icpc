#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
  ifstream output(argv[2]), key(argv[3]);
  
  long double a1, a2;
  assert(key >> a1);
  if (!(output >> a2)) {
    cout << "Could not parse output" << endl;
    return 2;
  } else if (a1 == 0) {
    if (a2 != 0) {
      return 2;
    }
  } else if (fabs(a2 - a1) / a1 > 1e-9) {
    return 2;
  }
  
  string crap;
  if (output >> crap) {
    cout << "Trailing output" << endl;
    return 1;
  }
  
  return 0;
}