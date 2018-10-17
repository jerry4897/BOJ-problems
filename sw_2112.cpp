#include <iostream>
#include <vector>
using namespace std;
int D, W, K;
vector<vector<int>> pan;
vector<vector<int>> tpan;
int main() {
	int T, min;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> D >> W >> K;
		min = D;
		pan.assign(D, vector<int>(W));
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				cin >> pan[i][j];

		for (int i = 0; i < (1 << D); i++) {
			int cnt = 0;
			int tmp[13];
			tpan = pan;
			for (int j = 0; j < D; j++) {
				int p = (1 << j);
				if (i&p) {
					tmp[cnt++] = j;
				}
				if (cnt > min) break;
			}
			if (cnt < min) {
				for (int k = 0; k < (1 << cnt); k++) {
					for (int kk = 0; kk < cnt; kk++) {
						int po = (1 <<  kk);
						if (k&po) for (int i = 0; i < W; i++) tpan[tmp[kk]][i] = 0;
						else for (int i = 0; i < W; i++) tpan[tmp[kk]][i] = 1;
					}
					int flag = 1;
					for (int ii = 0; ii < W; ii++) {
						int count = 1;
						if (flag) {
							for (int jj = 1; jj < D; jj++) {
								if (tpan[jj][ii] == tpan[jj - 1][ii]) count++;
								else count = 1;
								if (count == K) {
									flag = 1;
									break;
								}
								else flag = 0;
							}
						}
						else break;
					}
					if (flag) {
						if (min > cnt) {
							min = cnt;
							break;
						}
					}
				}
			}
		}
		printf("#%d %d\n", t, min);
	}
	return 0;
}
