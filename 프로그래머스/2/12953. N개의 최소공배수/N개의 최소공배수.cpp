#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { // 최대공약수
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcd(int a, int b){  // 최소 공배수
    return (a*b) / gcd(a,b);
}

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int mn = lcd(arr[arr.size()-2], arr[arr.size()-1]);
    int answer = mn;
    while(true){
        bool flag = true;
        for(int i=0; i<arr.size(); i++){
            if(answer % arr[i] != 0) flag = false;
        }
        if(flag) return answer;
        else{
            answer += mn;
        }
    }
    return answer;
}