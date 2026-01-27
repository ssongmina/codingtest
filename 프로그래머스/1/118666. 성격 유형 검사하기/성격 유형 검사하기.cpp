#include <bits/stdc++.h>

using namespace std;

int score[8] = {0,3,2,1,0,1,2,3}; // choices에 따른 점수
map<char, int> mp;

void init(){
    mp['R'] = 0; mp['T'] = 0;
    mp['C'] = 0; mp['F'] = 0;
    mp['J'] = 0; mp['M'] = 0;
    mp['A'] = 0; mp['N'] = 0;
} 

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    init();
    for(int i=0; i<survey.size(); i++){
        int c = choices[i];
        string str = survey[i];
        int s = score[c];
        if(c < 4) mp[str[0]] += s;
        else if(c > 4) mp[str[1]] += s;
    }
    if(mp['R'] >= mp['T']) answer += 'R';
    else answer += 'T';
    
    if(mp['C'] >= mp['F']) answer += 'C';
    else answer += 'F';
    
    if(mp['J'] >= mp['M']) answer += 'J';
    else answer += 'M';
    
    if(mp['A'] >= mp['N']) answer += 'A';
    else answer += 'N';
    
    return answer;
}