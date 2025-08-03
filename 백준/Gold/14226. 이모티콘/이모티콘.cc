#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int visited[1001][1001];

vector<int> v;
struct component {
    int window, board, cns;
};
int bfs(int a, int b, int c) {
    queue<component> q;
    q.push({a, b, c});
    
    while(!q.empty()) {
        int x = q.front().window;
        int y = q.front().board;
        int z = q.front().cns;
        
        q.pop();
        
        if(x == n) return z;
        
        if(0 < x && x < 1001) {
            if(visited[x][x] !=1) {
                q.push({x, x, z+1});
                visited[x][x] = 1;
            }
            
            if(x > 0 && x + y < 1001)
                if(visited[x + y][y] !=1) {
                    q.push({x + y, y, z+1});
                    visited[x + y][y] = 1;
                }
        
            if(visited[x - 1][y] !=1) {
                q.push({x - 1, y, z+1});
                visited[x - 1][y] = 1;
            
            }
        }
    }
 
}

int main()
{
    cin>>n;
    cout<<bfs(1, 0, 0);
    
    return 0;
}