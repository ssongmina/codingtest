#include <string>
#include <vector>
#include <iostream>

using namespace std;

string change(string s){
    string tmp = "";
    for(int i=0; i<s.size(); i++){
        //if(s[i] == '#') continue;
        //if(s[i] == 'E' || s[i] == 'B') tmp += s[i];
        //else{
            if(i+1 < s.size() && s[i+1] == '#'){
                //string temp = s.substr(i,2);
                tmp += tolower(s[i]);
                //tmp += mp[temp];
                i++;
            }
            else tmp += s[i];
        //}
    }
    return tmp;
}

vector<string> split(string str, string delimeter){
    long long pos;
    vector<string> tmp;
    vector<string> real;
    string token = "";
    while((pos = str.find(delimeter)) != string::npos){
        token = str.substr(0, pos);
        tmp.push_back(token);
        str.erase(0, pos+delimeter.size());
    }
    tmp.push_back(str);
    
    int a = stoi(tmp[0].substr(0,2))*60 + stoi(tmp[0].substr(3,2));
    int b = stoi(tmp[1].substr(0,2))*60 + stoi(tmp[1].substr(3,2));
    int total = b-a;
    string ackbo = change(tmp[3]);
    string song = "";
    for(int i = 0; i < total; i++){
        song += ackbo[i % ackbo.size()];
    }
    real.push_back(tmp[2]);  // 음악 제목
    real.push_back(song); // 음악 악보
    real.push_back(to_string(total));
    //cout << real[0] << " " << real[1] << "\n";
    return real;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int mx = 0;
    m = change(m);
    for(string music : musicinfos){
        vector<string> s = split(music, ",");
        if(s[1].find(m) != string::npos){
            if(mx < stoi(s[2])){
                answer = s[0];
                mx = stoi(s[2]);
            }
        }
    }
    if(answer.empty()) answer = "(None)";
    return answer;
}