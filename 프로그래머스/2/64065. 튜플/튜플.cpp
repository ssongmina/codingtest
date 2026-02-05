#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split(string s, string delimeter){
    s.erase(0,1); s.erase(s.size()-1,1); 
    vector<string> v;
    long long pos;
    string token = "";
    while((pos = s.find(delimeter)) != string::npos){
        token = s.substr(0, pos+1);
        v.push_back(token);
        s.erase(0, pos + delimeter.size() + 1);
    }
    return v;
}

bool cmp(string a, string b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int,int> mp;
    vector<string> ss = split(s, "}");
    sort(ss.begin(), ss.end(), cmp);
    for(int i=0; i<ss.size(); i++){
        string str = ss[i];
        str.erase(0,1); str.erase(str.size()-1,1);
        string ret = "";
        for(int i=0; i<str.size(); i++){
            if(str[i] != ',') ret += str[i];
            else{
                int a = stoi(ret);
                if(mp[a] == 0){
                    mp[a] = 1;
                    answer.push_back(a);
                }
                ret = "";
            }
        }
        if(ret.size()){
            int a = stoi(ret);
                if(mp[a] == 0){
                    mp[a] = 1;
                    answer.push_back(a);
                }
        }
    }
    return answer;
}