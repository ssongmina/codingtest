#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ret, answer;
    for(int i=0; i<progresses.size(); i++){
        int n = 100 - progresses[i];
        int p = speeds[i];
        int cnt = n / p;
        if(n % p != 0) cnt++;
        ret.push_back(cnt);
    }
    stack<int> stk;
    int cnt = 1;
    stk.push(ret[0]);
    int front = ret[0];
    for(int i=1; i<ret.size(); i++){
        if(ret[i] <= front) cnt++;
        else{
            answer.push_back(cnt);
            cnt = 1;
            front = ret[i];
        }
    }
    answer.push_back(cnt);
    
    
    
    return answer;
}