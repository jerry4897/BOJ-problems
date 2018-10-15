#include <iostream>
using namespace std;
int N, M, ans = 0;
int site[21][21];

void find(int x, int y) {
	for (int k = 1; k <= 2 * N; k++) {
		int cnt = 0;
		int pro = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (site[i][j]) {
					int distance = abs(i - x);
					distance += abs(j - y);
					if (distance < k) {
						cnt++;
					}
				}
			}
		}
		pro = cnt * M - k*k - (k - 1)*(k - 1);
		if (pro >= 0 && cnt > ans) {
			ans = cnt;
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> site[i][j];
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				find(i, j);
			}
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
