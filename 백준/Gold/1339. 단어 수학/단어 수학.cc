#include <bits/stdc++.h>
using namespace std;

int n;
string str;
vector<string> v;
vector<char> letter; 
map<char, int> mp;
int visited[10];
int mx;

void check(){
    int sum = 0;
    for(string &s : v){
        int num = 0;
        for(char c : s){
            num = num * 10 + mp[c];
        }
        sum += num;
    }
    mx = max(mx, sum);
}

void go(int idx){
    if(idx == letter.size()){
        check();
        return;
    }

    for(int i=9; i>=0; i--){  // 큰 수 우선 배정하면 가지치기 가능
        if(visited[i]) continue;
        visited[i] = 1;
        mp[letter[idx]] = i;
        go(idx + 1);
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        v.push_back(str);
        for(char c : str){
            if(mp.find(c) == mp.end()) {  // 새로운 문자만 push
                mp[c] = -1;
                letter.push_back(c);
            }
        }
    }

    go(0);

    cout << mx << "\n";
}
