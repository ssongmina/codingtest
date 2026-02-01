#include <bits/stdc++.h>

using namespace std;

vector<int> split(string s, string delimeter){
    vector<int> v;
    long long pos;
    string token = "";
    while((pos = s.find(delimeter)) != string::npos){
        token = s.substr(0, pos);
        v.push_back(stoi(token));
        s.erase(0, pos+delimeter.size());
    }
    v.push_back(stoi(s));
    return v;
}

string solution(string s) {
    string answer = "";
    vector<int> v = split(s, " ");
    sort(v.begin(), v.end());
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size()-1]);
    return answer;
}