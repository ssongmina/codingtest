#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> split(string str, string delimeter){
    vector<string> v;
    long long pos;
    string token;

    while((pos = str.find(delimeter)) != string::npos){
        token = str.substr(0, pos);
        v.push_back(token);
        str.erase(0, pos + delimeter.size());
    }
    if(!str.empty()) v.push_back(str);
    return v;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> fee; // 차량번호 -> 누적 시간
    map<string, int> mp;  // 차량번호 -> 입차 시간

    for (auto &rec : records) {
        vector<string> v = split(rec, " ");
        int time = stoi(v[0].substr(0,2)) * 60 + stoi(v[0].substr(3,2));
        string car = v[1];

        if (mp.find(car) == mp.end()) {
            mp[car] = time;
        } else {
            fee[car] += time - mp[car];
            mp.erase(car);
        }
    }

    // 출차 기록 없는 차량 처리
    for (auto &it : mp) {
        fee[it.first] += 23 * 60 + 59 - it.second;
    }

    // 요금 계산 (map이므로 차량번호 오름차순 자동 정렬)
    for (auto &it : fee) {
        int t = it.second;
        int tot = fees[1];

        if (t > fees[0]) {
            t -= fees[0];
            tot += ((t + fees[2] - 1) / fees[2]) * fees[3];
        }

        answer.push_back(tot);
    }

    return answer;
}
