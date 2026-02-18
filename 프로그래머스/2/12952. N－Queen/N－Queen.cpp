#include <string>
#include <vector>

using namespace std;

int answer;
int chess[15];

bool check(int depth){
    for(int i=0; i<depth; i++){
        if(chess[depth] == chess[i]) return false;
        if(abs(chess[depth]-chess[i]) == depth-i) return false;
    }
    return true;
}

void dfs(int n, int depth){
    if(depth == n){
        answer++;
        return ;
    }
    for(int i=0; i<n; i++){
        chess[depth] = i;
        if(check(depth)) dfs(n, depth+1);
    }
}

int solution(int n) {
    answer = 0;
    dfs(n, 0);
    return answer;
}