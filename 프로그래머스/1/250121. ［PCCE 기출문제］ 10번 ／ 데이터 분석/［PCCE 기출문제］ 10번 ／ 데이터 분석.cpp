#include <bits/stdc++.h>

using namespace std;

string st;

int getIdx(string str){
    if(str == "code") return 0;
    else if(str == "date") return 1;
    else if(str == "maximum") return 2;
    else if(str == "remain") return 3;
}

bool cmp(vector<int> a, vector<int> b){
    int idx = getIdx(st);
    return a[idx] < b[idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    st = sort_by;
    for(int i=0; i<data.size(); i++){
        int idx = getIdx(ext);
        if(data[i][idx] < val_ext) answer.push_back(data[i]);
    }
    sort(answer.begin(), answer.end(), cmp);
    return answer;
}