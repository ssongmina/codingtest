#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c == '('){
            stk.push(c);
        }else{
            if(stk.size()) stk.pop();
            else answer = false;
        }
    }
    if(stk.size()) answer = false;

    return answer;
}