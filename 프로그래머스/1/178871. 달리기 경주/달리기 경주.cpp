#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> order_s;
    map<int, string> order_i;
    for(int i=0; i<players.size(); i++){
        order_s[players[i]] = i+1;
        order_i[i+1] = players[i];
    }
    for(int i=0; i<callings.size(); i++){
        string str = callings[i];
        int n = order_s[str];
        string str1 = order_i[n-1];
        order_s[str] = n-1;
        order_s[str1] = n;
        order_i[n] = str1;
        order_i[n-1] = str;
    }
    for(int i=1; i<=players.size(); i++){
        answer.push_back(order_i[i]);
    }
    return answer;
}