#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(char c : number){
        while(!answer.empty() && k > 0 && answer.back() < c){
            k--;
            answer.pop_back();
        }
        answer.push_back(c);
    }
    while(k > 0){
        answer.pop_back();
        k--;
    }
    return answer;
}