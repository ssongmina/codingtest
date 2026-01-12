#include <bits/stdc++.h>

using namespace std;

map<string, string> mp;
void make_mp(){
    mp["zero"] = "0";
    mp["one"] = "1";
    mp["two"] = "2";
    mp["three"] = "3";
    mp["four"] = "4";
    mp["five"] = "5";
    mp["six"] = "6";
    mp["seven"] = "7";
    mp["eight"] = "8";
    mp["nine"] = "9";
}

int solution(string s) {
    string answer = "";
    string cur = "";
    make_mp();
    for(int i=0; i<s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            answer += s[i];
        }
        else{
            cur += s[i];
            if(mp[cur] != ""){
                answer += mp[cur];
                cur = "";
            }
        }
    }
    return stoi(answer);
}