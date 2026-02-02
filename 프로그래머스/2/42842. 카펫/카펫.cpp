#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tot = (brown-4)/2; // 노란색의 가+세
    int x, y;
    for(int i=1; i<=tot/2; i++){
        if(i*(tot-i) == yellow){
            x = i; y = tot-i;
            break;
        }
    }
    answer.push_back(y+2);
    answer.push_back(x+2);
    return answer;
}