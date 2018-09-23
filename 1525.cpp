#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<map>

using namespace std;
string puzzle = "";
map <int, int> m;
queue <string> q;

string s_swap(string pz, size_t pos, int mode) {
	if (mode == 1) {	//upper
		char tmp = pz[pos];
		pz[pos] = pz[pos - 3];
		pz[pos - 3] = tmp;
	}
	else if (mode == 2) {	//left
		char tmp = pz[pos];
		pz[pos] = pz[pos - 1];
		pz[pos - 1] = tmp;
	}
	else if (mode == 3) {	//right
		char tmp = pz[pos];
		pz[pos] = pz[pos + 1];
		pz[pos + 1] = tmp;
	}
	else {		//down
		char tmp = pz[pos];
		pz[pos] = pz[pos + 3];
		pz[pos + 3] = tmp;
	}
	return pz;
}
void move(string pz) {
	size_t pos = pz.find('0');
	string tmp;
	if (pos%3) {
		tmp = s_swap(pz, pos, 2);
		if (!m.count(stoi(tmp))) {
			q.push(tmp);
			m[stoi(tmp)] = m[stoi(pz)] + 1;
		}
	}
	if (pos%3 < 2) {
		tmp = s_swap(pz, pos, 3);
		if (!m.count(stoi(tmp))) {
			q.push(tmp);
			m[stoi(tmp)] = m[stoi(pz)] + 1;
		}
	}
	if (pos > 2) {
		tmp = s_swap(pz, pos, 1);
		if (!m.count(stoi(tmp))) {
			q.push(tmp);
			m[stoi(tmp)] = m[stoi(pz)] + 1;
		}
	}
	if (pos < 6) {
		tmp = s_swap(pz, pos, 4);
		if (!m.count(stoi(tmp))) {
			q.push(tmp);
			m[stoi(tmp)] = m[stoi(pz)] + 1;
		}
	}
}

int main() {
	int flag = 0;
	for (int i = 0; i < 9; i++) {
		int tmp;
		scanf("%d", &tmp);
		puzzle += to_string(tmp);
	}
	q.push(puzzle);
	m[stoi(puzzle)] = 0;

	while (!q.empty()) {
		string now = q.front();
		if (now == "123456780") {
			flag = 1;
			break;
		}
		q.pop();
		move(now);
	}
	if (flag) printf("%d\n", m[123456780]);
	else printf("-1\n");
	return 0;
}
