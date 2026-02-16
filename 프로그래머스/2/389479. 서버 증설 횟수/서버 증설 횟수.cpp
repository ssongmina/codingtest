#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int server[30];
    memset(server, 0, sizeof(server));
    for(int i=0; i<players.size(); i++){
        int n = players[i]/m;
        if(n == 0) continue;
        if(server[i] >= n) continue;
        int p = n - server[i];
        answer += p;
        for(int j=i; j<i+k && j < players.size(); j++){
            server[j] += p;
        }
    }
    return answer;
}