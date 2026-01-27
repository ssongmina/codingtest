#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dist(int from, int to) {
    if (from == 0) from = 11;
    if (to == 0) to = 11;

    int fx = (from - 1) / 3;
    int fy = (from - 1) % 3;
    int tx = (to - 1) / 3;
    int ty = (to - 1) % 3;

    return abs(fx - tx) + abs(fy - ty);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l = 10; // *
    int r = 12; // #

    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            l = num;
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            r = num;
        }
        else {
            int ld = dist(l, num);
            int rd = dist(r, num);

            if (ld < rd) {
                answer += "L";
                l = num;
            }
            else if (ld > rd) {
                answer += "R";
                r = num;
            }
            else {
                if (hand == "right") {
                    answer += "R";
                    r = num;
                } else {
                    answer += "L";
                    l = num;
                }
            }
        }
    }
    return answer;
}
