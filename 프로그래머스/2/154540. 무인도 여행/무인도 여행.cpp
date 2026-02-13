#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int visited[105][105];
vector<string> v;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int go(int y, int x){
    int ret = (v[y][x] - '0');
    visited[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= v.size() || nx < 0 || nx >= v[0].size()) continue;
        if(v[ny][nx] == 'X' || visited[ny][nx]) continue;
        ret += go(ny, nx);
    }
    return ret;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    v = maps;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            if(maps[i][j] != 'X' && !visited[i][j]){
                answer.push_back(go(i,j));
            }
        }
    }
    if(answer.size() == 0) return {-1};
    sort(answer.begin(), answer.end());
    return answer;
}