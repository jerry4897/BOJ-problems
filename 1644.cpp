#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	cnt = n - 1;
	vector<int> arr(n + 1);
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; i*j <= n; j++) {
			if (!arr[i*j]) {
				arr[i*j] = 1;
				cnt--;
			}
		}
	}
	vector<int>prime(cnt);
	int tmp = 0;
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) prime[tmp++] = i;
	}

	int i = 0, j = 0, ans = 0;
	if (cnt) {
		int su = prime[0];
		while (i <= j && j < cnt) {
			if (su < n) {
				j++;
				if (j < cnt) su += prime[j];
			}
			else if (su == n) {
				ans++;
				j++;
				if (j < cnt) su += prime[j];
			}
			else if (su > n) {
				su -= prime[i];
				i++;
				if (i > j && i < cnt) {
					su += prime[i];
					j = i;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
