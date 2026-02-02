#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // 귤의 종류에 대한 개수 구하기
    map<int, int> mp;
    for(int i=0; i<tangerine.size(); i++){
        mp[tangerine[i]]++;
    }
    // 귤 개수 내림차순으로 정렬
    priority_queue<int> pq;
    for(auto a : mp){
        pq.push(a.second);
    }
    
    while(pq.size()){
        int a = pq.top();
        pq.pop();
        answer++;
        k -= a;
        if(k <= 0) break;
    }
    
    
    return answer;
}