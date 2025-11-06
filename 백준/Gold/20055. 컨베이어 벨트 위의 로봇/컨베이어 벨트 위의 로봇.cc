#include <bits/stdc++.h>
using namespace std;

int n, k, stepCnt = 0;
int a[205]; // 내구도
deque<int> belt; // 벨트의 내구도 인덱스
deque<int> robot; // 로봇 위치 표시 (0 or 1)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        belt.push_back(a[i]);
        robot.push_back(0);
    }

    while (true) {
        stepCnt++;

        // 1. 벨트와 로봇 회전
        belt.push_front(belt.back());
        belt.pop_back();
        robot.push_front(robot.back());
        robot.pop_back();
        robot[n - 1] = 0; // 내리는 위치 로봇 내림

        // 2. 로봇 이동
        for (int i = n - 2; i >= 0; i--) {
            if (robot[i] && !robot[i + 1] && belt[i + 1] > 0) {
                robot[i] = 0;
                robot[i + 1] = 1;
                belt[i + 1]--;
            }
        }
        robot[n - 1] = 0;

        // 3. 올리는 위치에 로봇 올리기
        if (!robot[0] && belt[0] > 0) {
            robot[0] = 1;
            belt[0]--;
        }

        // 4. 내구도 0인 칸 개수 세기
        int zero = count(belt.begin(), belt.end(), 0);
        if (zero >= k) break;
    }

    cout << stepCnt << "\n";
}
