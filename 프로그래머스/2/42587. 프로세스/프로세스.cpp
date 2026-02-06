#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q; // 값, idx
    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push({priorities[i], i});
    }
    while(true){
        int first = pq.top();
        int val = q.front().first;
        int idx = q.front().second;
        if(first == val){
            if(idx == location){
                return ++answer;
            }
            else{
                q.pop();
                pq.pop();
                answer++;
            }
        }
        
        if(val < first){
            q.pop();
            q.push({val, idx});
        }
    }
    return answer;
}