#include <iostream>
#include <vector>
using namespace std;
int N, M, airport;
class travel {
public:
	int score;
	int time;
};
travel p[36];
int a[36][36];
int info[36]; // 0 : airport, 1 : P, 2 : hotel
int ans[40];
int siz = 0;
int max_;
void bfs(int day, int time, int score, int now, bool visited[36], int route_num, int route[40]) {
	if (info[now] == 1) {
		score += p[now].score;
		time += p[now].time;
	}
	if (time > 540) return;

	if (day == M) {
		if (now == airport) {
			if (score > max_) {
				max_ = score;
				for (int i = 1; i <= route_num; i++) {
					ans[i] = route[i];
				}
				siz = route_num;
			}
			return;
		}
		else {
			for (int i = 1; i <= N; i++) {
				if (!visited[i] && info[i] != 2) {
					if (info[i] == 1) {
						if (time + a[now][i] + p[i].time + a[i][airport] > 540) continue;
						else {
							visited[i] = 1;
							route[route_num + 1] = i;
							bfs(day, time + a[now][i], score, i, visited, route_num + 1, route);
							visited[i] = 0;
							route[route_num + 1] = 0;
						}
					}
					else {
						visited[i] = 1;
						route[route_num + 1] = i;
						bfs(day, time + a[now][i], score, i, visited, route_num + 1, route);
						visited[i] = 0;
						route[route_num + 1] = 0;
					}
				}
			}
		}
	}
	else if (now == airport) return;
	else if (info[now] == 2 && day < M) {
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && info[i] == 1) {
				if(info[i] != 2) visited[i] = 1;
				route[route_num + 1] = i;
				bfs(day + 1, a[now][i], score, i, visited, route_num + 1, route);
				visited[i] = 0;
				route[route_num + 1] = 0;
			}
		}
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				if(info[i] != 2) visited[i] = 1;
				route[route_num + 1] = i;
				bfs(day, time + a[now][i], score, i, visited, route_num + 1, route);
				visited[i] = 0;
				route[route_num + 1] = 0;
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		max_ = siz = 0;
		cin >> N >> M;
		bool visited[36] = { 0, };
		int route[40];
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				cin >> a[i][j];
				a[j][i] = a[i][j];
			}
		}
		for (int i = 1; i <= N; i++) {
			char c;
			cin >> c;
			if (c == 'P') {
				info[i] = 1;
				cin >> p[i].time >> p[i].score;
			}
			else if (c == 'A') {
				airport = i;
				info[i] = 0;
			}
			else info[i] = 2;
		}

		for (int i = 1; i <= N; i++) {
			if (info[i] == 1) {
				visited[i] = 1;
				route[1] = i;
				bfs(1, a[airport][i], 0, i, visited, 1, route);
				visited[i] = 0;
				route[1] = 0;
			}
		}
		printf("#%d %d", t, max_);
		if (max_) {
			for (int i = 1; i <= siz; i++)
				cout << ' ' << ans[i];
		}
		cout << '\n';
	}
	return 0;
}
