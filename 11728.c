#include<stdio.h>
#include<stdlib.h>
int* a;
int* b;
int* c;
int n, m;

int main()
{	
	int i = 1, j = 1, k = 1;
	scanf("%d%d", &n, &m);
	a = (int*)malloc(sizeof(int)*(n + 1));
	b = (int*)malloc(sizeof(int)*(m + 1));
	c = (int*)malloc(sizeof(int)*(n + m + 2));
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	
	while (i <= n&&j <= m) {
		if (a[i] < b[j]) c[k++] = a[i++];
		else c[k++] = b[j++];
	}
	while (i <= n) c[k++] = a[i++];
	while (j <= m) c[k++] = b[j++];

	for (int l = 1; l <= n + m; l++) printf("%d ", c[l]);
	printf("\n");
	return 0;
}
