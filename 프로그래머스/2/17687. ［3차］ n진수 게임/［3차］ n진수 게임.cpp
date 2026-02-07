#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string go(int n, int idx) {
    if (idx == 0) return "0";

    string str = "";
    while (idx > 0) {
        int r = idx % n;

        if (r < 10) str += char('0' + r);
        else str += char('A' + (r - 10));

        idx /= n;
    }

    reverse(str.begin(), str.end());
    return str;
}

string make(int n, int num) {
    string answer = "";
    int idx = 0;

    while (answer.size() < num) {
        answer += go(n, idx++);
    }

    return answer;
}

string solution(int n, int t, int m, int p) {
    string str = make(n, t * m);
    string answer = "";

    int idx = p - 1;
    while (t--) {
        answer += str[idx];
        idx += m;
    }

    return answer;
}
