/** Waterloo-2005-02-E: Traditional Bingo, Stefan Buettcher, 2005-01-30 **/

#include <stdio.h>
#include <string.h>

int n, number;
int card[5][5];

bool processNumber(int number) {
	for (int j = 0; j < 5; j++)
		for (int k = 0; k < 5; k++)
			if (card[j][k] == number) {
				card[j][k] = -1;
				return true;
			}
	return false;
}

void checkVictory(int no) {
	for (int col = 0; col < 5; col++) {
		bool vic = true;
		for (int row = 0; row < 5; row++)
			if (card[col][row] >= 0)
				vic = false;
		if (vic) {
			printf("BINGO after %i numbers announced\n", no);
			memset(card, 0, sizeof(card));
			return;
		}
	}
	for (int row = 0; row < 5; row++) {
		bool vic = true;
		for (int col = 0; col < 5; col++)
			if (card[col][row] >= 0)
				vic = false;
		if (vic) {
			printf("BINGO after %i numbers announced\n", no);
			memset(card, 0, sizeof(card));
			return;
		}
	}
	bool vic = true;
	for (int col = 0; col < 5; col++)
		if (card[col][col] >= 0)
			vic = false;
	if (vic) {
		printf("BINGO after %i numbers announced\n", no);
		memset(card, 0, sizeof(card));
		return;
	}
	vic = true;
	for (int col = 0; col < 5; col++)
		if (card[col][4 - col] >= 0)
			vic = false;
	if (vic) {
		printf("BINGO after %i numbers announced\n", no);
		memset(card, 0, sizeof(card));
		return;
	}
}

int main() {
	scanf("%i", &n);
	while (--n >= 0) {
		for (int i = 0; i <= 1; i++)
			scanf("%i%i%i%i%i", &card[0][i], &card[1][i], &card[2][i], &card[3][i], &card[4][i]);
		scanf("%i%i%i%i", &card[0][2], &card[1][2], &card[3][2], &card[4][2]);
		for (int i = 3; i <= 4; i++)
			scanf("%i%i%i%i%i", &card[0][i], &card[1][i], &card[2][i], &card[3][i], &card[4][i]);
		card[2][2] = -1;

		for (int i = 0; i < 75; i++) {
			scanf("%i", &number);
			if (processNumber(number))
				checkVictory(i + 1);
		}
	}
	return 0;
}


