#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    // 3진법 -> 뒤집기
    while(n!=0){
        v.push_back(n%3);
        n /= 3;
    }

    // 10진법으로
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        answer += pow(3,i) * v[i];
    }
    return answer;
}