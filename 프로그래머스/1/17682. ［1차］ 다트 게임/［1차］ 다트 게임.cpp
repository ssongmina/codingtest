#include <bits/stdc++.h>
using namespace std;

int solution(string dartResult) {
    int score[3] = {0};
    int idx = 0;
    string num = "";

    for (int i = 0; i < dartResult.size(); i++) {
        // 숫자 처리
        if (isdigit(dartResult[i])) {
            num += dartResult[i];
        }
        // 보너스 처리
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            int n = stoi(num);
            num = "";

            if (dartResult[i] == 'D') n = pow(n, 2);
            else if (dartResult[i] == 'T') n = pow(n, 3);

            score[idx] = n;

            // 옵션 처리
            if (i + 1 < dartResult.size()) {
                if (dartResult[i + 1] == '*') {
                    score[idx] *= 2;
                    if (idx > 0) score[idx - 1] *= 2;
                    i++;
                }
                else if (dartResult[i + 1] == '#') {
                    score[idx] *= -1;
                    i++;
                }
            }
            idx++;
        }
    }

    return score[0] + score[1] + score[2];
}
