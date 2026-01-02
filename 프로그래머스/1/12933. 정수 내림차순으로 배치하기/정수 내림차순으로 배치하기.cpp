#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);
    vector<char> v;
    for(int i=0; i<str.size(); i++){
        v.push_back(str[i]);
    }
    sort(v.begin(), v.end(), greater<>());
    str = "";
    for(int i=0; i<v.size(); i++) str += v[i];
    answer = stoll(str);
    return answer;
}