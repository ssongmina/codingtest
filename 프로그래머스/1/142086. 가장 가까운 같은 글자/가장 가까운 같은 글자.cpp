#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int idx;
    for(int i=0; i<s.size(); i++){
        idx = -1;
        for(int j=0; j<i; j++){
            if(s[i] == s[j]){
                idx = i-j;
            }
        }
        answer.push_back(idx);
    }
    return answer;
}