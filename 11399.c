#include<stdio.h>
#include<stdlib.h>
int check[1001];
int main() 
{
	int n, min, tmp, ans = 0;
	int p[1001];
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int j = 1; j <= n; j++) {
		min = 1001;
		for (int i = 1; i <= n; i++) {
			if (min > p[i]) {
				min = p[i];
				tmp = i;
			}
		}
	
		ans += p[tmp];
		check[j] = check[j-1] + ans;
		p[tmp] = 1001;
	}

	printf("%d\n", check[n]);
	return 0;
}
