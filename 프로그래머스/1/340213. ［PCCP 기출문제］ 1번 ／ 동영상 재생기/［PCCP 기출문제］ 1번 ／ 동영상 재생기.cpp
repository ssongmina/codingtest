#include <bits/stdc++.h>

using namespace std;

int go(string str){
    int h = stoi(str.substr(0,2));
    int m = stoi(str.substr(3,2));
    return h*60 + m;
}

string gogo(int cur){
    int h = cur / 60;
    int m = cur % 60;
    string str = "";
    if(h < 10) str += "0";
    str += to_string(h);
    str += ":";
    if(m < 10) str += "0";
    str += to_string(m);
    return str;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int total = go(video_len);   int cur = go(pos);
    int start = go(op_start);    int end = go(op_end);
    for(int i=0; i<commands.size(); i++){
        string str = commands[i];
        if(start <= cur && cur <= end) cur = end;
        if(str == "prev"){
            cur = max(0, cur-10);
        }
        else if(str == "next"){
            cur = min(total, cur+10);
        }
        cout << cur << "\n";
    }
    if(start <= cur && cur <= end) cur = end;
    answer = gogo(cur);
    return answer;
}