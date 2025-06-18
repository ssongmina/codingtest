#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, w[20][20];
int dp[1 << 16][16];

int go(int visited, int now) {
    if (visited == (1 << n) - 1) {
        if (w[now][0] == 0) return INF;
        return w[now][0];
    }

    int& ret = dp[visited][now];
    if (ret != -1) return ret;
    ret = INF;

    for (int next = 0; next < n; next++) {
        if (visited & (1 << next)) continue;
        if (w[now][next] == 0) continue;
        ret = min(ret, go(visited | (1 << next), next) + w[now][next]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    memset(dp, -1, sizeof(dp));
    cout << go(1, 0) << "\n"; // 0번 도시부터 시작
    return 0;
}
