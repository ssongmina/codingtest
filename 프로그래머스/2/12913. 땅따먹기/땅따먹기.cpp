#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int arr[100005][5];

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int row = land.size();  // 행 개수
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<4; i++) arr[0][i] = land[0][i];
    
    for(int i=1; i<row; i++){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                if(j == k) continue;
                arr[i][j] = max(arr[i][j], arr[i-1][k] + land[i][j]);
            }
        }
    }
    for(int i=0; i<4; i++){
        answer = max(answer, arr[row-1][i]);
    }
    return answer;
}