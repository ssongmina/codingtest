#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int arr[105][105], visited[105][105];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= maps.size() || nx >= maps[0].size()) continue;
            if(maps[ny][nx] == 0 || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    answer = visited[maps.size()-1][maps[0].size()-1];
    if(answer == 0) answer = -1;
    return answer;
}