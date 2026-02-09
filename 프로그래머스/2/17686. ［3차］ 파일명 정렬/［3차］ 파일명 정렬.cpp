#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> go(string x){
    vector<string> v;
    string head = "";
    int i=0;
    while(i < x.size()){
        if('0' <= x[i] && x[i] <= '9') break;
        else{
            head += x[i];
            i++;
        }
    }
    v.push_back(head);
    
    string number = "";
    int cnt = 0;
    while(i<x.size() && cnt < 5){
        if('0' <= x[i] && x[i] <= '9'){
            number += x[i];
            i++;
            cnt++;
        }
        else break;
    }
    v.push_back(number);
    v.push_back(x.substr(i));
    return v;
}

bool cmp(string a, string b){
    vector<string> v1 = go(a);
    vector<string> v2 = go(b);
    // HEAD 비교
    transform(v1[0].begin(), v1[0].end(), v1[0].begin(), ::tolower);
    transform(v2[0].begin(), v2[0].end(), v2[0].begin(), ::tolower);
    if(v1[0] != v2[0]) return v1[0] < v2[0];
    // NUMBER 비교
    int aa = stoi(v1[1]);
    int bb = stoi(v2[1]);
    if(aa != bb) return aa < bb;
    // TAIL 비교
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}