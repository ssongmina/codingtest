#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool check(string s){
    for(int i=0; i<s.size(); i++){
        if(!('a' <= s[i] && s[i] <= 'z')) return false;
    }
    return true;
}

vector<string> go(string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    vector<string> v;
    for(int i=0; i<str.size()-1; i++){
        string s = str.substr(i, 2);
        if(check(s)) v.push_back(s);
    }
    return v;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> v1, v2, s;
    v1 = go(str1);
    v2 = go(str2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(s));
    int ko = s.size();
    int hap = v1.size() + v2.size() - ko;
    float f = ((float)ko/hap) * 65536;
    if(hap == 0) f = 65536;
    return (int)f;
}