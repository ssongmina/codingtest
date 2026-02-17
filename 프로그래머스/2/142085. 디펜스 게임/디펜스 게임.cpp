#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // 오름 차순
    
    if(k >= enemy.size()){
        return enemy.size();
    }
    
    for(int i=0; i<enemy.size(); i++){
        int x = enemy[i];
        pq.push(x);
        if(pq.size() > k){
            int p = pq.top();
            pq.pop();
            n -= p;
        }
        if(pq.size() == k && n < 0) return i;
        if(pq.size() == k && n == 0) return i+1;
    }
    
    return enemy.size();
}