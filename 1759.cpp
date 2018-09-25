#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;
int L, C;

bool check(string pw) {
	int mo = 0, ja = 0;
	for (int i = 0; i < L; i++) {
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
			mo++;
		else ja++;
	}
	
	if (mo && ja >= 2) return true;
	else return false;
}

void go(vector<char> c, string pw, int i) {
	if (pw.length() == L) {
		if (check(pw)) cout << pw << "\n";
		return;
	}
	if (i == C) return;
	go(c, pw + c[i], i + 1);
	go(c, pw, i + 1);
}

int main() {
	scanf("%d%d", &L, &C);
	vector<char> c(C);
	for (int i = 0; i < C; i++) cin >> c[i];
	sort(c.begin(), c.end());
	go(c, "", 0);
	return 0;
}
