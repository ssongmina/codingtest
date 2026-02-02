#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    v.push_back(0); v.push_back(1); v.push_back(1);
    for(int i=3; i<=n; i++){
        int p = (v[i-1] + v[i-2])%1234567;
        v.push_back(p);
    }
    return v[n];
}