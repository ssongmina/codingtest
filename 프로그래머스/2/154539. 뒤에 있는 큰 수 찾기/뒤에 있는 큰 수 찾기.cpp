#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<int> stk; // idx값 넣을 예정
    int idx = numbers.size()-1;
    stk.push(idx--);
    for(int i=idx; i>=0; i--){
        while(!stk.empty() && numbers[stk.top()] <= numbers[i]){
            stk.pop();
        }
        if(!stk.empty()){
            answer[i] = numbers[stk.top()];
        }
        stk.push(i);
    }
    
    return answer;
}