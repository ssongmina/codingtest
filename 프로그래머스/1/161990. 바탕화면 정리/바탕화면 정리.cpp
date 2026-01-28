#include <bits/stdc++.h>

using namespace std;

int arr[55][55];

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> y, x;
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[i].size(); j++){
            if(wallpaper[i][j] == '#'){
                y.push_back(i);
                x.push_back(j);
            }
        }
    }
    sort(y.begin(), y.end());
    sort(x.begin(), x.end());
    answer.push_back(y[0]); answer.push_back(x[0]);
    answer.push_back(y[y.size()-1]+1); answer.push_back(x[x.size()-1]+1);
    
    return answer;
}