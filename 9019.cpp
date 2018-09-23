#include<iostream>
#include<queue>
#include<string>
#include<string.h>
#include<map>

using namespace std;
int N, K;

int d(int input) {
	return (input*2)%10000;
}
int s(int input) {
	if (input) return input - 1;
	else return 9999;
}
int l(int input) {
	return (input % 1000) * 10 + input / 1000;
}
int r(int input) {
	return (input % 10) * 1000 + input / 10;
}

int main() {
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		queue <int> q;
		long long int arr[10000];

		for (int i = 0; i < 10000; i++) arr[i] = -1;
		scanf("%d%d", &N, &K);
		arr[N] = 0;
		q.push(N);

		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			if (tmp == K) break;
			else {
				int d_ = d(tmp);
				int s_ = s(tmp);
				int l_ = l(tmp);
				int r_ = r(tmp);
				if (arr[d_] < 0) {
					arr[d_] = arr[tmp] * 10 + 1;
					//m[d_] = m[tmp] + 'D';
					if (d_ == K) break;
					q.push(d_);
				}
				if (arr[s_] < 0) {
					arr[s_] = arr[tmp] * 10 + 2;
					//m[s_] = m[tmp] + 'S';
					if (s_ == K) break;
					q.push(s_);
				}
				if (arr[l_] < 0) {
					arr[l_] = arr[tmp] * 10 + 3;
					//m[l_] = m[tmp] + 'L';
					if (l_ == K) break;
					q.push(l_);
				}
				if (arr[r_] < 0) {
					arr[r_] = arr[tmp] * 10 + 4;
					//m[r_] = m[tmp] + 'R';
					if (r_ == K) break;
					q.push(r_);
				}	
			}
		}
		
		string ans = to_string(arr[K]);
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] == '1') printf("D");
			else if (ans[i] == '2') printf("S");
			else if (ans[i] == '3') printf("L");
			else printf("R");
		}
		cout << "\n";
	}
	return 0;
}
