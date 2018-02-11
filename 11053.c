#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, j;
	int* d;
	int* a;

	scanf("%d", &n);

	d = (int*)malloc(sizeof(int)*(n + 1));
	a = (int*)malloc(sizeof(int)*(n + 1));
		
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);

	for (i = 1; i <= n; i++) {
		d[i] = 1;
		for (j = 1; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) d[i] = d[j] + 1;
		}
	}

	j = 0;
	for (i = 1; i <= n; i++) {
		if (d[i] > j) j = d[i];
	}
	printf("%d\n", j);
	return 0;
}
