#include<stdio.h>

long long int memo[1001];
long long int D(int n);

int main()
{
	int n, i;

	scanf("%d", &n);
	i = D(n);
	printf("%d\n", i);
	return 0;
}

long long int D(int n)
{
	if (n <= 2) return n;
	if (memo[n] > 0) return memo[n];
	memo[n] = D(n - 1) + D(n - 2);
	memo[n] %= 10007;
	return memo[n];
}
