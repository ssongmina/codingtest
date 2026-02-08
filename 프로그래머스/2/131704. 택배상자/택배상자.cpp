#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> stk;
    int idx = 1;
    for(int target : order){
        while(idx <= order.size() && (stk.empty() || stk.top() != target)){
            stk.push(idx++);
        }
        if(!stk.empty() && stk.top() == target){
            stk.pop();
            answer++;
        }
        else{
            break;
        }
    }
    return answer;
}