#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(int num : numbers) str.push_back(to_string(num));
    sort(str.begin(), str.end(), cmp);
    if(str[0] == "0") return "0";
    for(string number : str) answer+=number;
    return answer;
}