#include<stdio.h>
#include<stdlib.h>
int cnt;
void solve(int x, int y, int n) {
	if (n) {
		solve(x, 6 - x - y, n - 1);
		cnt++;
		if (n > 1)	solve(6 - x - y, y, n - 1);
	}
}
void solveP(int x, int y, int n) {
	if (n) {
		solveP(x, 6 - x - y, n - 1);
		printf("%d %d\n", x, y);
		if (n > 1)	solveP(6 - x - y, y, n - 1);
	}
}

int main() 
{
	int n;

	scanf("%d", &n);
	solve(1, 3, n);
	printf("%d\n", cnt);
	solveP(1, 3, n);
	return 0;
}
