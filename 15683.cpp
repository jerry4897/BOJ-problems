#include <iostream>
#include <vector>
using namespace std;
int N, M, num = 0, ans;
int cc[10];
void paint(int x, int y, int direc, int site[8][8], int flag, int now) {
	if (direc == 0) {	// 우측
		for (int i = y + 1; i < M; i++) {
			if (site[x][i] == 6) break;
			if (flag == -1) {
				if (site[x][i] <= 0) site[x][i] += flag*now;
			}
			else if (!flag) {
				if (site[x][i] < 0) site[x][i] -= (now * -1);
			}
		}
	}
	else if (direc == 1) {	// 아래
		for (int i = x + 1; i < N; i++) {
			if (site[i][y] == 6) break;
			if (flag == -1) {
				if (site[i][y] <= 0) site[i][y] += flag*now;
			}
			else if (!flag) {
				if (site[i][y] < 0) site[i][y] -= (now * -1);
			}
		}
	}
	else if (direc == 2) {	// 왼
		for (int i = y - 1; i >= 0; i--) {
			if (site[x][i] == 6) break;
			if (flag == -1) {
				if (site[x][i] <= 0) site[x][i] += flag*now;
			}
			else if (!flag) {
				if (site[x][i] < 0) site[x][i] -= (now*-1);
			}
		}
	}
	else {// 위
		for (int i = x - 1; i >= 0; i--) {
			if (site[i][y] == 6) break;
			if (flag == -1) {
				if (site[i][y] <= 0) site[i][y] += flag*now;
			}
			else if (!flag) {
				if (site[i][y] < 0) site[i][y] -= (-1 * now);
			}
		}
	}
}
void find(int x, int y, int site[8][8], int now) {
	int nx, ny;
	if (now < num - 1) {
		nx = cc[now + 1] / M;
		ny = cc[now + 1] % M;
	}

	if (site[x][y] == 1) {
		for (int i = 0; i < 4; i++) {
			paint(x, y, 0 + i, site, -1, now + 1);
			if (now == num - 1) {
				int cnt = 0;
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < M; k++) {
						if (!site[j][k]) cnt++;
					}
				}
				if (ans > cnt) ans = cnt;
			}
			else{
				find(nx, ny, site, now + 1);
			}
			paint(x, y, 0 + i, site, 0, now + 1);
		}
	}
	else if (site[x][y] == 2) {
		for (int i = 0; i < 2; i++) {
			paint(x, y, 0 + i, site, -1, now + 1);
			paint(x, y, (2 + i) % 4, site, -1, now + 1);
			if (now == num - 1) {
				int cnt = 0;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (!site[i][j]) cnt++;
					}
				}
				if (ans > cnt) ans = cnt;
			}
			else {
				find(nx, ny, site, now + 1);
			}
			paint(x, y, 0 + i, site, 0, now + 1);
			paint(x, y, (2 + i) % 4, site, 0, now + 1);
		}
	}
	else if (site[x][y] == 3) {
		for (int i = 0; i < 4; i++) {
			paint(x, y, 0 + i, site, -1, now + 1);
			paint(x, y, (3 + i) % 4, site, -1, now + 1);
			if (now == num - 1) {
				int cnt = 0;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (!site[i][j]) cnt++;
					}
				}
				if (ans > cnt) ans = cnt;
			}
			else {
				find(nx, ny, site, now + 1);
			}
			paint(x, y, 0 + i, site, 0, now + 1);
			paint(x, y, (3 + i) % 4, site, 0, now + 1);
		}
	}
	else if (site[x][y] == 4) {
		for (int i = 0; i < 4; i++) {
			paint(x, y, 0 + i, site, -1, now + 1);
			paint(x, y, (2 + i) % 4, site, -1, now + 1);
			paint(x, y, (3 + i) % 4, site, -1, now + 1);
			if (now == num - 1) {
				int cnt = 0;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (!site[i][j]) cnt++;
					}
				}
				if (ans > cnt) ans = cnt;
			}
			else {
				find(nx, ny, site, now + 1);
			}
			paint(x, y, 0 + i, site, 0, now + 1);
			paint(x, y, (2 + i) % 4, site, 0, now + 1);
			paint(x, y, (3 + i) % 4, site, 0, now + 1);
		}
	}
	else if (site[x][y] == 5) {
		paint(x, y, 0, site, -1, now + 1);
		paint(x, y, 1, site, -1, now + 1);
		paint(x, y, 2, site, -1, now + 1);
		paint(x, y, 3, site, -1, now + 1);
		if (now == num - 1) {
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (!site[i][j]) cnt++;
				}
			}
			if (ans > cnt) ans = cnt;
		}
		else {
			find(nx, ny, site, now + 1);
		}
		paint(x, y, 0, site, 0, now + 1);
		paint(x, y, 1, site, 0, now + 1);
		paint(x, y, 2, site, 0, now + 1);
		paint(x, y, 3, site, 0, now + 1);
	}
}
int main() {
	cin >> N >> M;
	ans = 0;
	int site[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> site[i][j];
			if (site[i][j] > 0 && site[i][j] < 6)cc[num++] = i*M + j;
			else if (!site[i][j]) ans++;
		}
	}

	int nx = cc[0] / M;
	int ny = cc[0] % M;
	find(nx, ny, site, 0);

	cout << ans << "\n";
	return 0;
}
