#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 1;
    int i=1,j=2;
    int cnt = 1;
    while(i < j && j <= n){
        if(cnt < n){
            cnt += j;
            j++;
        }
        else if(cnt > n){
            cnt -= i;
            i++;
        }
        else{
            answer++;
            cnt -= i;
            cnt += j;
            i++;
            j++;
        }
    }
    return answer;
}