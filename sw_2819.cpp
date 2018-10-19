#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int pos_x[4] = { 0,1,0,-1 };
int pos_y[4] = { 1,0,-1,0 };
int site[4][4];
list<int> lst;
void dfs(int x, int y, int cnt, int num) {
	if (cnt == 7) {
		lst.push_back(num);
		return;
	}
	else {
		for (int k = 0; k < 4; k++) {
			int nx = x + pos_x[k];
			int ny = y + pos_y[k];
			if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
				dfs(nx, ny, cnt + 1, num * 10 + site[nx][ny]);
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> site[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + pos_x[k];
					int ny = j + pos_y[k];
					if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
						int num = site[i][j] * 10 + site[nx][ny];
						dfs(nx, ny, 2, num);
					}
				}
			}
		}
		lst.sort();
		lst.unique();
		printf("#%d %u\n", t, lst.size());
		lst.clear();
	}
	return 0;
}
