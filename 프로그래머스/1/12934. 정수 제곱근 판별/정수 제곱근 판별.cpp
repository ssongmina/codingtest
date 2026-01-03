#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    long long x = sqrt(n);
    if(x*x == n){
        answer = (x+1)*(x+1);
    }
    return answer;
}