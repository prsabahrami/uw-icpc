#include <stdio.h>
#include <string.h>

int black;
int white;

enum {
    EMPTY=0,
    BLACK=1,
    WHITE=2,
    BORDER=-1,
    TOP=4
};

int board[30][30];
int mark[30][30];

int check_capture(int x, int y, int around_colour) {
    if(mark[x][y]) return 1;
    mark[x][y] = 1;
    if(board[x][y] == BORDER) return 1;
    if(board[x][y] == around_colour ) return 1;
    if(board[x][y] == EMPTY ) return 0;
    if(!check_capture(x+1,y,around_colour)) return 0;
    if(!check_capture(x-1,y,around_colour)) return 0;
    if(!check_capture(x,y+1,around_colour)) return 0;
    if(!check_capture(x,y-1,around_colour)) return 0;
    return 1;
}

void do_capture(int x, int y, int around_colour) {
    int capture_colour = 3^around_colour;
    if(board[x][y] != capture_colour) return;
    if(capture_colour == BLACK) white++;
    if(capture_colour == WHITE) black++;
    board[x][y] = 0;
    do_capture(x+1,y,around_colour);
    do_capture(x-1,y,around_colour);
    do_capture(x,y+1,around_colour);
    do_capture(x,y-1,around_colour);
}

int check_own(int x, int y, int around_colour) {
    if(board[x][y] == around_colour) return 1;
    if(board[x][y] == BORDER) return 1;
    if(mark[x][y]) return 1;
    mark[x][y] = 1;
    if(board[x][y] != EMPTY) return 0;
    if(!check_own(x+1,y,around_colour)) return 0;
    if(!check_own(x-1,y,around_colour)) return 0;
    if(!check_own(x,y+1,around_colour)) return 0;
    if(!check_own(x,y-1,around_colour)) return 0;
    return 1;
}

void clear_mark() {
    memset(mark,0,sizeof(mark));
}

int N, M;

int scale(int x) {
    return x+(N/2)+2;
}
int x,y;
char colour;
main() {
    int i,j;
    while(1) {
        black = 0;
        white = 0;
        scanf("%i %i ", &N, &M);
        if(!N) break;
        memset(board,-1,sizeof(board));
        for(i = scale((1-N)/2); i <= scale((N-1)/2); i++) {
            for(j = scale((1-N)/2); j <= scale((N-1)/2); j++) {
                board[i][j] = EMPTY;
            }
        }
        for(i = 0; i < M; i++) {
            scanf("%c(%i,%i) ",&colour,&x,&y);
            x = scale(x);
            y = scale(y);
            if(colour == 'B') colour = BLACK; else colour = WHITE;
            clear_mark();
            board[x][y] = colour;
            clear_mark();
            if(check_capture(x+1,y,colour)) { clear_mark(); do_capture(x+1,y,colour); }
            clear_mark();
            if(check_capture(x-1,y,colour)) { clear_mark(); do_capture(x-1,y,colour); }
            clear_mark();
            if(check_capture(x,y+1,colour)) { clear_mark(); do_capture(x,y+1,colour); }
            clear_mark();
            if(check_capture(x,y-1,colour)) { clear_mark(); do_capture(x,y-1,colour); }
        }
        for(i = scale((1-N)/2); i <= scale((N-1)/2); i++) {
            for(j = scale((1-N)/2); j <= scale((N-1)/2); j++) {
                if(board[i][j] != EMPTY) continue;
                clear_mark();
                if(check_own(i,j,BLACK)) black++;
                clear_mark();
                if(check_own(i,j,WHITE)) white++;
            }
        }
        printf("%u %u\n", black, white);
    }
}

