#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0, idx = 0;
    sort(score.begin(), score.end(), greater<>());
    while(true){
        if(score.size()-idx < m) break;
        int mn = k;
        for(int i=idx; i<idx+m; i++){
            mn = min(score[i], mn);
        }
        answer += mn * m;
        idx += m;
    }
    return answer;
}