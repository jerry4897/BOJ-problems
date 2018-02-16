#include<stdio.h>
#include<stdlib.h>
int** a;
int cnt[3];

int same(int x, int y, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[x][y] != a[x + i][y + j])return 0;
		}
	}
	return 1;
}

void solve(int x, int y, int n) {
	int m = n / 3;
	if (same(x, y, n)) {
		cnt[a[x][y] + 1]++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i*m, y + j*m, m);
		}
	}
}

int main() 
{
	int n;

	scanf("%d", &n);
	a = (int**)malloc(sizeof(int*)*(n + 1));
	for (int i = 1; i <= n; i++) a[i] = (int*)malloc(sizeof(int)*(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
  
	solve(1, 1, n);
	printf("%d\n%d\n%d\n", cnt[0], cnt[1], cnt[2]);
	return 0;
}
