#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[2001];
bool dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 길이 1 → 팰린드롬
    for (int i = 1; i <= n; i++) dp[i][i] = true;

    // 길이 2
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]) dp[i][i + 1] = true;
    }

    // 길이 ≥ 3
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (a[i] == a[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }

    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }

    return 0;
}
