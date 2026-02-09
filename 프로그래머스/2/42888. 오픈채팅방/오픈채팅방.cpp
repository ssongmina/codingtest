#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> split(string str){
    size_t pos = 0;
    string token = "";
    vector<string> v;

    while((pos = str.find(" ")) != string::npos){
        token = str.substr(0, pos);
        v.push_back(token);
        str.erase(0, pos + 1);
    }

    if(!str.empty()) v.push_back(str);
    return v;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> mp; // uid, 닉네임
    vector<pair<string, string>> v; // enter/leave, uid
    
    for(string str : record){
        vector<string> tmp = split(str);
        if(tmp[0] == "Enter"){
            mp[tmp[1]] = tmp[2];
            v.push_back({"Enter", tmp[1]});
        }
        else if(tmp[0] == "Change"){
            mp[tmp[1]] = tmp[2];
        }
        else if(tmp[0] == "Leave"){
            v.push_back({"Leave", tmp[1]});
        }
    }
    
    for(int i=0; i<v.size(); i++){
        string a = v[i].first; // leave
        string b = v[i].second; // uid
        if(a == "Leave"){
            answer.push_back(mp[b]+"님이 나갔습니다.");
        }
        else if(a == "Enter"){
            answer.push_back(mp[b]+"님이 들어왔습니다.");
        }
    }
    return answer;
}