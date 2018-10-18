#include <iostream>
#include <vector>
using namespace std;
class atom {
public:
	int x;
	int y;
	int direc;
	int power;
};
int N;
int main() {
	int T, min;
	vector<vector<int>> map;
	atom *a = new atom[1000];
	atom aq[1000];
	map.assign(4002, vector<int>(4002, 0));
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int ans = 0, front = 0, end = 0, size = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a[i].x >> a[i].y >> a[i].direc >> a[i].power;
			a[i].x += 1000;	a[i].x *= 2;
			a[i].y += 1000;	a[i].y *= 2;
			map[a[i].x][a[i].y] = a[i].power;
			aq[end] = a[i];
			end = (end + 1) % 1000;
			size++;
		}
		for (int i = 0; i < 4002; i++) {
			int len = size;
			for (int j = 0; j < len; j++) {
				atom tmp = aq[front];
				front = (front + 1) % 1000;
				size--;
				map[tmp.x][tmp.y] -= tmp.power;
				switch (tmp.direc) {
				case 0:tmp.y++; break;
				case 1:tmp.y--; break;
				case 2:tmp.x--; break;
				case 3:tmp.x++;
				}
				if (tmp.x >= 0 && tmp.x <= 4000 && tmp.y >= 0 && tmp.y <= 4000) {
					map[tmp.x][tmp.y] += tmp.power;
					aq[end] = tmp;
					end = (end + 1) % 1000;
					size++;
				}
			}
			len = size;
			for (int j = 0; j < len; j++) {
				atom tmp = aq[front];
				front = (front + 1) % 1000;
				size--;
				if (map[tmp.x][tmp.y] != tmp.power) {
					ans += map[tmp.x][tmp.y];
					map[tmp.x][tmp.y] = 0;
				}
				else {
					aq[end] = tmp;
					end = (end + 1) % 1000;
					size++;
				}
			}
			if (size <= 0) break;
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
