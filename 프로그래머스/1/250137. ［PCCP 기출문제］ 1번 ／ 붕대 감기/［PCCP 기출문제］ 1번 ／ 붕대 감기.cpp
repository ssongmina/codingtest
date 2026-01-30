#include <bits/stdc++.h>

using namespace std;

// 기술 시전 시간, 초당 회복량, 추가 회복량
int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0, mx = 0;
    int arr[1005];
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<attacks.size(); i++){
        arr[attacks[i][0]] = attacks[i][1];
        mx = max(mx, attacks[i][0]);
    }
    int cnt = 0, blood = health;
    for(int i=0; i<=mx; i++){
        if(arr[i]){ // 공격 받은 경우
            cnt = 0;
            blood -= arr[i];
            if(blood <= 0) return -1;
        }
        else if(arr[i] == 0){
            cnt++;
            blood = min(health, blood+bandage[1]);
        }
        
        if(cnt == bandage[0]){
            blood = min(health, blood+bandage[2]);
            cnt = 0;
        }
        cout << i << " -- " << blood << "\n";
    }
    return blood;
}