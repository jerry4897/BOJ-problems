#include <iostream>
#include <vector>
#include <list>
using namespace std;
int move_x[4] = { 1, 1, -1, -1 };
int move_y[4] = { 1, -1, -1, 1 };
int N, ans = -1;
int site[21][21];

void find(int x, int y) {
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - i; j++) {
			bool visited[101] = { 0 };
			int flag = 1;
			if (ans > (i * 2) + (j * 2)) continue;
			int sw = 1;
			int nx = x;
			int ny = y;
			for (int k = 0; k < 2; k++) {
				for (int ii = 0; ii < i; ii++) {
					nx += sw;
					ny += sw;
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
						flag = 0;
						break;
					}
					if (!visited[site[nx][ny]]) {
						visited[site[nx][ny]] = 1;
					}
					else {
						flag = 0;
					}
				}
				if (!flag) break;
				for (int jj = 0; jj < j; jj++) {
					nx += sw;
					ny -= sw;
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
						flag = 0;
						break;
					}
					if (!visited[site[nx][ny]]) {
						visited[site[nx][ny]] = 1;
					}
					else {
						flag = 0;
						break;
					}
				}
				if (!flag) break;
				sw *= -1;
			}
			if (flag && ans < (i * 2) + (j * 2)) {
				ans = (i * 2) + (j * 2);
			}
		}
	}
}
void start() {
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < N - 1; j++) {
			find(i, j);
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> site[i][j];
			}
		}
		start();
		printf("#%d %d\n", t, ans);
		ans = -1;
	}
	return 0;
}
