#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<char> v;

vector<string> split(string s){
    vector<string> tmp;
    set<char> st;
    string str = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == '-' || s[i] == '*' || s[i] == '+'){
            tmp.push_back(str);
            tmp.push_back(string(1,s[i]));
            str = "";
            st.insert(s[i]);
        }
        else str += s[i];
    }
    if(str.size()) tmp.push_back(str);
    v.assign(st.begin(), st.end());
    sort(v.begin(), v.end());
    return tmp;
}

long long cal(long long a, char b, long long c){
    if(b == '-') return a-c;
    if(b == '*') return a*c;
    if(b == '+') return a+c;
}

long long go(vector<string> ret){
    // v의 순서대로 값 계산 때리기
    for(auto op : v){
        for(int i=0; i<ret.size(); i++){
            if(ret[i] == string(1, op)){
                long long left = stoll(ret[i-1]);
                long long right = stoll(ret[i+1]);
                long long ans = cal(left, op, right);
                ret.erase(ret.begin()+i-1, ret.begin()+i+2);
                ret.insert(ret.begin()+i-1, to_string(ans));
                i -= 1;
            }
        }
    }
    return stoll(ret[0]);
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> ret = split(expression);
    do{
        answer = max(answer, abs(go(ret)));
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}