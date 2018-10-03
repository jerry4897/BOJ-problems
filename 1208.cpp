#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, s;

int main() {
	long long int ans = 0, cnt1 = 0, cnt2 = 0;
	cin >> n >> s;
	vector<int> num(n);
	vector<int> first;
	vector<int> second;
	for (int i = 0; i < n; i++) cin >> num[i];

	int m = n / 2;
	for (long long int i = 1; i < (1 << m); i++) {
		int sum = 0;
		for (int k = 0; k < m; k++) {
			if ((i & (1 << k))) {
				sum += num[k];
			}
		}
		cnt1++;
		first.push_back(sum);
	}
	for (long long int i = 1; i < (1 << (n-m)); i++) {
		int sum = 0;
		for (int k = m; k < n; k++) {
			if ((i & (1 << k-m))) {
				sum += num[k];
			}
		}
		cnt2++;
		second.push_back(sum);
	}
	first.push_back(0);
	second.push_back(0);
	cnt1++; cnt2++;

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	long long int i = 0, j = cnt2 - 1;
	while (i < cnt1 && j >= 0) {
		int sum = first[i] + second[j];
		if (sum == s) {
			long long int tmp1 = i, tmp2 = j;
			long long int tcnt1 = 0, tcnt2 = 0;

			while (tmp1 < cnt1 && first[i] == first[tmp1++]) tcnt1++;
			while (tmp2 >= 0 && second[j] == second[tmp2--]) tcnt2++;

			ans += (tcnt1)*(tcnt2);
			i += tcnt1;
			j -= tcnt2;
		}
		else if (sum > s) j--;
		else i++;
	}

	if(s) cout << ans << "\n";
	else cout << ans - 1 << "\n";

	return 0;
}
