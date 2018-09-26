#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;
vector <vector <int>> v;
list <int> mlist;
int N, tmp, ans = 100000000;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> tmp(N);
		v.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		mlist.push_back(i);
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	do {
		tmp = 0;
		for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
			list<int>::iterator itt = ++it;
			it--;
			if (itt == mlist.end()) {
				if(v[*it][mlist.front()]) tmp += v[*it][mlist.front()];
				else {
					tmp = 100000000;
					break;
				}
			}
			else if (v[*it][*itt]) {
				tmp += v[*it][*itt];
			}
			else {
				tmp = 100000000;
				break;
			}
		}
		if (ans > tmp) ans = tmp;
	} while (next_permutation(mlist.begin(), mlist.end()));

	printf("%d\n", ans);
	return 0;
}
