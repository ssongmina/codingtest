#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[505];
int row, col;
int visited[505][505];
vector<vector<int>> v;
vector<int> p;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int dfs(int y, int x){
    int sum = 1;
    visited[y][x] = 1;
    p.push_back(x);
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= row || nx < 0 || nx >= col) continue;
        if(!v[ny][nx] || visited[ny][nx]) continue;
        sum += dfs(ny,nx);
    }
    return sum;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    v = land;
    memset(arr, 0, sizeof(arr));
    memset(visited, 0, sizeof(visited));
    row = land.size(), col = land[0].size();
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(land[i][j] && !visited[i][j]){
                p.clear(); 
                int cnt = dfs(i,j);
                sort(p.begin(), p.end());
                for(int k=p[0]; k<=p[p.size()-1]; k++){
                    arr[k] += cnt;
                }
            }
        }
    }
    for(int i=0; i<col; i++){
        answer = max(answer, arr[i]);
    }
    return answer;
}