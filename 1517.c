#include<stdio.h>
#include<stdlib.h>

int* a;
int* b;

long long int sort(int start, int end) {
	long long int cnt = 0;
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	if (start == end) return 0;
	
	cnt = sort(start, mid) + sort(mid + 1, end);
	while (i <= mid && j <= end) {
		if (a[i] < a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
			cnt += (long long int)(mid - i + 1);
		}
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= end) b[k++] = a[j++];

	for (int i = start; i <= end; i++) a[i] = b[i - start];
	return cnt;
}
int main() 
{
	int n;

	scanf("%d", &n);
	a = (int*)malloc(sizeof(int)*(n + 1));
	b = (int*)malloc(sizeof(int)*(n + 1));
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	
	printf("%lld\n", sort(1, n));

	free(a);
	free(b);
	return 0;
}
