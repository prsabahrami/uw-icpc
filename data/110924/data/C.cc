#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;
ld a[100111];
bool equ(const ld& a, const ld& b) { return fabs(a-b) < 1e-18; }
bool cmp(const ld& a, const ld& b) { return fabs(a) < fabs(b) || (equ(fabs(a), fabs(b)) && a < b); }
	
int main()
{
	int N; scanf("%d", &N);
	
	int neg = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		scanf("%llf", &a[i]);
		if (a[i] < 0) neg++;
	}
	
	sort(a, a+N, cmp);
	for (int i = 1; i < N; i++)
		if (fabs(a[i]) != fabs(a[i-1]))
			cnt++;
	
	if (cnt == 0) 
		printf("%d\n", (neg && neg != N ? -1 : 1));
	else if (N >= 65 || cnt != N-1) 
		puts("0");
	else 
	{
		for (int iter = 0; iter < 65; iter++)
		{
			for (int i = 0; i < N-1; i++)
				a[i] = a[i+1] / a[i];
			a[N-1] = 1;
			sort(a, a+N, cmp);
			N = unique(a, a+N, equ) - a;
			if (N <= 2) break;
		}
		
		if (N > 2) puts("0");
		else {
			cout.precision(20);
			cout << (a[0] == 1 ? a[1] : a[0]) << endl;
		}
	}
	
	return 0;
}
