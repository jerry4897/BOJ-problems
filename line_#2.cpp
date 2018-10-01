#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <string>
#include <vector>
using namespace std;

int next_move(char c) {
	if (c == 'F') return 4;
	else if (c == 'R') return 1;
	else if (c == 'B') return 2;
	else if (c == 'L') return 3;
}
bool check(int entire, int now) {
	size_t found = to_string(entire).find(to_string(now));
	if (found != string::npos) return true;
	else return false;
}
int main() {
	int n ,direc, xpos, ypos;
	char ex, now;
	ex = 'B';
	cin >> n;
	vector<vector<char>> c;
	vector<vector<int>> num;
	vector<vector<bool>> visited;
	vector<vector<int>> map;
	for (int i = 0; i < n; i++) {
		vector<bool>tmp(n);
		vector<int>tmp1(n);
		vector<char>tmpc(n);
		visited.push_back(tmp);
		map.push_back(tmp1);
		c.push_back(tmpc);
		num.push_back(tmp1);
	}
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			map[x][y] = 0;
		}
	}
	visited[0][0] = 1;
	map[0][0] = 2;
	xpos = ypos = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			string node;
			cin >> node;
			now = node[0];
			int weight = stoi(node.substr(1,string::npos));
			c[x][y] = now;
			num[x][y] = weight;
			// @todo Write your code here.
		}
	}

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			now = c[ypos][xpos];
			cout << xpos << " " << ypos << " " << ex << " " << now << endl;
			int weight = num[ypos][xpos];
			direc = (next_move(ex) + next_move(now)) % 4;
			cout << "direc = " << direc << endl;
			if (!direc) {
				ypos -= weight;
				if (visited[ypos][xpos]) {
					if (check(map[ypos][xpos], 4)) {
						cout << xpos << " " << ypos << endl;
						return 0;
					}
					map[ypos][xpos] = (map[ypos][xpos] * 10 + 4);
				}
				else {
					visited[ypos][xpos] = 1;
					map[ypos][xpos] = 4;
				}
			}
			else {
				if (direc == 1)	xpos += weight;
				else if (direc == 2) ypos += weight;
				else xpos -= weight;

				if (visited[ypos][xpos]) {
					if (check(map[ypos][xpos], direc)) {
						cout << xpos << " " << ypos << endl;
						return 0;
					}
					map[ypos][xpos] = (map[ypos][xpos] * 10 + direc);
				}
				else {
					visited[ypos][xpos] = true;
					map[ypos][xpos] = direc;
				}
			}
			ex = direc;
		}
	}
	// @todo Write your code here.
	return 0;
}
