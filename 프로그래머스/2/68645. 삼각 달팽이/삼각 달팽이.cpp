#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v(n+5, vector<int>(n+5));
    int state = 0;
    int y = 0, x = 1, cnt = 1;
    for(int i=n; i>0; i--){
        if(state == 0){ // 아래로
            for(int j=0; j<i; j++){
                v[++y][x] = cnt++;
            }
            state = 1;
        }
        else if(state == 1){ // 오른쪽으로
            for(int j=0; j<i; j++){
                v[y][++x] = cnt++;
            }
            state = 2;
        }
        else if(state == 2){ // 위로
            for(int j=0; j<i; j++){
                v[--y][--x] = cnt++;
            }
            state = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            answer.push_back(v[i][j]);
        }
    }
    
    return answer;
}