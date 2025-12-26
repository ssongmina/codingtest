#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> mp;
    for(int i=0; i<nums.size(); i++){
        if(mp.find(nums[i]) != mp.end()){
            mp[nums[i]]++;
        }else{
            mp[nums[i]] = 1;
        }
    }
    int mx = nums.size()/2;
    if(mx <= mp.size()) return mx;
    else return mp.size();
}