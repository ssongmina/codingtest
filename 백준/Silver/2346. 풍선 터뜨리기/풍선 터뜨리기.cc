#include <iostream>
#include <deque>
using namespace std;

deque<pair<int,int>> D;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int value;
		cin >> value;
		D.push_back({ value,i });
	}

	while (true) {
		cout << D.front().second << " ";
		int step = abs(D.front().first);
		bool is_minus = false;
		if (D.front().first < 0) is_minus = true;
		D.pop_front();

		if (D.empty()) break;

		if (is_minus) {
			//왼쪽으로 해당 수 만큼 이동.
			for (int i = 0; i < step; i++) {
				D.push_front(D.back());
				D.pop_back();
			}
		}
		else {
			for (int i = 0; i < step-1; i++) {
				D.push_back(D.front());
				D.pop_front();
			}
		}
	}

	return 0;
}