#include <bits/stdc++.h>
using namespace std;

int n, k, ret;
int arr[105];
vector<int> plug;
vector<int> order[105];

bool check(int c) {
	for (auto a : plug) {
		if (a == c) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		order[arr[i]].push_back(i);
	}

	for (int i = 0; i < k; i++) {
		int now = arr[i];

		// 현재 사용 기록 삭제
		order[now].erase(order[now].begin());

		// 이미 꽂혀 있다면 continue
		if (check(now)) continue;

		// 아직 플러그에 자리가 있다면 꽂기
		if (plug.size() < n) {
			plug.push_back(now);
			continue;
		}

		// 뽑을 전기용품 찾기
		int mx = -1, idx = -1;
		for (int j = 0; j < plug.size(); j++) {
			int device = plug[j];

			if (order[device].empty()) { // 다시 안 쓰이면 바로 뽑기
				idx = j;
				break;
			}
			if (order[device][0] > mx) { // 가장 늦게 다시 쓰는 것 선택
				mx = order[device][0];
				idx = j;
			}
		}

		// 교체
		plug[idx] = now;
		ret++;
	}

	cout << ret << "\n";
	return 0;
}
