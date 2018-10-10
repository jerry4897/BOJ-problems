#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ans = 0, N, M, R, C, L;
int visited[50][50];
queue<int> q;
queue<int> tq;
void bfs(int x, int y, int time, int arr[50][50]) {
	visited[x][y] = 1;
	if (time == L) return;
	int pos_x[4] = { 0, 1, 0, -1 };
	int pos_y[4] = { 1, 0, -1, 0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + pos_x[i];
		int ny = y + pos_y[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && arr[nx][ny]){
			switch (arr[x][y]) {
			case 1 :
				if (i == 0 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 6 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 1 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 4 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 2 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 5)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 3 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 6)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				break;
			case 2 :
				if (i == 1 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 4 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 3 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 6)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				break;
			case 3 :
				if (i == 0 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 6 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 2 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 5)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				break;
			case 4 :
				if (i == 0 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 6 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 3 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 6)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				break;
			case 5 :
				if (i == 0 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 6 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 1 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 4 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				break;
			case 6 :
				if (i == 1 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 4 || arr[nx][ny] == 7)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 2 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 5)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				break;
			case 7 :
				if (i == 2 && (arr[nx][ny] == 1 || arr[nx][ny] == 3 || arr[nx][ny] == 4 || arr[nx][ny] == 5)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				else if (i == 3 && (arr[nx][ny] == 1 || arr[nx][ny] == 2 || arr[nx][ny] == 5 || arr[nx][ny] == 6)) {
					q.push(nx*M + ny);
					tq.push(time + 1);
				}
				break;
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		int arr[50][50];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}
		q.push(R*M + C);
		tq.push(1);
		while (!q.empty()) {
			int np = q.front();
			int nt = tq.front();
			q.pop();
			tq.pop();
			bfs(np / M, np%M, nt, arr);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j]) {
					ans++;
					visited[i][j] = 0;
				}
			}
		}
		cout << "#" << t << " " << ans << "\n";
		ans = 0;
	}
	return 0;
}
