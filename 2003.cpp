#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long int n, s, ans = 0;
	cin >> n >> s;
	vector<long long int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int  i = 0, j = 0;
	long long int su = arr[0];
	while (i <= j && j < n) {
		if (su < s) {
			j++;
			if(j < n) su += arr[j];
		}
		else if (su == s) {
			ans++;
			j++;
			if(j < n) su += arr[j];
		}
		else if (su > s) {
			su -= arr[i];
			i++;
			if (i > j && i < n) {
				su += arr[i];
				j = i;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
