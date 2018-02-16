#include<stdio.h>
#include<stdlib.h>

int main() 
{
	int n, k, ans = 0;
	int coin[11];
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++) scanf("%d", &coin[i]);

	for (int i = n; i >= 1; i--) {
		int tmp = k / coin[i];
		ans += tmp;
		k = k - tmp*coin[i];
	}

	printf("%d\n", ans);
	return 0;
}
