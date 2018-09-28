#include<iostream>
#include<vector>
using namespace std;
int n, s;
int ans = 0;
vector<int> num(21);

void combine(int cnt, int len, int now, int flag, vector<int> arr) {
	if (flag) {
		arr[len - 1] = num[now];
	}
	if (cnt == len) {
		int tmp = 0;
		for (int i = 0; i < len; i++) tmp += arr[i];
		if (tmp == s) ans++;
		return;
	}
	else if (now == n - 1) return;
	combine(cnt, len + 1, now + 1, 1, arr);
	combine(cnt, len, now + 1, 0, arr);
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> num[i];
	
	for (int i = 1; i <= n; i++) {
		vector<int> arr(21);
		combine(i, 1, 0, 1, arr);
		combine(i, 0, 0, 0, arr);
	}
	cout << ans << "\n";
	return 0;
}
