#include<stdio.h>
#include<stdlib.h>
int* num;
int* b;

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid&&j <= end) {
		if (num[i] <= num[j]) b[k++] = num[i++];
		else b[k++] = num[j++];
	}
	while (i <= mid) b[k++] = num[i++];
	while (j <= end)b[k++] = num[j++];
	for (int i = start; i <= end; i++) num[i] = b[i - start];
}

void sort(int start, int end) {
	int mid = (start + end) / 2;
	if (start == end) return;
	
	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}
int binary(int x, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (num[mid] == x) return 1;
		else if (num[mid] < x) start = mid + 1;
		else end = mid - 1;
	}
	return 0;
}
int main()
{
	int n, m;
	scanf("%d", &n);
	num = (int*)malloc(sizeof(int)*(n));
	b = (int*)malloc(sizeof(int)*(n));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	sort(1, n);
	
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		if (binary(x, 1, n)) printf("1 ");
		else printf("0 ");
	}
	printf("\n");
	return 0;
}
