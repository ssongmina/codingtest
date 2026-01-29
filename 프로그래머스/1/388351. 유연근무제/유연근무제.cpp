#include <string>
#include <vector>

using namespace std;

int add10(int t) {
    int h = t / 100;
    int m = t % 100;
    m += 10;
    if(m >= 60) {
        h++;
        m -= 60;
    }
    return h * 100 + m;
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0; i<schedules.size(); i++){ // 직원 
        int time = add10(schedules[i]);
        int cnt = 0;
        for(int j=0; j<timelogs[i].size(); j++){ 
            int day = (startday + j - 1) % 7 + 1;
            if(day == 6 || day == 7) continue;
            if(timelogs[i][j] <= time) cnt++;
        }
        if(cnt == 5) answer++;
    }
    return answer;
}