#include <bits/stdc++.h>

using namespace std;

int arr[1005][15];

int solution(int n, int w, int num) {
    int answer = 0;
    int cnt = (n + w - 1) / w;
    int y = 0, x = 0;
    
    memset(arr, 0, sizeof(arr));
    for(int i=1; i<=w; i++){
        arr[1][i] = i;
        if(arr[1][i] == num) y = 1, x = i;
    }
    
    for(int i=2; i<=cnt; i++){  // 행에 대해서
        for(int j=1; j<=w; j++){  // 열에 대해서
            if(i%2 == 0){ // 짝수행
                arr[i][j] = arr[i-1][j] + (w*2-2*j+1);
            }
            else{ // 홀수행
                arr[i][j] = arr[i-1][j] + (2*j-1);
            }
            if(arr[i][j] == num) y = i, x = j;
        }
    }
    
    for(int i=y; i<=cnt; i++){
        if(arr[i][x] != 0 && arr[i][x] <= n) answer++;
    }
    return answer;
}