#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> v, tree;

void update(int idx, ll diff) {
    while (idx <= n) {
        tree[idx] += diff;
        idx += idx & -idx;
    }
}

ll sum(int idx) {
    ll ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

ll rangeQuery(int left, int right) {
    return sum(right) - sum(left - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k;
    v.resize(n + 1); // 1-based
    tree.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        update(i, v[i]);
    }

    for (int i = 0; i < m + k; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            ll c;
            cin >> b >> c;
            ll diff = c - v[b];
            v[b] = c;
            update(b, diff);
        } else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << rangeQuery(b, c) << '\n';
        }
    }

    return 0;
}
