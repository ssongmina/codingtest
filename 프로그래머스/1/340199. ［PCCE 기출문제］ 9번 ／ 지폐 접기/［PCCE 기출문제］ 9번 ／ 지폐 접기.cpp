#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(true){
        sort(wallet.begin(), wallet.end());
        sort(bill.begin(), bill.end());
        if(bill[0] <= wallet[0] && bill[1] <= wallet[1]) break;
        answer++;
        bill[1] = bill[1]/2;
    }
    return answer;
}