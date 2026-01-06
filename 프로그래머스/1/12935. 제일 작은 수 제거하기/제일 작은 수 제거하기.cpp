#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int a = *min_element(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == a) continue;
        answer.push_back(arr[i]);
    }
    if(answer.size() == 0) answer.push_back(-1);
    return answer;
}