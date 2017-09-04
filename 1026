#include<stdio.h>

int main()
{
	int a[51], b[51];
	int n;
	int max, min, pos, sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)	scanf("%d", &b[i]);

	for (int i = 0; i < n; i++) {
		pos = i;
		min = 100;
		for (int j = i; j < n; j++) {
			if (a[j] < min) {
				min = a[j];
				pos = j;
			}
		}
		int tmp = a[pos];
		a[pos] = a[i];
		a[i] = tmp;
	}

	for (int i = 0; i < n; i++) {
		pos = i;
		max = -1;
		for (int j = i; j < n; j++) {
			if (b[j] > max) {
				max = b[j];
				pos = j;
			}
		}
		int tmp = b[pos];
		b[pos] = b[i];
		b[i] = tmp;
	}

	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	printf("%d\n", sum);
}
