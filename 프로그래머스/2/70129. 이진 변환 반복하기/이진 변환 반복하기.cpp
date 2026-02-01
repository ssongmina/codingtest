#include <bits/stdc++.h>

using namespace std;

string trans(int n){
    string s = "";
    vector<int> v;
    while(n>1){
        v.push_back(n%2);
        n /= 2;
    }
    if(n == 1) v.push_back(1);
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        s += to_string(v[i]);
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0; // 제거한 0의 개수
    int num = 0; // 몇번의 이진변환
    while(true){
        num++;
        // 0 제거
        sort(s.begin(), s.end());
        int pos = s.find("1");
        cnt += pos;
        s.erase(0, pos);
        
        // x의 길이를 2진법으로 표현
        s = trans(s.size());
        
        if(s == "1") break;
    }

    answer.push_back(num); answer.push_back(cnt);
    return answer;
}