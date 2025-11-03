#include <iostream>
#include <string>
using namespace std;

string num[5] = {
" -       -   -       -   -   -   -   -  ",
"| |   |   |   | | | |   |     | | | | | ",
"         -   -   -   -   -       -   -  ",
"| |   | |     |   |   | | |   | | |   | ",
" -       -   -       -   -       -   -  "};

string ans[23];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int len; string s; cin >> len >> s;
	for (auto& l : s) {
		int cur = l - '0';
		
		ans[0] += ' ';
		for (int i = 0; i < len; i++) ans[0] += num[0][cur * 4 + 1];
		ans[0] += ' ';
		ans[0] += ' ';
		
		for (int k = 1; k <= len; k++) {
			ans[k] += num[1][cur * 4];
			for (int i = 0; i < len; i++) ans[k] += num[1][cur * 4 + 1];
			ans[k] += num[1][cur * 4 + 2];
			ans[k] += ' ';
		}

		ans[len + 1] += ' ';
		for (int i = 0; i < len; i++) ans[len + 1] += num[2][cur * 4 + 1];
		ans[len + 1] += ' ';
		ans[len + 1] += ' ';

		for (int k = len + 2; k <= len * 2 + 1; k++) {
			ans[k] += num[3][cur * 4];
			for (int i = 0; i < len; i++) ans[k] += num[3][cur * 4 + 1];
			ans[k] += num[3][cur * 4 + 2];
			ans[k] += ' ';
		}

		ans[len * 2 + 2] += ' ';
		for (int i = 0; i < len; i++) ans[len * 2 + 2] += num[4][cur * 4 + 1];
		ans[len * 2 + 2] += ' ';
		ans[len * 2 + 2] += ' ';
	}

	for (int i = 0; i <= len * 2 + 2; i++) {
		cout << ans[i] << '\n';
	}
}