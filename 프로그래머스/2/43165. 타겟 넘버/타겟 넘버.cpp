#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(q.size()){
        int idx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(idx == numbers.size()){
            if(cnt == target) answer++;
            continue;
        }
        q.push({idx+1, cnt-numbers[idx]});
        q.push({idx+1, cnt+numbers[idx]});
    }
    return answer;
}