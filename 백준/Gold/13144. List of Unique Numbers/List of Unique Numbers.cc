#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005], visited[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ret = 0;
    int r = 0;
    for(int l = 0; l < n; l++) {
        while(r < n && !visited[arr[r]]) {
            visited[arr[r]] = 1;
            r++;
        }
        ret += (r - l);
        visited[arr[l]] = 0;  // 왼쪽 포인터가 한 칸 옮기니까 해당 값은 제거
    }

    cout << ret << "\n";
    return 0;
}
