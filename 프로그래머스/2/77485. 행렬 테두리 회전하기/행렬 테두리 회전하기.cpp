#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int arr[rows+5][columns+5];
    int cnt = 1;
    memset(arr, 0, sizeof(arr));
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            arr[i][j] = cnt++;
        }
    }
    for(vector<int> query : queries){
        int y1 = query[0], x1 = query[1];
        int y2 = query[2], x2 = query[3];
        vector<pair<int,int>> idx;
        vector<int> val;
        // 오른쪽으로
        for(int i=x1; i<=x2; i++){
            idx.push_back({y1,i});
            val.push_back(arr[y1][i]);
        }
        // 아래로
        for(int i=y1+1; i<=y2; i++){
            idx.push_back({i,x2});
            val.push_back(arr[i][x2]);
        }
        // 왼쪽으로
        for(int i=x2-1; i>=x1; i--){
            idx.push_back({y2,i});
            val.push_back(arr[y2][i]);
        }
        // 위로
        for(int i=y2-1; i>=y1+1; i--){
            idx.push_back({i,x1});
            val.push_back(arr[i][x1]);
        }
        rotate(val.rbegin(), val.rbegin()+1, val.rend());
    
        // 다시 값 넣기
        int mn = 987654321;
        for(int i=0; i<idx.size(); i++){
            int y = idx[i].first;
            int x = idx[i].second;
            arr[y][x] = val[i];
            mn = min(mn, arr[y][x]);
        }
        answer.push_back(mn);
    }
    
    return answer;
}