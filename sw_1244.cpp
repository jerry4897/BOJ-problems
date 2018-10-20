#include <iostream>
#include <math.h>
using namespace std;
int num, len, ans = 0;
void change(int str, int pos1, int pos2, int cnt) {
	int div1 = pow(10, len - pos1 - 1);
	int div2 = pow(10, len - pos2 - 1);
	int num1 = (str % (div1 * 10)) / div1;
	int num2 = (str % (div2 * 10)) / div2;
	str -= num1*div1;
	str -= num2*div2;
	str += num1*div2;
	str += num2*div1;
	if (cnt == num) {
		if(ans < str) ans = str;
		return;
	}
	else {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (i != j)
					change(str, i, j, cnt + 1);
			}
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int str;
		cin >> str >> num;
		ans = 0;
		int div = pow(10, 5);
		//if (str / div == 9) cout << "?";
		len = 6;
		for (int i = 0; i < 6; i++) {
			if (str / div) break;
			else {
				len--;
				div /= 10;
			}
		}

		if (num) {
			while (len > 4 && num >= len) {
				num -= 2;
			}
			for (int i = 0; i < len; i++) {
				for (int j = 0; j < len; j++) {
					if (i != j)
						change(str, i, j, 1);
				}
			}
		}
		else ans = str;
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
