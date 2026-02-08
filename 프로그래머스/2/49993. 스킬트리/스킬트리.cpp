#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_set<char> l;
    for(int i=0; i<skill.size(); i++) l.insert(skill[i]);
    
    for(string target : skill_trees){ // "BACDE"
        int idx = 0;
        bool flag = true;
        for(char c : target){
            if(!l.count(c)) continue;
            if(c == skill[idx]){
                idx++;
            }else{
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}