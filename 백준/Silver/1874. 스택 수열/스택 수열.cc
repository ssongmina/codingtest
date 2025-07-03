#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int now = 1;
    stack<int> stk;
    bool flag = true;
    
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        while (now <= num) {
            stk.push(now++);
            str += "+\n";
        }
        if (!stk.empty() && stk.top() == num) {
            stk.pop();
            str += "-\n";
        } else {
            flag = false;
            break;
        }
    }

    if (flag) cout << str;
    else cout << "NO\n";

    return 0;
}
