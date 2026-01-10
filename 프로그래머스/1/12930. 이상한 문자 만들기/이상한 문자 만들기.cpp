#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            idx = 0;
            answer += ' ';
            continue;
        } 
        if(idx&1){ // 홀수
            answer += tolower(s[i]);
        }
        else{
            answer += toupper(s[i]);
        }
        idx++;
    }
    return answer;
}