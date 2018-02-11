#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, Max;
	int* a;
	int* d;
	scanf("%d", &n);
	
	a = (int*)malloc(sizeof(int)*(n + 1));
	d = (int*)malloc(sizeof(int)*(n + 1));

	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	d[1] = a[1];

	for (i = 2; i <= n; i++) {
		if (d[i - 1] + a[i] > a[i]) d[i] = d[i - 1] + a[i];
		else d[i] = a[i];
	}
	Max = d[1];
	for (int i = 1; i <= n; i++) {
		if (d[i] > Max) Max = d[i];
	}
	printf("%d\n", Max);
	
	return 0;
}
