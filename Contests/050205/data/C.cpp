/** Waterloo-2005-02-C: Up the Ante, Stefan Buettcher, 2005-01-31 **/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int n, k, l, m;


#define MAX_MONEY 20000

//#define SIMULATE

#ifdef SIMULATE

// I used this to verify my results experimentally...
void simulate() {
	const int gameCount = 300000;
	int positiveCnt = 0;
	for (int g = 0; g < gameCount; g++) {
		int gain = 0;
		int bet = 1;
		for (int i = 1; i <= m; i++) {
			int r = random() % 14;
			assert(r >= 0);
			switch (r) {
				case 0:
					gain += 3 * bet;
					bet = 1;
					break;
				case 1:
					gain += 2 * bet;
					bet = 1;
					break;
				case 2: case 3:
					gain += bet;
					bet = 1;
					break;
				default:
					gain -= bet;
					bet *= 2;
					if (bet > l)
						bet = 1;
			}
			if ((i >= k) && (gain > 0))
				break;
		}
		if (gain > 0)
			positiveCnt++;
	}
	printf("%.4lf\n", (positiveCnt * 1.0) / gameCount);
}

#else

double probability[MAX_MONEY][10];
double newProb[MAX_MONEY][10];
double probThatWin, probThatLose;
int min[10], max[10];

void play(int round) {
	for (int i = 0; i < MAX_MONEY; i++)
		for (int j = 0; j < 10; j++)
			newProb[i][j] = 0.0;

	int newMin[10], newMax[10];
	memcpy(newMin, min, sizeof(min));
	memcpy(newMax, max, sizeof(max));

	for (int bet = 0; (1 << bet) <= l; bet++) {
		int from = min[bet];
		int to = max[bet];
		int b = (1 << bet);

		// consider we win with three equal: 1/14
		for (int i = from; i < to; i++)
			newProb[i + 3 * b][0] += 1.0 / 14 * probability[i][bet];
		// consider we win with two equal: 1/14
		for (int i = from; i < to; i++)
			newProb[i + 2 * b][0] += 1.0 / 14 * probability[i][bet];
		// consider we win with one equal: 2/14
		for (int i = from; i < to; i++)
			newProb[i + 1 * b][0] += 2.0 / 14 * probability[i][bet];
		if (from + 3 * b < newMin[0])
			newMin[0] = from + 3 * b;
		if (to + 3 * b > newMax[0])
			newMax[0] = to + 3 * b;

		// consider we lose: 10/14
		if (2 * b > l) {
			// if house limit is reached, go back to 1 dollar
			for (int i = from; i < to; i++)
				newProb[i - b][0] += 10.0 / 14 * probability[i][bet];
			if (from - b < newMin[0])
				newMin[0] = from - b;
			if (to - b > newMax[0])
				newMax[0] = to - b;
		}
		else {
			// else: double!
			for (int i = from; i < to; i++)
				newProb[i - b][bet + 1] += 10.0 / 14 * probability[i][bet];
			if (from - b < newMin[bet + 1])
				newMin[bet + 1] = from - b;
			if (to - b > newMax[bet + 1])
				newMax[bet + 1] = to - b;
		}
	}

	memcpy(min, newMin, sizeof(min));
	memcpy(max, newMax, sizeof(max));
	memcpy(probability, newProb, sizeof(probability));

	if (round < k)
		probThatLose = 1.0;
	else {
		double thisProb = 0.0;
		for (int i = MAX_MONEY/2 + 1; i < MAX_MONEY; i++)
			for (int j = 0; (1 << j) <= l; j++) {
				thisProb += probability[i][j];
				probability[i][j] = 0.0;
			}
		probThatWin += thisProb;
	}
} // end of play(int)

#endif

int main() {
	scanf("%i", &n);
	while (--n >= 0) {
		scanf("%i%i%i", &k, &m, &l);
#ifdef SIMULATE
		simulate();
#else
		for (int i = 0; i < MAX_MONEY; i++)
			for (int j = 0; j < 12; j++) {
				probability[i][j] = 0.0;
				min[j] = MAX_MONEY/2;
				max[j] = MAX_MONEY/2;
			}
		probability[MAX_MONEY/2][0] = 1.0;
		min[0] = MAX_MONEY/2;
		max[0] = MAX_MONEY/2+1;
		probThatWin = 0.0;
		for (int i = 1; i <= m; i++)
			play(i);
		printf("%.4lf\n", probThatWin);
#endif
	}
	return 0;
}



