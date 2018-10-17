#include <iostream>
using namespace std;
int N, ans;
int x_pos[4] = { -1,0,1,0 };
int y_pos[4] = { 0,1,0,-1 };
int map[101][101];
int white[5];
int init_x, init_y;
void go(int x, int y, int direc) {
	while (1) {
		if (x < 0 || x == N || y < 0 || y == N) {
			direc += 2;
			direc %= 4;
			ans++;
		}
		else if (x == init_x && y == init_y) {
			return;
		}
		else {
			ans++;
			if (map[x][y] == 1) {
				if (direc == 0 || direc == 1) direc += 2;
				else {
					if (direc == 2) direc = 1;
					else direc = 0;
				}
			}
			else if (map[x][y] == 2) {
				if (direc == 1 || direc == 2) {
					direc += 2;
					direc %= 4;
				}
				else if (direc == 0) direc = 1;
				else direc = 2;
			}
			else if (map[x][y] == 3) {
				if (direc == 2 || direc == 3) {
					direc += 2;
					direc %= 4;
				}
				else if (direc == 0) direc = 3;
				else direc = 2;
			}
			else if (map[x][y] == 4) {
				if (direc == 0 || direc == 3) {
					direc += 2;
					direc %= 4;
				}
				else if (direc == 1) direc = 0;
				else direc = 3;
			}
			else if (map[x][y] == 5) {
				direc += 2;
				direc %= 4;
			}
			else if (map[x][y] >= 6 && map[x][y] <= 10) {
				ans--;
				int tmp = white[map[x][y] - 6] - (x*N + y);
				x = tmp / N;
				y = tmp % N;
			}
			else if (map[x][y] == -1) {
				ans--;
				return;
			}
			else ans--;
		}
		x += x_pos[direc];
		y += y_pos[direc];
	}
}
int main() {
	int T, max = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ans = max = 0;
		for (int i = 0; i < 5; i++) white[i] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					white[map[i][j] - 6] += i*N + j;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!map[i][j]) {
					init_x = i; init_y = j;
					for (int direc = 0; direc < 4; direc++) {
						ans = 0;
						go(i + x_pos[direc], j + y_pos[direc], direc);
						if (max < ans) max = ans;
					}
				}
			}
		}
		printf("#%d %d\n", t, max);
	}
	return 0;
}
