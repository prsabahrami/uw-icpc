#include <stdio.h>
#include <string.h>

using namespace std;

#include <queue>
#include <set>

typedef pair<int,int> stump;
set<stump> stumps;

struct log{
    int a1;
    int a2;
    int b;
    char orient;
    bool touches(stump s) const {
        if(orient=='-') {
            if(a1==s.first && b==s.second) return true;
            if(a2==s.first && b==s.second) return true;
        } else {
            if(a1==s.second && b==s.first) return true;
            if(a2==s.second && b==s.first) return true;
        }
        return false;
    }
    stump other(stump s) const {
        if(orient=='-') {
            if(a1==s.first && b==s.second) return stump(a2,b);
            if(a2==s.first && b==s.second) return stump(a1,b);
        } else {
            if(a1==s.second && b==s.first) return stump(b,a2);
            if(a2==s.second && b==s.first) return stump(b,a1);
        }
        return stump(-1,-1);
    }
    int len() const {
        if(a1<a2) return a2-a1; else return a1-a2;
    }
    stump endp1() {
        if(orient == '-') return stump(a1,b);
        return stump(b,a1);
    }
    stump endp2() {
        if(orient == '-') return stump(a2,b);
        return stump(b,a2);
    }
    bool hits(stump s) {
        if(orient == '-') {
            return(s.second == b && a1 < s.first && s.first < a2);
        } else {
            return(s.first == b && a1 < s.second && s.second < a2);
        }
    }
    bool valid() {
        if(!stumps.count(endp1())) return false;
        if(!stumps.count(endp2())) return false;
        for(set<stump>::iterator it = stumps.begin(); it != stumps.end(); it++) {
            if(hits(*it)) return false;
        }
        return true;
    }
    bool crosses(const log l) {
        if(orient == l.orient) return false;
        return(l.a1 < b && b < l.a2 && a1 < l.b && l.b < a2);
    }
};


bool operator<(const log l1, const log l2) {
    if(l1.a1<l2.a1) return true;
    if(l1.a1>l2.a1) return false;
    if(l1.a2<l2.a2) return true;
    if(l1.a2>l2.a2) return false;
    if(l1.b<l2.b) return true;
    if(l1.b>l2.b) return false;
    if(l1.orient<l2.orient) return true;
    if(l1.orient>l2.orient) return false;
    return false;
}

struct board {
    stump guy;
    int len;
    set<log> logs;
    bool canadd(log l) {
        if(logs.count(l)) return false;
        if(!l.valid()) return false;
        for(set<log>::iterator it = logs.begin(); it != logs.end(); it++) {
            if(l.crosses(*it)) return false;
        }
        return true;
    }
};

struct mboard {
    board bd;
    int moves;
};

bool operator<(const board& b1, const board& b2) {
    if(b1.guy<b2.guy) return true;
    if(b1.guy>b2.guy) return false;
    if(b1.len<b2.len) return true;
    if(b1.len>b2.len) return false;
    if(b1.logs<b2.logs) return true;
    if(b1.logs>b2.logs) return false;
    return false;
}

void printboard(board bd) {
    printf("%d %d %d\n", bd.guy.first, bd.guy.second, bd.len);
    for(set<log>::iterator it = bd.logs.begin(); it != bd.logs.end(); it++) {
        printf("%d %d %d %c\n", it->a1, it->a2, it->b, it->orient);
    }
}

int rows;
int cols;
int cnts[1000];
char buf[1000];
stump goal;

set<board> seen;
queue<mboard> q;

void move(board bd, int moves) {
    if(seen.count(bd) == 0) {
        seen.insert(bd);
        mboard mbd;
        mbd.bd = bd;
        mbd.moves = moves;
        q.push(mbd);
    }
}

main() {
    int CASES;
    scanf("%d", &CASES);
    while(CASES--) {
        int i,j,k;
        scanf("%d %d ", &rows, &cols);
        stumps = set<stump>();
        board bd;
        bd.len = 0;
        memset(cnts,0,sizeof(cnts));
        for(i=0; i<rows; i++) {
            gets(buf);
            for(j=0; j<cols; j++) {
                if(cnts[j]) {
                    if(buf[j] != '|') {
                        log l;
                        l.a1 = i-cnts[j]-1;
                        l.a2 = i;
                        l.b = j;
                        l.orient = '|';
                        bd.logs.insert(l);
                    }
                }
                stump s(j,i);
                switch(buf[j]) {
                    case 'S':
                        stumps.insert(s);
                        break;
                    case 'B':
                        bd.guy = stump(j,i);
                        stumps.insert(s);
                        break;
                    case 'E':
                        goal = s;
                        stumps.insert(s);
                        break;
                    case '-':
                        if(buf[j-1] != '-') {
                            log l;
                            l.a1 = j-1;
                            for(k=j; buf[k] == '-'; k++);
                            l.a2 = k;
                            l.b = i;
                            l.orient = '-';
                            bd.logs.insert(l);
                        }
                    case '|':
                        cnts[j]++;
                }
                if(buf[j] != '|') cnts[j] = 0;
            }
        }
        //printboard(bd);
        seen = set<board>();
        q = queue<mboard>();
        mboard mbd;
        mbd.bd = bd;
        mbd.moves = 0;
        q.push(mbd);
        while(q.size() > 0) {
            mboard mbd = q.front();
            q.pop();
            board bd = mbd.bd;
            int moves = mbd.moves;
            if(bd.guy == goal) {
                printf("%d\n", moves);
                goto next;
            }
            for(set<log>::iterator it = bd.logs.begin(); it != bd.logs.end(); it++) {
                if(it->touches(bd.guy)) {
                    board bd2 = bd;
                    bd2.guy = it->other(bd.guy);
                    move(bd2, moves+1);
                }
            }
            if(!bd.len) {
                for(set<log>::iterator it = bd.logs.begin(); it != bd.logs.end(); it++) {
                    if(it->touches(bd.guy)) {
                        board bd2 = bd;
                        /*
                        bd2.logs = set<log>();
                        log badl = *it;
                        for(set<log>::iterator it2 = bd.logs.begin(); it2 != bd.logs.end(); it2++) {
                            log newl = *it2;
                            if(badl < newl || newl < badl) bd2.logs.insert(newl);
                        }
                        */
                        bd2.logs.erase(*it);
                        bd2.len = it->len();
                        move(bd2, moves+1);
                    }
                }
            }
#define trylog(bd,log) \
            do { \
                if(bd.canadd(log)) { \
                    board bd2 = bd; \
                    bd2.len = 0; \
                    bd2.logs.insert(log); \
                    move(bd2, moves+1); \
                } \
            } while(0)
            if(bd.len) {
                log l;
                l.a1 = bd.guy.first;
                l.a2 = bd.guy.first + bd.len;
                l.b = bd.guy.second;
                l.orient = '-';
                trylog(bd, l);
                l.a1 = bd.guy.first - bd.len;
                l.a2 = bd.guy.first;
                trylog(bd, l);
                l.a1 = bd.guy.second;
                l.a2 = bd.guy.second + bd.len;
                l.b = bd.guy.first;
                l.orient = '|';
                trylog(bd, l);
                l.a1 = bd.guy.second - bd.len;
                l.a2 = bd.guy.second;
                trylog(bd, l);
            }
        }
        puts("0");
next:;
    }
}

