#include <bits/stdc++.h>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() != 4 && s.size() != 6) return false;
    for(int i=0; i<s.size(); i++){
        if('0' > s[i] || s[i] > '9') return false;
    }
    return answer;
}