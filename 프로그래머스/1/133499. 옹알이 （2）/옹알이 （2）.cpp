#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i=0; i<babbling.size(); i++){
        string s = babbling[i];
        int idx = 0; 
        bool flag = true;
        string p = "";
        while(idx < babbling[i].size() && flag){
            if(s.substr(idx,2) == "ye" || s.substr(idx,2) == "ma"){
                if(p == s.substr(idx,2)) flag = false;
                p = s.substr(idx,2);
                idx += 2;
            }
            else if(s.substr(idx,3) == "aya" || s.substr(idx,3) == "woo"){
                if(p == s.substr(idx,3)) flag = false;
                p = s.substr(idx,3);
                idx += 3;
            }
            else flag = false;
        }
        if(flag) answer++;
            
    }
    return answer;
}