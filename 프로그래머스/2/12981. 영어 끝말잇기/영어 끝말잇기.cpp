#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> mp;
    mp[words[0]] = 1;
    for(int i=1; i<words.size(); i++){
        if(words[i-1][words[i-1].size()-1] != words[i][0]){
            answer.push_back(i%n + 1);
            answer.push_back(i/n + 1);
            break;
        }
        if(mp.find(words[i]) == mp.end()){ // 이전에 말한 단어인지 확인
            mp[words[i]] == 1;
        }
        else{
            answer.push_back(i%n + 1);
            answer.push_back(i/n + 1);
            break;
        }
    }
    if(answer.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}