#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> mp;

void dfs(int idx, int num, string str, string alphabet){
    if(str.size() == num){
        if(mp[str]) mp[str]++;
        else mp[str] = 1;
        return ;
    }
    for(int i=idx; i<alphabet.size(); i++){
        dfs(i+1, num, str+alphabet[i], alphabet); // 현재 idx 추가
    }
}

vector<string> solution(vector<string> orders, vector<int> course){
    vector<string> answer;
    
    sort(orders.begin(), orders.end());
    
    // 각 order에 대해서 course별로 조합 생성해서 map에 넣어두기
    for(int i : course){
        for(string order : orders){
            sort(order.begin(), order.end());
            dfs(0, i, "", order);
        }
    }
  
    // course 길이 별로 max인 것만 answer에 push
    for(int i : course){
        int mx = 0;
        for(auto m : mp){
            if(m.first.size() == i){
                mx = max(mx, m.second);
            }
        }
        
        if(mx < 2) continue;
        for(auto m : mp){
            if(m.second == mx && m.first.size() == i) answer.push_back(m.first);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}