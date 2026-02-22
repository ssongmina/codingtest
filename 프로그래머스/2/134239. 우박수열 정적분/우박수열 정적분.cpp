#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> tmp; // 위치별 y값
vector<double> v;

void go(int k){
    tmp.push_back(k);
    while(k != 1){
        if(k&1){ // 홀수
            k = k*3 + 1;
        }    
        else{ // 짝수
            k /= 2;
        }
        tmp.push_back(k);
    }
    
    // 각 구간 별 크기 구하기
    for(int i=1; i<tmp.size(); i++){
        double total = ((double)tmp[i-1]+tmp[i])/2;
        v.push_back(total);
    }
    
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    // 우박 수열 구하기
    go(k);
    
    // 각 구간 별로 우박 수열의 정적분 구하기
    for(auto range : ranges){
        int a = range[0];
        int b = (tmp.size()-1) + range[1];
        cout << a << " " << b << "\n";
        double sum = 0;
        for(int i=a; i<b; i++){
            sum += v[i];
        }
        if(a > b) sum = -1;
        answer.push_back(sum);
    }
    
    return answer;
}