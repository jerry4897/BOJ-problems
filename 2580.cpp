#include<iostream>

using namespace std;
int sdo[10][10];

int row(int z, int num) {
	int x = z / 9;
	for (int i = 0; i < 9; i++) {
		if (sdo[x][i] == num) return 1;
	}
	return 0;
}
int col(int z, int num) {
	int y = z % 9;
	for (int i = 0; i < 9; i++) {
		if (sdo[i][y] == num) return 1;
	}
	return 0;
}
int box(int z, int num) {
	int x = z / 9;
	int y = z % 9;
	x /= 3;
	x *= 3;
	y /= 3;
	y *= 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (sdo[i][j] == num) return 1;
		}
	}
	return 0;
}
bool solve(int z) {
	if (z > 80) return true;
	int x = z / 9;
	int y = z % 9;
	if (sdo[x][y]) {
		if (solve(z + 1)) return true;
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (!row(z, i) && !col(z, i) && !box(z, i)) {
				sdo[x][y] = i;
				if (solve(z + 1)) return true;
				sdo[x][y] = 0;
			}
		}
	}
	return false;
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdo[i][j];
		}
	}
	
	solve(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sdo[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
