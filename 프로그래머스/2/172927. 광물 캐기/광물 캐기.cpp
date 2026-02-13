#include <string> 
#include <vector> 
#include <map> 
#include <numeric> 
#include <iostream> 
#include <algorithm> 

using namespace std;

int arr[3][3] = {{1,1,1}, {5,1,1}, {25,5,1}}; 
map<string, int> mp; 
vector<vector<int>> v; 
void init(){ mp["diamond"] = 0; mp["iron"] = 1; mp["stone"] = 2; }

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    init();
    
    int total = accumulate(picks.begin(), picks.end(), 0);
    vector<vector<int>> groups;
    
    for(int i = 0; i < minerals.size() && groups.size() < total; i += 5) {
        vector<int> cnt(3, 0);
        
        for(int j = i; j < i+5 && j < minerals.size(); j++) {
            cnt[mp[minerals[j]]]++;
        }
        
        groups.push_back(cnt);
    }
    
    sort(groups.begin(), groups.end(), [](vector<int>& a, vector<int>& b){
        int fatigueA = a[0]*25 + a[1]*5 + a[2];
        int fatigueB = b[0]*25 + b[1]*5 + b[2];
        return fatigueA > fatigueB;
    });
    
    for(auto& g : groups) {
        int pickType = -1;
        
        if(picks[0] > 0) pickType = 0;
        else if(picks[1] > 0) pickType = 1;
        else if(picks[2] > 0) pickType = 2;
        else break;
        
        picks[pickType]--;
        
        for(int i = 0; i < 3; i++)
            answer += arr[pickType][i] * g[i];
    }
    
    return answer;
}
