#include <bits/stdc++.h>

using namespace std;

int arr[15], brr[15];

string solution(string X, string Y) {
    string answer = "";
    for(int i=0; i<X.size(); i++){
        arr[X[i]-'0']++;
    }
    for(int i=0; i<Y.size(); i++){
        brr[Y[i]-'0']++;
    }
    for(int i=0; i<10; i++){
        int mn = min(arr[i], brr[i]);
        for(int j=0; j<mn; j++) answer += to_string(i);
    }
    sort(answer.begin(), answer.end(), greater<>());
    if(answer == "") answer = "-1";
    if(answer[0] == '0') answer = "0";
    return answer;
}