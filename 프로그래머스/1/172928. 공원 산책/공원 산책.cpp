#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
map<char, int> mp;

void init(){
    mp['N'] = 0; mp['E'] = 1;
    mp['S'] = 2; mp['W'] = 3;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    init();

    int y = 0, x = 0;
    int n = park.size(), m = park[0].size();

    // 시작 위치 찾기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(park[i][j] == 'S') {
                y = i; x = j;
            }
        }
    }

    // 경로 처리
    for(string str : routes){
        char dir = str[0];
        int num = str[2] - '0';

        int ny = y, nx = x;
        bool ok = true;

        for(int step = 0; step < num; step++){
            ny += dy[mp[dir]];
            nx += dx[mp[dir]];

            // 범위 초과
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                ok = false;
                break;
            }

            // 장애물
            if(park[ny][nx] == 'X') {
                ok = false;
                break;
            }
        }

        if(ok) {
            y = ny;
            x = nx;
        }
    }

    return {y, x};
}
