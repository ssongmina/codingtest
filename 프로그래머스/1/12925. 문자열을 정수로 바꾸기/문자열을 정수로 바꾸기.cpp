#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    string str = s;
    if(s[0] == '-') str = s.substr(1);
    answer = stoi(str);
    if(str.size() != s.size()) answer = -answer;
    return answer;
}