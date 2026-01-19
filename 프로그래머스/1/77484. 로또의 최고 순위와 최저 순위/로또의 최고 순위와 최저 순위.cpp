#include <bits/stdc++.h>

using namespace std;

int getRank(int n){
    if(n == 6) return 1;
    else if(n == 5) return 2;
    else if(n == 4) return 3;
    else if(n == 3) return 4;
    else if(n == 2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero = 0, correct = 0;
    for(int i=0; i<6; i++){
        int a = lottos[i];
        auto it = find(win_nums.begin(), win_nums.end(), a);
        if(a == 0) zero++;
        else if(it != win_nums.end()){
            win_nums.erase(it);
            correct++;
        }
    }
    answer.push_back(getRank(correct+zero));
    answer.push_back(getRank(correct));
    return answer;
}