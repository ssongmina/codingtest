#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> v[105];
int visited[105];

int dfs(int i, int j){
    int cnt = 1;
    visited[i] = 1;
    for(auto a : v[i]){
        if(visited[a] || a == j) continue;
        visited[a] = 1;
        cnt += dfs(a,j);
    }
    return cnt;
}

int check(int i, int j){ //i와 j를 끊어버린다
    memset(visited, 0, sizeof(visited));
    int a = dfs(i,j);
    int b = dfs(j,i);
    return abs(a-b);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(auto wire : wires){
        v[wire[0]].push_back(wire[1]);
        v[wire[1]].push_back(wire[0]);
    }
    
    for(auto wire : wires){
        answer = min(answer, check(wire[0], wire[1]));
    }
    return answer;
}