#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer, ret;
    for(int i=0; i<score.size(); i++){
        ret.push_back(score[i]);
        sort(ret.begin(), ret.end(), greater<>());
        if(i < k) answer.push_back(ret[i]);
        else answer.push_back(ret[k-1]);
    }
    return answer;
}