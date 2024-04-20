#include <string.h>

char buf[10*1024*1024];

char C[255];

#define F(x) for(C[x]=0; C[x]<2; C[x]++)

int eval(int i) {
    if(buf[i] == 'N') return -eval(i+1);
    if(buf[i] == 'K') {
        int x = eval(i+1);
        int y = eval(abs(x));
        if(x > 0) return y; else return -abs(y);
    }
    if(buf[i] == 'A') {
        int x = eval(i+1);
        int y = eval(abs(x));
        if(x < 0) return y; else return abs(y);
    }
    if(buf[i] == 'C') {
        int x = eval(i+1);
        int y = eval(abs(x));
        if(x<0 && y>0) return -abs(y); else return abs(y);
    }
    if(buf[i] == 'E') {
        int x = eval(i+1);
        int y = eval(abs(x));
        if(x<0 && y<0) return abs(y);
        if(x>0 && y>0) return abs(y);
        return -abs(y);
    }
    if(C[buf[i]]) return i+1; else return -(i+1);
}
main() {
    while(1) {
        gets(buf);
        if(buf[0] == '0') break;
        F('p') F('q') F('r') F('s') F('t')
        {
            if(eval(0) <0) goto not;
        }
        puts("tautology");
        continue;
not:
        puts("not");
    }
}
