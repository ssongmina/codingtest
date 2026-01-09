#include <bits/stdc++.h>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for(long long i=0; i<t.size()-p.size()+1; i++){
        if(t.substr(i, p.size()) <= p){
            answer++;
        } 
    }
    return answer;
}