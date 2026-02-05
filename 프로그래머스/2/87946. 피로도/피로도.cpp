#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vv;
vector<vector<int>> dun;

int check(int idx, int k){
    vector<int> v = vv[idx];
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        int a = dun[v[i]][0];
        int b = dun[v[i]][1];
        if(k < a) return cnt;
        k -= b;
        cnt++;
    }
    return cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> v;
    dun = dungeons;
    // 순열 구하기
    for(int i=0; i<dungeons.size(); i++){
        v.push_back(i);
    }
    do{
        vv.push_back(v);
    }while(next_permutation(v.begin(), v.end()));
    
    for(int i=0; i<vv.size(); i++){
        answer = max(answer, check(i, k));
    }
    
    return answer;
}