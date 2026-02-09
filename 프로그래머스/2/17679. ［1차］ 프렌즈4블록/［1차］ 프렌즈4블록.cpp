#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

char arr[35][35];
set<pair<int,int>> s;

void check(int m, int n){
    // 2*2 확인
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            char c = arr[i][j];
            if(c == ' ') continue;
            if(c == arr[i+1][j] && c == arr[i][j+1] && c == arr[i+1][j+1]){
                s.insert({i+1,j}); s.insert({i,j+1}); 
                s.insert({i+1,j+1}); s.insert({i,j});
            }
        }
    }
    
    // set 배열 내 arr 모두 ' '으로 만들기
    for(auto a : s){
        arr[a.first][a.second] = ' ';
    }
    return ;
}

void down(int m, int n){ // 행 열
    // 빈칸 내리기 -> 열 별로 계산 추천
    vector<string> v;
    for(int i=0; i<n; i++){
        string s = "";
        for(int j=0; j<m; j++){
            if(arr[j][i] != ' ') s += arr[j][i];
        }
        if(s.size() != m){
            while(s.size() != m){
                s = " " + s;
            }
        }
        v.push_back(s);
    }
    memset(arr, ' ', sizeof(arr));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            arr[j][i] = v[i][j];
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = board[i][j];
        }
    }
    while(true){
        s.clear();
        // 1. 중복 확인
        check(m,n);
        answer += s.size();
        if(s.size() == 0) break;
        // 2. 내리기
        down(m,n);
    }
    return answer;
}