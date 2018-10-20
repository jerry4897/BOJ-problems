#include <iostream>
#include <vector>
using namespace std;
int N;
vector<vector<int>> lst(100);
class dragon {
public:
	int x;
	int y;
	int d;
	int g;
};
dragon d[20];
void init_dragon(int dr) {
	int pos = d[dr].x * 200 + d[dr].y;
	lst[dr].push_back(pos);
	switch (d[dr].d) {
	case 0: lst[dr].push_back(pos + 200); break;
	case 1: lst[dr].push_back(pos - 1); break;
	case 2: lst[dr].push_back(pos - 200); break;
	case 3: lst[dr].push_back(pos + 1);
	}
}
void generation(int c_dragon, int gene) {
	int len = lst[c_dragon].size();
	for (int i = len - 1; i > 0; i--) {
		int sub = lst[c_dragon][i] - lst[c_dragon][i - 1];
		switch (sub) {
		case -1:lst[c_dragon].push_back(lst[c_dragon].back() - 200); break;	// y 증가 -> x 감소	
		case 1:lst[c_dragon].push_back(lst[c_dragon].back() + 200); break;	// y 감소 -> x 증가
		case -200: lst[c_dragon].push_back(lst[c_dragon].back() + 1); break;	// x 증가 -> y 증가
		case 200: lst[c_dragon].push_back(lst[c_dragon].back() - 1);		// x 감소 -> y 감소
		}
	}
	if (gene == d[c_dragon].g) return;
	else generation(c_dragon, gene + 1);
}
int main() {
	cin >> N;
	int map[101][101] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> d[i].x >> d[i].y >> d[i].d >> d[i].g;
		init_dragon(i);
		if(d[i].g) generation(i, 1);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < lst[i].size(); j++) {
			int xp = lst[i][j] / 200;
			int yp = lst[i][j] % 200;
			if (xp >= 0 && xp <= 100 && yp >= 0 && yp <= 100) map[xp][yp] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j]) {
				if (map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) cnt++;
			}
		}
	}
	cout << cnt << "\n";
	return 0;
}
