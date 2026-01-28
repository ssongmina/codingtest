#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

int toDays(int y, int m, int d){
    return y * 12 * 28 + m * 28 + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    // 약관 파싱
    for(string t : terms){
        mp[t[0]] = stoi(t.substr(2));
    }

    int ty = stoi(today.substr(0,4));
    int tm = stoi(today.substr(5,2));
    int td = stoi(today.substr(8,2));
    int todayDays = toDays(ty, tm, td);

    for(int i=0; i<privacies.size(); i++){
        string s = privacies[i];
        int y = stoi(s.substr(0,4));
        int m = stoi(s.substr(5,2));
        int d = stoi(s.substr(8,2));
        char type = s[11];

        int expireDays = toDays(y, m + mp[type], d) - 1;

        if(expireDays < todayDays){
            answer.push_back(i+1);
        }
    }

    return answer;
}
