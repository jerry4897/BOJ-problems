#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, tmp;
	cin >> n;
	vector<int> arr(10001);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) cout << i << '\n';
	}
	return 0;
}
