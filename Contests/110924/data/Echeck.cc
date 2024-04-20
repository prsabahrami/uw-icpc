#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int matrix[50][50];
int dr[5] = {-1, 0, 1, 0, 0};
int dc[5] = {0, -1, 0, 1, 0};

int main(int argc, char** argv) {
	ifstream input(argv[1]), output(argv[2]), key(argv[3]);
	int T; assert(input >> T);
	
	for (int test = 0; test < T; test++) {
    int N, M; assert(input >> N >> M);
		bool allzero = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				int elem; assert(key >> elem);
				if (elem) allzero = false;
			}
		
		bool allzero2 = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (!(output >> matrix[i][j]) || (matrix[i][j] & ~1)) {
					cout << "Invalid output for case " << test+1 << endl;
					return 2;
				} else if (matrix[i][j]) {
					allzero2 = false;
				}
				
		if (allzero2 && !allzero) {
			cout << "Output was the zero matrix for case " << test+1 << endl;
			return 2;
		}
				
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				int sum = 0;
				for (int k = 0; k < 5; k++) {
					unsigned ni = i + dr[k], nj = j + dc[k];
					if (ni < N && nj < M)
						sum += matrix[ni][nj];
				}
				if (sum % 2) {
					cout << "Parity was bad in case " << test+1 << endl;
					return 2;
				}
			}
	}
	
	string crap;
	if (output >> crap) {
		cout << "Trailing output" << endl;
		return 1;	// trailing stuff
	}
	
	return 0;
}