#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string s;
int a[1001][1001]; 
int dist[1001][1001][11];  // y, x, 부순 벽 개수

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<m; j++){
            a[i][j] = s[j] - '0';
            for(int kk=0; kk<=k; kk++){
                dist[i][j][kk] = -1;
            }
        }
    }

    queue<tuple<int,int,int>> q;
    q.push({0, 0, 0});      // y, x, 부순 벽 개수
    dist[0][0][0] = 1;

    while(!q.empty()){
        auto [y, x, w] = q.front();
        q.pop();

        if(y == n-1 && x == m-1){
            cout << dist[y][x][w] << "\n";
            return 0;
        }

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            // 벽이 아닌 경우(0)
            if(a[ny][nx] == 0){
                if(dist[ny][nx][w] == -1){
                    dist[ny][nx][w] = dist[y][x][w] + 1;
                    q.push({ny, nx, w});
                }
            }

            // 벽인 경우(1)
            else {
                if(w < k && dist[ny][nx][w+1] == -1){
                    dist[ny][nx][w+1] = dist[y][x][w] + 1;
                    q.push({ny, nx, w+1});
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
