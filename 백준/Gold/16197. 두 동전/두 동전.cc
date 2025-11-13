#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[25][25];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<pair<int,int>> coin;
int ret = -1;

void go(int cnt){
    if(cnt >= 10) return;

    for(int i = 0; i < 4; i++){
        int ny1 = coin[0].first + dy[i];
        int nx1 = coin[0].second + dx[i];
        int ny2 = coin[1].first + dy[i];
        int nx2 = coin[1].second + dx[i];
        
        int fall = 0;

        // 벽 처리
        if(ny1 < 0 || ny1 >= n || nx1 < 0 || nx1 >= m) fall++;
        else if(a[ny1][nx1] == '#') ny1 = coin[0].first, nx1 = coin[0].second;
        if(ny2 < 0 || ny2 >= n || nx2 < 0 || nx2 >= m) fall++;
        else if(a[ny2][nx2] == '#') ny2 = coin[1].first, nx2 = coin[1].second;

        if(fall == 2) continue;
        if(fall == 1){
            if(ret == -1 || ret > cnt + 1)
                ret = cnt + 1;
            continue;
        }
        if(ny1 == ny2 && nx1 == nx2) continue;

        vector<pair<int,int>> tmp = coin;
        coin[0] = {ny1, nx1};
        coin[1] = {ny2, nx2};
        go(cnt + 1);
        coin = tmp;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'o'){
                coin.push_back({i, j});
                a[i][j] = '.';
            }
        }
    }

    go(0);
    cout << ret << "\n";
}
