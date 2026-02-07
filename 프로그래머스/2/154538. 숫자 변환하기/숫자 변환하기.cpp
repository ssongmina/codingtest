#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int visited[1000005];

int solution(int x, int y, int n) {
    int answer = 0;
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(q.size()){
        int x = q.front();
        q.pop();
        if(x == y) break;
        for(int nx : {x+n, x*2, x*3}){
            if(nx > 1000000) continue;
            if(visited[nx]) continue;
            q.push(nx);
            visited[nx] = visited[x] + 1;
        }
    }
    answer = (visited[y]) ? visited[y]-1 : -1;
    return answer;
}