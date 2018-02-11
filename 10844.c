#include<stdio.h>

int main()
{
	int n, i, j;
	long long int sum = 0;
	long long int d[101][10];

	scanf("%d", &n);
	d[1][0] = 0;
	for (i = 1; i <= 9; i++) d[1][i] = 1;            

	for (i = 2; i <= n; i++) {
		for (j = 0; j <= 9; j++) {
			if (j == 0) d[i][j] = d[i - 1][j + 1];
			else if (j == 9) d[i][j] = d[i - 1][j - 1];
			else d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
			d[i][j] %= 1000000000;
		}
	}
	for (i = 0; i <= 9; i++) sum += d[n][i];
	printf("%lld\n", sum % 1000000000);
	return 0;
}
