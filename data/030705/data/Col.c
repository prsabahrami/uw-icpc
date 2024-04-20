#include <stdio.h>

char* scale[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
int spaces[] = { 0, 2, 4, 5, 7, 9, 11, 12 };

main() {
    int pos[13];
    char line[2000];
    char* note;
    int j,k;
    int did_space;
    while(1) {
        memset(pos,0,sizeof(pos));
        gets(line);
        if( !strcmp(line,"END") ) break;
        char* ln = line;
        while( note = strtok(ln," ") ) {
            ln = 0;
            for( j = 0; j < 12; j++ ) {
                for( k = 0; k < 8; k++ ) {
                    if( !strcmp( scale[j+spaces[k]], note ) ) goto next;
                }
                pos[j] = 1;
next:
            }
        }
        did_space = 0;
        for( j = 0; j < 12; j++ )
            if( !pos[j] ) {
                printf( " %s", scale[j] );
            }
        puts("");
    }
}
