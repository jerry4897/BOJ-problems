#include <iostream>
using namespace std;
int N, M, K, ans = 0;
class germ {
public:
	int state;			// 0 : nothing, 1 : die, 2 : activated, 3 : de-activated
	int life;
	int time;
	int created;
};
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		int width = 2 * K + M + 10;
		int height = 2 * K + N + 10;
		germ **g = new germ*[height];
		for (int i = 0; i < height; i++)
			g[i] = new germ[width];
		//init
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++) 
				g[i][j].state = g[i][j].life = g[i][j].time = 0;

		int x = height / 2; int y = width / 2;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int input;
				cin >> input;
				if (input) {
					g[x + i][y + j].life = input;
					g[x + i][y + j].state = 3;
					g[x + i][y + j].created = 0;
				}
			}
		}
		for (int k = 1; k <= K; k++) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (g[i][j].state == 3 && g[i][j].created != k) {	// 현재 비활성
						g[i][j].time++;
						if (g[i][j].time == g[i][j].life) {
							g[i][j].state = 2;
							g[i][j].time = 0;
						}
					}
					else if (g[i][j].state == 2) {	// 현재 활성
						if (!g[i][j].time) {							
							if (!g[i][j + 1].state) {
								g[i][j + 1].state = 3;
								g[i][j + 1].life = g[i][j].life;
								g[i][j + 1].created = k;
							}
							else if (g[i][j + 1].state == 3 && g[i][j + 1].created == k) {
								if (g[i][j + 1].life < g[i][j].life)
									g[i][j + 1].life = g[i][j].life;
							}
							if (!g[i + 1][j].state) {
								g[i + 1][j].state = 3;
								g[i + 1][j].life = g[i][j].life;
								g[i + 1][j].created = k;
							}
							else if (g[i + 1][j].state == 3 && g[i + 1][j].created == k) {
								if (g[i + 1][j].life < g[i][j].life)
									g[i + 1][j].life = g[i][j].life;
							}
							if (!g[i][j - 1].state) {
								g[i][j - 1].state = 3;
								g[i][j - 1].life = g[i][j].life;
								g[i][j - 1].created = k;
							}
							else if (g[i][j - 1].state == 3 && g[i][j - 1].created == k) {
								if (g[i][j - 1].life < g[i][j].life)
									g[i][j - 1].life = g[i][j].life;
							}
							if (!g[i - 1][j].state) {
								g[i - 1][j].state = 3;
								g[i - 1][j].life = g[i][j].life;
								g[i - 1][j].created = k;
							}
							else if (g[i - 1][j].state == 3 && g[i - 1][j].created == k) {
								if (g[i - 1][j].life < g[i][j].life)
									g[i - 1][j].life = g[i][j].life;
							}
						}
						g[i][j].time++;
						if (g[i][j].time == g[i][j].life) g[i][j].state = 1;
					}
				}
			}
		}
		ans = 0;
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (g[i][j].state == 2 || g[i][j].state == 3) ans++;
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
