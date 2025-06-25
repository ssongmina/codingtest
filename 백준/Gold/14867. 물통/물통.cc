#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int visited[1001][1001]; // [a][b] 최대 용량은 1000 이하

struct State {
    int x, y, cnt;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c >> d;

    queue<State> q;
    q.push({0, 0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto [x, y, cnt] = q.front(); q.pop();
        
        if (x == c && y == d) {
            cout << cnt << '\n';
            return 0;
        }

        vector<pair<int, int>> nextStates = {
            {a, y},     // x 채우기
            {x, b},     // y 채우기
            {0, y},     // x 비우기
            {x, 0},     // y 비우기
            {min(x + y, a), max(0, x + y - a)}, // y -> x
            {max(0, x + y - b), min(x + y, b)}  // x -> y
        };

        for (auto [nx, ny] : nextStates) {
            if (!visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push({nx, ny, cnt + 1});
            }
        }
    }

    cout << "-1\n"; // 불가능한 경우
    return 0;
}
