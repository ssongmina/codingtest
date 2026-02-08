#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }
    while(pq.top() < k){
        if(pq.size() < 2){
            answer = -1;
            break;
        }
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a + 2*b);
        answer++;
    }
    return answer;
}