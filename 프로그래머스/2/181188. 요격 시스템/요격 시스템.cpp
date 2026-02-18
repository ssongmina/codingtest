#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second; 
    }
};

int solution(vector<vector<int>> targets) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    for(int i=0; i<targets.size(); i++){
        pq.push({targets[i][0], targets[i][1]});
    }
    int prefix = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        if(prefix > p.first) continue;
        prefix = p.second;
        answer++;
        cout << p.first << " - " << p.second << " - " << prefix << "\n"; 
    }
    return answer;
}