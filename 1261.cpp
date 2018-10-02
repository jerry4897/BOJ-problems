#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
int n, m;
int x[4] = { 0,1,0,-1 };
int y[4] = { 1,0,-1,0 };
deque<int> q;

void solve(vector<string> maze, vector<vector<int>> &cnt, vector<vector<bool>> &visited, int ox, int oy) {
	for (int i = 0; i < 4; i++) {
		int nx = ox + x[i];
		int ny = oy + y[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!visited[nx][ny]) {
				visited[nx][ny] = 1;
				if (maze[nx][ny] == '0') {
					cnt[nx][ny] = cnt[ox][oy];
					q.push_front(nx*m + ny);
				}
				else {
					cnt[nx][ny] = cnt[ox][oy] + 1;
					q.push_back(nx*m + ny);
				}
			}
		}
	}
	return;
}
int main() {
	cin >> m >> n;
	vector<string> maze(n);
	vector<vector<bool>> visited;
	vector<vector<int>> cnt;
	for (int i = 0; i < n; i++) {
		vector<bool> tmp(m);
		vector<int> tmp1(m);
		visited.push_back(tmp);
		cnt.push_back(tmp1);
	}
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
	visited[0][0] = true;
	cnt[0][0] = 0;
	q.push_back(0);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop_front();
		int dx = tmp / m;
		int dy = tmp % m;
		solve(maze, cnt, visited, dx, dy);
	}
	cout << cnt[n-1][m-1] << "\n";
	return 0;
}
