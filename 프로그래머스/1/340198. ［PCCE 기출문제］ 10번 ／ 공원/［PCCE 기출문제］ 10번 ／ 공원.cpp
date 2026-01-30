#include <bits/stdc++.h>
using namespace std;

int arr[55][55];
int h, w;

bool go(int y, int x, int n){
    for(int i = y; i < y + n; i++){
        for(int j = x; j < x + n; j++){
            if(arr[i][j]) return false;
        }
    }
    return true;
}

bool check(int n){
    for(int i = 0; i <= h - n; i++){
        for(int j = 0; j <= w - n; j++){
            if(go(i, j, n)) return true;
        }
    }
    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    h = park.size();
    w = park[0].size();
    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            arr[i][j] = (park[i][j] != "-1");
        }
    }

    sort(mats.begin(), mats.end(), greater<>());

    for(int m : mats){
        if(check(m)) return m;
    }

    return -1;
}
