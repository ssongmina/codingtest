#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(string u){
    stack<char> stk;
    for(char c : u){
        if(c == '(') stk.push('(');
        else{
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

string go(string p){
    if(p == "") return "";
    
    string str = "";
    int i;
    int s = 0, e = 0;
    for(i=0; i<p.size(); i++){
        if(p[i] == '(') s++;
        else e++;
        if(s == e) break;
    }
    string u = p.substr(0, i+1);
    string v = p.substr(i+1);
    
    // u가 올바른 문자열인 경우
    if(check(u)){
        str += u;
        str += go(v);
    }
    // u가 올바른 문자열이 아닌 경우
    else{
        string s = "(";
        s += go(v);
        s += ")";
        // u의 앞 뒤 제거 후 괄호 방향 뒤집기
        u.erase(0,1); 
        u.erase(u.size()-1);
        for(char &c : u){
            c = (c == '(' ? ')' : '(');
        }
        s += u;
        str += s;
    }
    return str;
}

string solution(string p) {
    string answer = "";
    return go(p);
    
    return answer;
}