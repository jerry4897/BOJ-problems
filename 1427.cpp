#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <long long int> arr;
int main() {
	long long int n;
	
	cin >> n;
	while (n) {
		arr.push_back(n % 10);
		n /= 10;
	}
	sort(arr.begin(), arr.end());

	for (int i = arr.size() - 1; i >= 0; i--) {
		cout << arr[i];
	}
	cout << endl;
	return 0;
}
