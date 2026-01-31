#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, string delimiter){
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos){
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int n = friends.size();
    int arr[55][55] = {0}; // 준사람, 받은사람
    int gift[55] = {0};     // 선물 지수
    int get_gift[55] = {0}; // 다음 달 받을 선물 수
    map<string, int> idx;

    // 친구 이름 → 인덱스
    for(int i=0; i<n; i++){
        idx[friends[i]] = i;
    }

    // 준/받은 기록 및 선물 지수 계산
    for(string g : gifts){
        vector<string> str = split(g, " ");
        int giver = idx[str[0]];
        int receiver = idx[str[1]];
        arr[giver][receiver]++;
        gift[giver]++;
        gift[receiver]--;
    }

    // 다음 달 받을 선물 계산 (i<j 쌍만 비교)
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int a = arr[i][j];
            int b = arr[j][i];

            if(a > b) get_gift[i]++;
            else if(a < b) get_gift[j]++;
            else { // 동률이면 선물 지수 비교
                if(gift[i] > gift[j]) get_gift[i]++;
                else if(gift[i] < gift[j]) get_gift[j]++;
            }
        }
    }

    // 가장 많이 받을 선물 수
    for(int i=0; i<n; i++){
        answer = max(answer, get_gift[i]);
    }

    return answer;
}