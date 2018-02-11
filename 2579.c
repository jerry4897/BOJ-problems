#include<stdio.h>
#include<stdlib.h>
int Max(int a, int b);

int main()
{
	int n, i;
	int* a;
	int* d;
	scanf("%d", &n);

	d = (int*)malloc(sizeof(int*)*(n + 1));
	a = (int*)malloc(sizeof(int)*(n + 1));
		
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	d[0] = 0;
	d[1] = a[1];
	if(n>=2) d[2] = a[1] + a[2];

	for (i = 3; i <= n; i++) {
		d[i] = Max(d[i - 3] + a[i] + a[i - 1], d[i - 2] + a[i]);
	}
	printf("%d\n", d[n]);
	return 0;
}

int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
