#include <string>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int visited[105][105];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int solution(vector<string> maps) {
    int answer = 0;
    int r = maps.size(), c = maps[0].size();
    int y = 0 , x = 0;
    int ey = 0, ex = 0;
    int ly = 0, lx = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(maps[i][j] == 'S') y = i, x = j;
            else if(maps[i][j] == 'E') ey = i, ex = j;
            else if(maps[i][j] == 'L') ly = i, lx = j;
        }
    }
    // s -> l
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = 1;
    int tolever = 0;
    while(q.size()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(visited[ny][nx] || maps[ny][nx] == 'X') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    if(visited[ly][lx]) tolever = visited[ly][lx];
    
    // l -> e
    memset(visited, 0, sizeof(visited));
    q.push({ly, lx});
    visited[ly][lx] = 1;
    int toend = 0;
    while(q.size()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(visited[ny][nx] || maps[ny][nx] == 'X') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    if(visited[ey][ex]) toend = visited[ey][ex];
    
    if(toend != 0 && tolever != 0) return toend + tolever - 2;
    else return -1;
    
    return answer;
}