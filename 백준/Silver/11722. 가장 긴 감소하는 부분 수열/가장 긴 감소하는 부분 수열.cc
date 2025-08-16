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
        dp[i] = 1; // 자기 자신만 있는 수열의 길이는 1
    }

    int ret = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ret = max(ret, dp[i]);
    }

    cout << ret << "\n";
    return 0;
}
