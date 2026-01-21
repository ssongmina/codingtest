#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos;
    while ((pos = input.find(delimiter)) != string::npos) {
        ret.push_back(input.substr(0, pos));
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> order, warn;

    for (int i = 0; i < id_list.size(); i++) {
        order[id_list[i]] = i;
        warn[id_list[i]] = 0;
    }

    vector<vector<string>> num(id_list.size());

    for (int i = 0; i < report.size(); i++) {
        vector<string> s = split(report[i], " ");
        int reporter = order[s[0]];
        string reported = s[1];

        if (find(num[reporter].begin(), num[reporter].end(), reported) == num[reporter].end()) {
            num[reporter].push_back(reported);
            warn[reported]++;
        }
    }

    vector<string> banned;
    for (string id : id_list) {
        if (warn[id] >= k) banned.push_back(id);
    }

    for (int i = 0; i < id_list.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < num[i].size(); j++) {
            if (find(banned.begin(), banned.end(), num[i][j]) != banned.end()) {
                cnt++;
            }
        }
        answer[i] = cnt;
    }

    return answer;
}
