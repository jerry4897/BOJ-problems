#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i;
	int* d;
	scanf("%d", &n);
	
	d = (int*)malloc(sizeof(int)*(n + 1));
	d[0] = 0;
	for (i = 1; i <= n; i++) {
		int min = 100000;
		for (int j = 1; j*j <= i; j++) {
			if (min > d[i - j*j]) min = d[i - j*j];
		}
		d[i] = min + 1;
	}
	printf("%d\n", d[n]);
	return 0;
}
