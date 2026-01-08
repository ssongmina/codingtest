#include <bits/stdc++.h>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    for(int i=0; i<count; i++){
        answer += price*(i+1);
    }
    answer -= money;
    if(answer < 0) return 0;
    return answer;
}