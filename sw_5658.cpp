#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <list>
using namespace std;
list<long long int> lst;
int N, K;
void rotate(deque<long long int> dq, int num) {
	int len = N / 4;
	long long int multi = 1;
	for (int i = 0; i < len - 1; i++) multi *= 16;
	for (int i = 0; i < num; i++) {
		long long int tmp = dq.back();
		dq.push_front(tmp);
		dq.pop_back();
	}

	for (int i = 0; i < N; i += len) {
		long long int res = 0;
		long long int mul = multi;
		for (int j = i; j < i + len; j++) {
			res += dq[j] * mul;
			mul /= 16;
		}
		lst.push_back(res);
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		deque<long long int> dq;
		for (int i = 0; i < N; i++) {
			int num;
			scanf("%1x", &num);
			dq.push_back(num);
		}
		for (int i = 0; i < N / 4; i++) {
			rotate(dq, i);
		}
		
		lst.sort();
		lst.unique();
		lst.reverse();
		int i = 0;
		for (std::list<long long int>::iterator it = lst.begin(); it != lst.end(); ++it) {
			if (i++ == K-1) {
				printf("#%d %d\n", t, *it);
				break;
			}
		}
		lst.clear();
	}
	return 0;
}
