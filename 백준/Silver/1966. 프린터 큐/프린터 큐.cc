#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        queue<pair<int,int>> q; // (index, priority)
        priority_queue<int> pq; // 중요도 내림차순 관리

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push({i, x});
            pq.push(x);
        }

        int cnt = 0;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            if (cur.second == pq.top()) { 
                // 출력됨
                cnt++;
                pq.pop();
                if (cur.first == m) { // 목표 문서 출력
                    cout << cnt << "\n";
                    break;
                }
            } else {
                // 뒤로 보냄
                q.push(cur);
            }
        }
    }
    return 0;
}
