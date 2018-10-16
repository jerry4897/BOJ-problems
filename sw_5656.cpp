#include <iostream>
#include <queue>
using namespace std;
int N, W, H, ans = 180;
int h_pos[4] = { 0, 1, 0, -1 };
int w_pos[4] = { 1, 0, -1, 0 };
queue<int> q;

void crash(vector<vector<int>> &map, int h, int w, vector<vector<int>> &visited) {
	int range = map[h][w];
	map[h][w] = 0;
	visited[h][w] = 1;
	for (int i = 1; i < range; i++) {
		for (int p = 0; p < 4; p++) {
			int nh = h + i*h_pos[p];
			int nw = w + i*w_pos[p];
			if (nh >= 0 && nh < H && nw >= 0 && nw < W) {
				if (map[nh][nw] && !visited[nh][nw]) {
					visited[nh][nw] = 1;
					q.push(nh*W + nw);
				}
			}
		}
	}
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		crash(map, front / W, front%W, visited);
	}
}
void shoot(int N, vector<vector<int>> map, int pos) {
	vector<vector<int>> visited;
	visited.assign(H, vector<int>(W, 0));

	int flag = 0;
	for (int h = 0; h < H; h++) {
		if (map[h][pos]) {
			crash(map, h, pos, visited);
			flag = 1;
			break;
		}
	}
	if (!flag) return;
	// 빈 칸 매꾸기
	for (int i = 0; i < W; i++) {
		for (int j = H - 2; j >= 0; j--) {
			if (map[j][i] && !map[j + 1][i]) {
				int move_to = H - 1;
				for (int k = j + 1; k < H; k++) {
					if (map[k][i]) {
						move_to = k - 1;
						break;
					}
				}
				map[move_to][i] = map[j][i];
				map[j][i] = 0;
			}
		}
	}
	
	if (N) {
		for (int w = 0; w < W; w++)
			shoot(N - 1, map, w);
	}
	else {
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j]) cnt++;
			}
		}
		if (ans > cnt) ans = cnt;
	}
	if (!ans) return;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;
		vector<vector<int>> map;
		map.assign(H, vector<int>(W, 0));
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> map[i][j];
		
		for (int k = N; k > 0; k--) {
			for (int w = 0; w < W; w++) {	// finding top brick
				shoot(k - 1, map, w);
			}
		}
		
		printf("#%d %d\n", t, ans);
		ans = 180;
	}
	return 0;
}
