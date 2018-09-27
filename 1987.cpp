#include<iostream>
#include<vector>
#include<string>
using namespace std;
int R, C;
vector <bool> alpha(26);
vector <vector<char>> board;

int track(int x, int y) {
	int ans = 0;
	if (y + 1 < C) {
		if (alpha[board[x][y + 1] - 'A'] == false) {
			alpha[board[x][y + 1] - 'A'] = true;
			int tmp = track(x, y + 1);
			if (ans < tmp) ans = tmp;
			alpha[board[x][y + 1] - 'A'] = false;
		}
	}
	if (x + 1 < R) {
		if (alpha[board[x + 1][y] - 'A'] == false) {
			alpha[board[x + 1][y] - 'A'] = true;
			int tmp = track(x + 1, y);
			if (ans < tmp) ans = tmp;
			alpha[board[x + 1][y] - 'A'] = false;
		}
	}
	if (y - 1 >= 0) {
		if (alpha[board[x][y - 1] - 'A'] == false) {
			alpha[board[x][y - 1] - 'A'] = true;
			int tmp = track(x, y - 1);
			if (ans < tmp) ans = tmp;
			alpha[board[x][y - 1] - 'A'] = false;
		}
	}
	if (x - 1 >= 0) {
		if (alpha[board[x - 1][y] - 'A'] == false) {
			alpha[board[x - 1][y] - 'A'] = true;
			int tmp = track(x - 1, y);
			if (ans < tmp) ans = tmp;
			alpha[board[x - 1][y] - 'A'] = false;
		}
	}
	return ans + 1;
}
int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		vector<char>temp(C);
		board.push_back(temp);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	alpha[board[0][0] - 'A'] = true;
	cout << track(0, 0) << "\n";
	return 0;
}
