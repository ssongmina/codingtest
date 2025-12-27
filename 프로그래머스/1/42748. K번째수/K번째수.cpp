#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> ret;
        int s = commands[i][0]-1;
        int e = commands[i][1];
        int k = commands[i][2]-1;
        for(int j=s; j<e; j++){
            ret.push_back(array[j]);
        }
        sort(ret.begin(), ret.end());
        answer.push_back(ret[k]);
    }
    return answer;
}