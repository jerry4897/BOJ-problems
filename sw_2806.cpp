#include <iostream>
using namespace std;
int N, ans;
int x_pos[4] = { 1,1,-1,-1 };
int y_pos[4] = { 1,-1,-1,1 };
int check(int x, int y, int site[10][10]) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (site[i][y]) cnt++;
	}
	if (cnt > 1) return 0;

	cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < 4; j++) {
			int nx = x + x_pos[j] * (i + 1);
			int ny = y + y_pos[j] * (i + 1);
			if (nx >= 0 && nx < N&&ny >= 0 && ny < N) {
				if (site[nx][ny]) cnt++;
			}
		}
	}
	if (cnt) return 0;
	return 1;
}
void find(int row, int col, int site[10][10]) {
	site[row][col] = 1;
	if (check(row, col, site)) {
		if (row == N - 1) {
			ans++;
		}
		else {
			find(row + 1, 0, site);
			site[row + 1][0] = 0;
		}
	}
	if (col < N - 1) {
		site[row][col] = 0;
		find(row, col + 1, site);
		site[row][col + 1] = 0;
	}
	else return;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = 0;
		int site[10][10] = { 0, };
		find(0, 0, site);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
