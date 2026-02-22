#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long cal(vector<int> diffs, vector<int> times, int level){
    long long sum = (long long)times[0];
    for(int i=1; i<diffs.size(); i++){
        if(diffs[i] <= level) sum += times[i];
        else{
            sum += ((long long)diffs[i]-level)*(times[i]+times[i-1]) + times[i];
        }
    }
    return sum;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());
    int level = right;
    while(left <= right){
        int mid = (left+right)/2;
        long long total = cal(diffs, times, mid);
        if(total <= limit){
            level = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return level;
}