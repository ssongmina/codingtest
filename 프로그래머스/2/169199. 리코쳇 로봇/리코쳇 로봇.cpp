#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int b[105][105];
int visited[105][105];
int row, col;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

pair<int,int> slide(int y, int x, int dir){
    int ny = y;
    int nx = x;
    
    while(true){
        int ty = ny + dy[dir];
        int tx = nx + dx[dir];
        
        if(ty < 0 || ty >= row || tx < 0 || tx >= col) break;
        if(b[ty][tx] == 1) break;
        
        ny = ty;
        nx = tx;
    }
    
    return {ny, nx};
}

int solution(vector<string> board) {
    memset(b, 0, sizeof(b));
    memset(visited, -1, sizeof(visited));
    
    row = board.size();
    col = board[0].size();
    
    int sy, sx, gy, gx;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j] == 'R'){
                sy = i; sx = j;
            }
            else if(board[i][j] == 'G'){
                gy = i; gx = j;
            }
            else if(board[i][j] == 'D'){
                b[i][j] = 1;
            }
        }
    }
    
    queue<pair<int,int>> q;
    q.push({sy,sx});
    visited[sy][sx] = 0;
    
    while(!q.empty()){
        auto [y,x] = q.front();
        q.pop();
        
        if(y == gy && x == gx){
            return visited[y][x];
        }
        
        for(int d=0; d<4; d++){
            auto [ny,nx] = slide(y,x,d);
            
            if(visited[ny][nx] != -1) continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    
    return -1; // 도달 불가
}
