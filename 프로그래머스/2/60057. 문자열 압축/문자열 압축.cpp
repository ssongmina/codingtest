#include <string>
#include <vector>

using namespace std;

int cal(string s, int n){
    int ret = 0;
    string tmp = "";
    string prev = s.substr(0,n);
    int num = 1;
    for(int i=n; i<s.size(); i+=n){
        string str = s.substr(i,n);
        if(prev == str) num++;
        else if(prev != str){
            if(num > 1) tmp += to_string(num);
            tmp += prev;
            prev = str;
            num = 1;
        }
    }
    if(num > 1) tmp += to_string(num);
    tmp += prev;
    return tmp.size();
}

int solution(string s) {
    int answer = s.size();
    for(int i=1; i<=s.size()/2; i++){ // 문자열 압축 길이
        answer = min(answer, cal(s,i));
    }
    return answer;
}