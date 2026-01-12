#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, string> a, pair<char, string> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> v;
    for(int i=0; i<strings.size(); i++){
        v.push_back({strings[i][n], strings[i]});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].second);
    }
    return answer;
}