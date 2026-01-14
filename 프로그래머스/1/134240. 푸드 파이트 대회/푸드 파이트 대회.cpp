#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for(int i=0; i<food.size(); i++){
        int n = food[i];
        for(int j=0; j<n/2; j++) answer += to_string(i);
    }
    string ans = answer;
    reverse(ans.begin(), ans.end());
    answer += "0" + ans;
    return answer;
}