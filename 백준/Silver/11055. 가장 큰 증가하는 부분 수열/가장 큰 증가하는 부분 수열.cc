#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005], dp[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = arr[i]; // 자기 자신만 포함한 합으로 초기화
    }

    int ret = dp[0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        ret = max(ret, dp[i]);
    }

    cout << ret << "\n";
    return 0;
}
