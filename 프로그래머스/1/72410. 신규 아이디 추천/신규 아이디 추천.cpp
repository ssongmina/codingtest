#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    string answer = "";

    // 1,2단계
    for(char c : new_id){
        c = tolower((unsigned char)c);
        if( ('a' <= c && c <= 'z') ||
            ('0' <= c && c <= '9') ||
            c == '-' || c == '_' || c == '.'){
            answer += c;
        }
    }

    // 3단계
    string tmp = "";
    for(char c : answer){
        if(c == '.' && !tmp.empty() && tmp.back() == '.') continue;
        tmp += c;
    }
    answer = tmp;

    // 4단계
    if(!answer.empty() && answer.front() == '.') answer.erase(0,1);
    if(!answer.empty() && answer.back() == '.') answer.pop_back();

    // 5단계
    if(answer.empty()) answer = "a";

    // 6단계
    if(answer.size() >= 16){
        answer.erase(15);
        if(answer.back() == '.') answer.pop_back();
    }

    // 7단계
    while(answer.size() < 3){
        answer += answer.back();
    }

    return answer;
}
