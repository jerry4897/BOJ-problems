#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
stack <int> s1;
stack <int> s2;
int flag = 1; // 0 : 뒤집힘
int main() {
	int num;
	cin >> num;
	while (num--) {
		string str;
		cin >> str;
		if (str == "ENQUEUE") {
			int op;
			cin >> op;
			s1.push(op);
		}
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			cout << s2.top() << "\n";
			s2.pop();
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
	}
	return 0;
}
