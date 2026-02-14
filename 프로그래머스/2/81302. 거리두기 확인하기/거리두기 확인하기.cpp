#include <string>
#include <vector>
#include <cmath>

using namespace std;

int go(vector<string> &v) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (v[i][j] != 'P') continue;

            // 모든 다른 좌표 검사
            for (int ni = 0; ni < 5; ni++) {
                for (int nj = 0; nj < 5; nj++) {
                    if (i == ni && j == nj) continue;
                    if (v[ni][nj] != 'P') continue;

                    int dist = abs(i - ni) + abs(j - nj);
                    if (dist > 2) continue;

                    // 1️⃣ 거리 1
                    if (dist == 1) return 0;

                    // 2️⃣ 거리 2 직선
                    if (dist == 2 && (i == ni || j == nj)) {
                        int mid_i = (i + ni) / 2;
                        int mid_j = (j + nj) / 2;
                        if (v[mid_i][mid_j] != 'X') return 0;
                    }

                    // 3️⃣ 거리 2 대각선
                    if (dist == 2 && i != ni && j != nj) {
                        if (v[i][nj] != 'X' || v[ni][j] != 'X')
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; i++) {
        answer.push_back(go(places[i]));
    }
    return answer;
}
