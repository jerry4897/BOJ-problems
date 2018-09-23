#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<map>

using namespace std;
int A, B, C;
int ans[201];
int visited[201][201][201];
string water = "";
map <int, int> m;
queue <string> q;

void move(int a, int b, int c) {
	string tmp;
	if (a) {
		if (a <= B - b) {
			if (!visited[0][a + b][c]) {
				visited[0][a + b][c] = 1;
				tmp = "0," + to_string(a + b) + "," + to_string(c);
				q.push(tmp);
			}
		}
		else if (a > B - b) {
			if (!visited[a - (B - b)][B][c]) {
				visited[a-(B-b)][B][c] = 1;
				tmp = to_string(a-(B-b)) + "," + to_string(B) + "," + to_string(c);
				q.push(tmp);
			}
			if (a - (B - b) < C - c) {
				if (!visited[0][B][c + a - (B - b)]) {
					visited[0][B][c + a - (B - b)] = 1;
					tmp = "0," + to_string(B) + "," + to_string(c + a - (B - b));
					q.push(tmp);
				}
			}
			else {
				if (!visited[a - (B - b) - (C - c)][B][C]) {
					visited[a - (B - b) - (C - c)][B][C] = 1;
					tmp = to_string(a - (B - b) - (C - c)) + "," + to_string(B) + "," + to_string(C);
					q.push(tmp);
				}
			}
		}
		
		if (a <= C - c) {
			if (!visited[0][b][a + c]) {
				visited[0][b][a + c] = 1;
				tmp = "0," + to_string(b) + "," + to_string(a + c);
				q.push(tmp);
			}
		}
		else if (a > C - c) {
			if (!visited[a - (C - c)][b][C]) {
				visited[a - (C - c)][b][C] = 1;
				tmp = to_string(a - (C - c)) + "," + to_string(b) + "," + to_string(C);
				q.push(tmp);
			}
			if (a - (C - c) < B - b) {
				if (!visited[0][b + a - (C - c)][C]) {
					visited[0][b + a - (C - c)][C] = 1;
					tmp = "0," + to_string(b + a - (C - c)) + "," + to_string(C);
					q.push(tmp);
				}
			}
			else {
				if (!visited[a - (B - b) - (C - c)][B][C]) {
					visited[a - (B - b) - (C - c)][B][C] = 1;
					tmp = to_string(a - (B - b) - (C - c)) + "," + to_string(B) + "," + to_string(C);
					q.push(tmp);
				}
			}
		}
	}
	if (b) {
		if (b <= A - a) {
			if (!visited[a + b][0][c]) {
				visited[a + b][0][c] = 1;
				tmp = to_string(a + b) + ",0," + to_string(c);
				q.push(tmp);
			}
		}
		else if (b > A - a) {
			if (!visited[A][b - (A - a)][c]) {
				visited[A][b - (A - a)][c] = 1;
				tmp = to_string(A) + "," + to_string(b - (A - a)) + "," + to_string(c);
				q.push(tmp);
			}
			if (b - (A - a) < C - c) {
				if (!visited[A][0][c + b - (A - a)]) {
					visited[A][0][c + b - (A - a)] = 1;
					tmp = to_string(A) + ",0," + to_string(c + b - (A - a));
					q.push(tmp);
				}
			}
			else {
				if (!visited[A][b - (A - a) - (C - c)][C]) {
					visited[A][b - (A - a) - (C - c)][C] = 1;
					tmp = to_string(A) + "," + to_string(b - (A - a) - (C - c)) + "," + to_string(C);
					q.push(tmp);
				}
			}
		}

		if (b <= C - c) {
			if (!visited[a][0][b + c]) {
				visited[a][0][b + c] = 1;
				tmp = to_string(a) + ",0," + to_string(b + c);
				q.push(tmp);
			}
		}
		else if (b > C - c) {
			if (!visited[a][b - (C - c)][C]) {
				visited[a][b - (C - c)][C] = 1;
				tmp = to_string(a) + "," + to_string(b - (C - c)) + "," + to_string(C);
				q.push(tmp);
			}
			if (b - (C - c) < A - a) {
				if (!visited[a + b - (C - c)][0][C]) {
					visited[a + b - (C - c)][0][C] = 1;
					tmp = to_string(a + b - (C - c)) + ",0," + to_string(C);
					q.push(tmp);
				}
			}
			else {
				if (!visited[A][b - (A - a) - (C - c)][C]) {
					visited[A][b - (A - a) - (C - c)][C] = 1;
					tmp = to_string(A) + "," + to_string(b - (A - a) - (C - c)) + "," + to_string(C);
					q.push(tmp);
				}
			}
		}
	}
	if (c) {
		if (c <= A - a) {
			if (!visited[a + c][b][0]) {
				visited[a + c][b][0] = 1;
				tmp = to_string(a + c) + "," + to_string(b) + ",0";
				q.push(tmp);
			}
		}
		else if (c > A - a) {
			if (!visited[A][b][c - (A - a)]) {
				visited[A][b][c - (A - a)] = 1;
				tmp = to_string(A) + "," + to_string(b) + "," + to_string(c - (A - a));
				q.push(tmp);
			}
			if (c - (A - a) < B - b) {
				if (!visited[A][b + c - (A - a)][0]) {
					visited[A][b + c - (A - a)][0] = 1;
					tmp = to_string(A) + "," + to_string(b + c - (A - a)) + ",0";
					q.push(tmp);
				}
			}
			else {
				if (!visited[A][B][C - (A - a) - (B - b)]) {
					visited[A][B][C - (A - a) - (B - b)] = 1;
					tmp = to_string(A) + "," + to_string(B) + "," + to_string(C - (A - a) - (B - b));
					q.push(tmp);
				}
			}
		}

		if (c <= B - b) {
			if (!visited[a][b + c][0]) {
				visited[a][b + c][0] = 1;
				tmp = to_string(a) + "," + to_string(b + c) + ",0";
				q.push(tmp);
			}
		}
		else if (c > B - b) {
			if (!visited[a][B][c - (B - b)]) {
				visited[a][B][c - (B - b)] = 1;
				tmp = to_string(a) + "," + to_string(B) + "," + to_string(c - (B - b));
				q.push(tmp);
			}
			if (c - (B - b) < A - a) {
				if (!visited[a + c - (B - b)][B][0]) {
					visited[a + c - (B - b)][B][0] = 1;
					tmp = to_string(a + c - (B - b)) + "," + to_string(B) + ",0";
					q.push(tmp);
				}
			}
			else {
				if (!visited[A][B][c - (A - a) - (B - b)]) {
					visited[A][B][c - (A - a) - (B - b)] = 1;
					tmp = to_string(A) + "," + to_string(B) + "," + to_string(c - (A - a) - (B - b));
					q.push(tmp);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &A, &B, &C);
	for (int i = 0; i <= C; i++) ans[i] = 0;
	for (int i = 0; i <= A; i++)
		for (int j = 0; j <= B; j++)
			for (int k = 0; k <= C; k++)
				visited[i][j][k] = 0;
	water = "0,0," + to_string(C);
	q.push(water);
	m[stoi(water)] = 0;
	visited[0][0][C] = 1;
	ans[C] = 1;

	while (!q.empty()) {
		string now = q.front();
		char *a, *b, *c;
		a = strtok(&now[0], ",");
		b = strtok(NULL, ",");
		c = strtok(NULL, ",");
		/*if (!visited[stoi(a)][stoi(b)][stoi(c)]) {
			visited[stoi(a)][stoi(b)][stoi(c)] = 1;
			q.push(string(a) + "," + string(b) + "," + string(c));
		}*/
		//cout << a << " " << b << " " << c << "\n";
		if (atoi(a) == 0) {
			ans[stoi(c)] = 1;
		}
		q.pop();
		move(atoi(a),atoi(b),atoi(c));
	}
	for (int i = 0; i <= C; i++) {
		if (ans[i]) printf("%d ", i);
	}
	printf("\n");
	return 0;
}
