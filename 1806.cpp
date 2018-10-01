#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long int n, s;
	cin >> n >> s;
	vector<long long int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int i = 0, j = 0, ans = n + 1;
	long long int su = arr[0];
	while (i <= j && j < n) {
		if (su < s) {
			j++;
			if(j < n) su += arr[j];
		}
		else if (su == s) {
			if (j - i + 1 < ans) ans = j - i + 1;
			j++;
			if(j < n) su += arr[j];
		}
		else if (su > s) {
			if (j - i + 1 < ans) ans = j - i + 1;
			su -= arr[i];
			i++;
			if (i > j && i < n) {
				su += arr[i];
				j = i;
			}
		}
	}
	if(ans < n+1) cout << ans << "\n";
	else cout << "0\n";
	return 0;
}
