#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n + 1, 1);

    // 체육복 분배 상태 초기화
    for (int l : lost) clothes[l]--;
    for (int r : reserve) clothes[r]++;

    // 앞 번호부터 빌려주기
    for (int i = 1; i <= n; i++) {
        if (clothes[i] == 0) {
            if (i - 1 >= 1 && clothes[i - 1] == 2) {
                clothes[i - 1]--;
                clothes[i]++;
            }
            else if (i + 1 <= n && clothes[i + 1] == 2) {
                clothes[i + 1]--;
                clothes[i]++;
            }
        }
    }

    // 체육수업 가능한 학생 수 계산
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (clothes[i] >= 1) answer++;
    }

    return answer;
}
