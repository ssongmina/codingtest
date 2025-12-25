#include <bits/stdc++.h>
using namespace std;

int n;
int a[25][25];
int sy, sx;        // 상어 위치
int sharkSize = 2;
int eatCnt = 0;
int answer = 0;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

struct Fish {
    int dist, y, x;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                sy = i;
                sx = j;
                a[i][j] = 0;
            }
        }
    }

    while (true) {
        vector<Fish> fishes;
        int dist[25][25];
        memset(dist, -1, sizeof(dist));

        queue<pair<int,int>> q;
        q.push({sy, sx});
        dist[sy][sx] = 0;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if (dist[ny][nx] != -1) continue;
                if (a[ny][nx] > sharkSize) continue;

                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});

                if (a[ny][nx] != 0 && a[ny][nx] < sharkSize) {
                    fishes.push_back({dist[ny][nx], ny, nx});
                }
            }
        }

        if (fishes.empty()) break;

        sort(fishes.begin(), fishes.end(), [](Fish a, Fish b) {
            if (a.dist != b.dist) return a.dist < b.dist;
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        });

        Fish target = fishes[0];

        answer += target.dist;
        sy = target.y;
        sx = target.x;
        a[sy][sx] = 0;

        eatCnt++;
        if (eatCnt == sharkSize) {
            sharkSize++;
            eatCnt = 0;
        }
    }

    cout << answer << "\n";
    return 0;
}
