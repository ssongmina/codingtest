#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1, a = 1, b = 0;
    char c = s[0];
    for(int i=1; i<s.size(); i++){
        if(a == b){
            answer++;
            c = s[i];
            a = 1, b = 0;
            continue;
        }
        if(s[i] == c) a++;
        else b++;
    }
    return answer;
}