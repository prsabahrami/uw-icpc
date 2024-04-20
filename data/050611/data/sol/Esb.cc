#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int x, y;
	int tl, bl, tr, br;
	int row, metaRow;
} Point;


int n;
Point p[200004];
int inRowLeft[202000], inRowRight[202000];
int inMetaRowLeft[1024], inMetaRowRight[1024];


int compareX(const void *a, const void *b) {
	Point *x = (Point*)a;
	Point *y = (Point*)b;
	if (x->x == y->x)
		return x->y - y->y;
	else
		return x->x - y->x;
}


int compareY(const void *a, const void *b) {
	Point *x = (Point*)a;
	Point *y = (Point*)b;
	if (x->y == y->y)
		return x->x - y->x;
	else
		return x->y - y->y;
}


int intAsc(const void *a, const void *b) {
	return *((int*)a) - *((int*)b);
}


void precompute() {
	int curX, curY, seenSoFar, seenInCur;
	qsort(p, n, sizeof(Point), compareY);
	int rowCnt = 0;
	curY = -999999999; seenSoFar = 0; seenInCur = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].y != curY) {
			seenSoFar += seenInCur;
			seenInCur = 0;
			curY = p[i].y;
			rowCnt++;
		}
		p[i].row = rowCnt - 1;
		seenInCur++;
	}

	if (rowCnt == 0) {
		for (int i = 0; i < n; i++) {
			p[i].tl = 0;
			p[i].tr = 0;
			p[i].bl = 0;
			p[i].br = 0;
		}
		return;
	}
	int metaRowSize = (int)(sqrt(rowCnt) + 0.1);
	int metaRowCnt = rowCnt / metaRowSize + 1;
	for (int i = 0; i < rowCnt + 2000; i++)
		inRowRight[i] = inRowLeft[i] = 0;
	for (int i = 0; i < metaRowCnt + 20; i++)
		inMetaRowLeft[i] = inMetaRowRight[i] = 0;

	for (int i = 0; i < n; i++) {
		p[i].metaRow = p[i].row / metaRowSize;
		inRowRight[p[i].row]++;
		inMetaRowRight[p[i].metaRow]++;
	}

	qsort(p, n, sizeof(Point), compareX);
	curX = -999999999;
	int lastChange = -1;
	int pos = 0;
	while (pos < n) {
		curX = p[pos].x;
		int start = pos;
		int end = start;
		while ((end < n) && (p[end].x == curX))
			end++;
		// remove all from right side
		for (int i = start; i < end; i++) {
			inRowRight[p[i].row]--;
			inMetaRowRight[p[i].metaRow]--;
		}
		// count what we have TL, TR, BL, BR
		for (int i = start; i < end; i++) {
			p[i].tl = p[i].tr = p[i].bl = p[i].br = 0;
			int row = p[i].row;
			int metaRow = p[i].metaRow;
			for (int k = 0; k < metaRow; k++) {
				p[i].bl += inMetaRowLeft[k];
				p[i].br += inMetaRowRight[k];
			}
			for (int k = metaRow * metaRowSize; k < row; k++) {
				p[i].bl += inRowLeft[k];
				p[i].br += inRowRight[k];
			}
			for (int k = row + 1; k < (metaRow + 1) * metaRowSize; k++) {
				p[i].tl += inRowLeft[k];
				p[i].tr += inRowRight[k];
			}
			for (int k = metaRow + 1; k < metaRowCnt; k++) {
				p[i].tl += inMetaRowLeft[k];
				p[i].tr += inMetaRowRight[k];
			}
		}
		// put all to left side
		for (int i = start; i < end; i++) {
			inRowLeft[p[i].row]++;
			inMetaRowLeft[p[i].metaRow]++;
		}
		pos = end;
	}

} // end of precompute()


void getStanAndOllie(int i, int *s, int *o) {
	*s = p[i].bl + p[i].tr;
	*o = p[i].tl + p[i].br;
}



void play() {
	int s, o;
	int bestStan = 0;
	int bestOllie[200000];
	int bestOllieCount = 0;
	qsort(p, n, sizeof(Point), compareX);
	int stan = 0;
	while (stan < n) {
		int ollie = stan;
		int bestStanHere = 500000;
		int bestOllieHere = 0;
		do {
			if (n - bestOllieHere >= bestStan) {
				getStanAndOllie(ollie, &s, &o);
				if (o > bestOllieHere) {
					bestOllieHere = o;
					bestStanHere = s;
				}
				else if (o == bestOllieHere) if (s < bestStanHere) {
					bestOllieHere = o;
					bestStanHere = s;
				}
			}
			ollie++;
			if (ollie >= n)
				break;
		} while (p[ollie].x == p[stan].x);
		if (bestStanHere > bestStan) {
			bestStan = bestStanHere;
			bestOllie[0] = bestOllieHere;
			bestOllieCount = 1;
		}
		else if (bestStanHere == bestStan)
			bestOllie[bestOllieCount++] = bestOllieHere;
		stan = ollie;
	}
	qsort(bestOllie, bestOllieCount, sizeof(int), intAsc);
	printf("Stan: %d; Ollie:", bestStan);
	printf(" %d", bestOllie[0]);
	for (int i = 1; i < bestOllieCount; i++)
		if (bestOllie[i] > bestOllie[i - 1])
			printf(" %d", bestOllie[i]);
	printf(";\n");
}


int main() {
	while (scanf("%d", &n) == 1) {
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		precompute();
		play();
	}
	return 0;
}



