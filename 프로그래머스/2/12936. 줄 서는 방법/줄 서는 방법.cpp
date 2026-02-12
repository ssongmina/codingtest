#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long fac(int n){
    long long cnt = 1;
    for(int i=1; i<=n; i++){
        cnt *= i;
    }
    return cnt;
}

vector<int> solution(int n, long long k) {
    vector<int> answer; vector<int> v;
    for(int i=1; i<=n; i++) v.push_back(i);
    k--;
    while(v.size() > 1){
        long long f = fac(n-1);
        int idx = k/f;
        answer.push_back(v[idx]);
        v.erase(v.begin()+idx);
        n--;
        k %= f;
    }
    answer.push_back(v[0]);
    
    return answer;
}