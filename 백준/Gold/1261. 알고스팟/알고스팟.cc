#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[105][105];
int dist[105][105]; // 최소 벽 부순 횟수
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            arr[i][j] = str[j] - '0';
            dist[i][j] = 1e9; // 초기화
        }
    }

    deque<pair<int,int>> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;

    while(!dq.empty()) {
        auto [y, x] = dq.front(); dq.pop_front();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            int cost = arr[ny][nx];
            if(dist[ny][nx] > dist[y][x] + cost) {
                dist[ny][nx] = dist[y][x] + cost;
                if(cost == 0) dq.push_front({ny, nx});
                else dq.push_back({ny, nx});
            }
        }
    }

    cout << dist[n-1][m-1] << "\n";
    return 0;
}
