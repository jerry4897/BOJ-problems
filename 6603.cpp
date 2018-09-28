#include<iostream>
#include<vector>
#include<string>
using namespace std;
int k;
bool pick(vector <int> s, int now, int len, int flag, vector <int> num) {
	vector<int>tmp = num;
	if (flag) num[len - 1] = s[now];
	if (len == 6) {
		for (int i = 0; i < len; i++)
			cout << num[i] << " ";
		cout << "\n";
		return true;
	}
	else if (now == k - 1) return false;
	pick(s, now + 1, len + 1, 1, num);
	pick(s, now + 1, len, 0, num);
	return false;
}
int main() {
	while (1) {
		cin >> k;
		if (!k) break;

		vector<int> s(k);
		vector<int> num(k);
		for (int i = 0; i < k; i++) cin >> s[i];
		pick(s, 0, 1, 1, num);
		pick(s, 0, 0, 0, num);
		cout << "\n";
	}
	return 0;
}
