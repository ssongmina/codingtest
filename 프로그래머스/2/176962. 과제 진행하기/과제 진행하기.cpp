#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int changeTime(string str){
    return stoi(str.substr(0,2))*60 + stoi(str.substr(3,2));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> stk;

    sort(plans.begin(), plans.end(), [](auto &a, auto &b){
        return changeTime(a[1]) < changeTime(b[1]);
    });

    for(int i = 0; i < plans.size() - 1; i++){
        string name = plans[i][0];
        int start = changeTime(plans[i][1]);
        int play = stoi(plans[i][2]);
        int nextStart = changeTime(plans[i+1][1]);

        int diff = nextStart - start;

        if(play <= diff){
            answer.push_back(name);
            int remain = diff - play;

            while(!stk.empty() && remain > 0){
                auto [sname, stime] = stk.top();
                stk.pop();

                if(stime <= remain){
                    remain -= stime;
                    answer.push_back(sname);
                } else {
                    stk.push({sname, stime - remain});
                    remain = 0;
                }
            }
        } else {
            stk.push({name, play - diff});
        }
    }

    answer.push_back(plans.back()[0]);

    while(!stk.empty()){
        answer.push_back(stk.top().first);
        stk.pop();
    }

    return answer;
}
