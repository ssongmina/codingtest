#include <bits/stdc++.h>

using namespace std;

bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n%2 == 0) return 0;
    for(int i=3; i*i<=n; i++){
        if(n%i == 0) return 0;
    }
    return 1;
}

int solution(vector<int> nums) {
    int answer = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                int ret = nums[i] + nums[j] + nums[k];
                if(check(ret)) answer++;
            }
        }
    }

    return answer;
}