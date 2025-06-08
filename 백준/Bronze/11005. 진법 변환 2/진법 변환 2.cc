#include <bits/stdc++.h>
using namespace std;

int n, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> b;

    string result = "";
    while (n > 0) {
        int r = n % b;
        if (r < 10) result += (r + '0');
        else result += (r - 10 + 'A');
        n /= b;
    }

    reverse(result.begin(), result.end());
    cout << result << "\n";

    return 0;
}
