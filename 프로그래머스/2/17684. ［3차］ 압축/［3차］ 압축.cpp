#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> mp;
int idx = 27;

void init(){
    mp["A"] = 1; mp["B"] = 2; mp["C"] = 3; mp["D"] = 4;
    mp["E"] = 5; mp["F"] = 6; mp["G"] = 7; mp["H"] = 8;
    mp["I"] = 9; mp["J"] = 10; mp["K"] = 11; mp["L"] = 12;
    mp["M"] = 13; mp["N"] = 14; mp["O"] = 15; mp["P"] = 16;
    mp["Q"] = 17; mp["R"] = 18; mp["S"] = 19; mp["T"] = 20;
    mp["U"] = 21; mp["V"] = 22; mp["W"] = 23; mp["X"] = 24;
    mp["Y"] = 25; mp["Z"] = 26;
}

string check(string msg){
    for(int i=msg.size(); i>0; i--){
        string s = msg.substr(0,i);
        if(mp.find(s) != mp.end()) return s;
    }
}

vector<int> solution(string msg) {
    vector<int> answer;
    init();
    while(msg.size()){
        // 가장 긴 단어 찾기
        string str = check(msg);
        // 색인 번호 출력
        answer.push_back(mp[str]);
        // 사전 등록 
        if(str.size() < msg.size()){
            mp[str+msg[str.size()]] = idx++;
        }
        // 제거
        msg.erase(0, str.size());
    }
    return answer;
}