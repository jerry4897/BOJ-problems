#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ans = 999999;
int p_pose[10];
int s_pose[2];
int s_time[2];
int site[11][11];

void sol(vector<int>f_len, vector<int>s_len) {
	int size1 = (int)f_len.size();
	int size2 = (int)s_len. size();
	int time1 = 1;
	vector<int>f;
	vector<int>s;
	while (time1++ < ans) {
		int cnt = 0;
		for (int i = 0; i < (int)f.size(); i++) {
			f[i]--;
			if (f[i] == s_time[0] * -1) cnt++;
		}
		f.erase(f.begin(), f.begin() + cnt);
		for (int i = 0; i < (int)f_len.size(); i++) {
			if (f_len[i] > 0) f_len[i]--;
			if (!f_len[i] && f.size() < 3) {
				f.push_back(f_len[i]); f_len[i] = -1;
			}
		}
		cnt = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			s[i]--;
			if (s[i] == s_time[1] * -1) cnt++;
		}
		s.erase(s.begin(), s.begin() + cnt);
		for (int i = 0; i < (int)s_len.size(); i++) {
			if (s_len[i] > 0) s_len[i]--;
			if (!s_len[i] && s.size() < 3) {
				s.push_back(s_len[i]); s_len[i] = -1;
			}
		}

		if (!(int)f.size() && !(int)s.size()) {
			int flag = 1;
			for (int i = 0; i < size1; i++) {
				if (f_len[i] != -1) {
					flag = 0; break;
				}
			}
			for (int i = 0; i < size2; i++) {
				if (s_len[i] != -1) {
					flag = 0; break;
				}
			}
			if (flag && time1 < ans) {
				ans = time1;
				return;
			}
		}
	}
}
void cal(vector<int>first, vector<int>second) {
	int size1 = (int)first.size();
	int size2 = (int)second.size();
	vector<int> f_len(size1);
	vector<int> s_len(size2);
	for (int i = 0; i < size1; i++) {
		int distance = abs(s_pose[0] / N - p_pose[first[i]] / N);
		distance += abs(s_pose[0] % N - p_pose[first[i]] % N);
		f_len[i] = distance;
	}
	for (int i = 0; i < size2; i++) {
		int distance = abs(s_pose[1] / N - p_pose[second[i]] / N);
		distance += abs(s_pose[1] % N - p_pose[second[i]] % N);
		s_len[i] = distance;
	}
	sort(f_len.begin(), f_len.end());
	sort(s_len.begin(), s_len.end());
	sol(f_len, s_len);
}
void make(int people) {
	for (int i = 0; i < pow(2, people); i++) {
		vector<int> first;
		vector<int> second;
		for (int j = 0; j < people; j++) {
			int tmp = (int)pow(2, j);
			if (i&tmp) first.push_back(j);
			else second.push_back(j);
		}
		cal(first, second);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		int people = 0;
		int stair = 0;
		ans = 999999;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> site[i][j];
				if (site[i][j] == 1) p_pose[people++] = i*N + j;
				else if (site[i][j] > 1) {
					s_pose[stair] = i*N + j;
					s_time[stair++] = site[i][j];
				}
			}
		}
		vector<int>first;
		vector<int>second;
		make(people);

		printf("#%d %d\n", t, ans);
	}
	return 0;
}
