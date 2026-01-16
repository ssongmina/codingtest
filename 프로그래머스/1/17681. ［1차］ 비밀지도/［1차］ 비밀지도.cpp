#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<n; i++){
        string str = "";
        for(int j=0; j<n; j++){
            if(arr1[i] & (1<<j) || arr2[i] & (1<<j)) str += "#";
            else str += " ";
        }
        reverse(str.begin(), str.end());
        answer.push_back(str);
    }
    return answer;
}