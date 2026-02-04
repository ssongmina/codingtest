#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;
vector<string> w;
vector<int> n;

bool check(){
    for(int i=0; i<w.size(); i++){
        if(mp[w[i]] != n[i]) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    w = want; n = number;
    for(int i=0; i<want.size(); i++){
        mp[want[i]] = 0;
    }
    for(int i=0; i<10; i++){
        mp[discount[i]]++;
    }
    // 확인
    if(check()) answer++;
    for(int i=1; i<=discount.size()-10; i++){
        mp[discount[i-1]]--;
        mp[discount[9+i]]++;
        // 확인
        if(check()) answer++;
    }
    return answer;
}