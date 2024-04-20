#include "testlib.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];
typedef pair<int, int> PII;

bool adjacent(const PII &a, const PII &b) {
    return (a.first == b.first && abs(a.second - b.second) == 1) || (a.second == b.second && abs(a.first - b.first) == 1);
}

int main(int argc, char * argv[]) {
    setName("compare files as sequence of lines");
    registerTestlibCmd(argc, argv);

    int T = inf.readInt(1, 100);
    for (int _ = 1; _ <= T; _++) {
        int n = inf.readInt(2, 64);
        map<int, PII> mp;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = inf.readInt(1, n * n);
                mp[a[i][j]] = PII(i, j);
            }
        }
        if (mp.size() != n * n) {
            quitf(_fail, "[case %d] Invalid input", _);
        }
        set<int> st;
        vector<int> res;
        for (int i = 1; i <= n * n; i++) {
            if (!ouf.eof()) {
                int x = ouf.readInt(1, n * n);
                res.push_back(x);
            }
            else {
                quitf(_wa, "[case %d] Need more output", _);
            }
        }
        for (auto &x : res) st.insert(x);
        if (st.size() != res.size()) {
            quitf(_wa, "[case %d] Duplicate number exists", _);
        }
        int pos = 0, neg = 0;
        for (int i = 1; i < res.size(); i++) {
            if (!adjacent(mp[res[i]], mp[res[i - 1]])) {
                quitf(_wa, "[case %d] Not adjacent", _);
            }
            if (res[i] < res[i - 1]) 
                pos++;
            else
                neg++;
        }
        if (pos < neg) {
            quitf(_wa, "[case %d] Not lazy, up = %d, down = %d", _, neg, pos);
        }
    }

    // while (!ouf.eof()) {
    //     std::string rm = ouf.readString();
    //     if (rm != "")
    //         quitf(_wa, "Too many output");
    // }
    
    quitf(_ok, "correct");
}
