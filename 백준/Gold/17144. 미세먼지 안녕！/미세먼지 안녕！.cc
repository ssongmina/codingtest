#include <bits/stdc++.h>
using namespace std;

int r, c, t;
int arr[55][55], temp[55][55];
int k1 = -1, k2 = -1;  // 공기청정기 위치
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void spread() {
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] > 0) {
                int cnt = 0;
                int val = arr[i][j] / 5;
                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                    if (arr[ny][nx] == -1) continue;
                    temp[ny][nx] += val;
                    cnt++;
                }
                temp[i][j] += arr[i][j] - val * cnt;
            }
        }
    }

    // 공기청정기 위치 복원
    temp[k1][0] = -1;
    temp[k2][0] = -1;

    memcpy(arr, temp, sizeof(arr));
}

void air1() { // 위쪽 - 반시계 방향
    vector<pair<int, int>> v;
    vector<int> val;
    int y = k1;

    for (int i = 1; i < c; i++) {
        v.push_back({y, i});
        val.push_back(arr[y][i]);
    }
    for (int i = y - 1; i >= 0; i--) {
        v.push_back({i, c - 1});
        val.push_back(arr[i][c - 1]);
    }
    for (int i = c - 2; i >= 0; i--) {
        v.push_back({0, i});
        val.push_back(arr[0][i]);
    }
    for (int i = 1; i < y; i++) {
        v.push_back({i, 0});
        val.push_back(arr[i][0]);
    }

    rotate(val.rbegin(), val.rbegin() + 1, val.rend());
    val[0] = 0;
    for (int i = 0; i < v.size(); i++) {
        arr[v[i].first][v[i].second] = val[i];
    }
}

void air2() { // 아래쪽 - 시계 방향
    vector<pair<int, int>> v;
    vector<int> val;
    int y = k2;

    for (int i = 1; i < c; i++) {
        v.push_back({y, i});
        val.push_back(arr[y][i]);
    }
    for (int i = y + 1; i < r; i++) {
        v.push_back({i, c - 1});
        val.push_back(arr[i][c - 1]);
    }
    for (int i = c - 2; i >= 0; i--) {
        v.push_back({r - 1, i});
        val.push_back(arr[r - 1][i]);
    }
    for (int i = r - 2; i > y; i--) {
        v.push_back({i, 0});
        val.push_back(arr[i][0]);
    }

    rotate(val.rbegin(), val.rbegin() + 1, val.rend());
    val[0] = 0;
    for (int i = 0; i < v.size(); i++) {
        arr[v[i].first][v[i].second] = val[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                if (k1 == -1) k1 = i;
                else k2 = i;
            }
        }
    }

    while (t--) {
        spread();   // 1. 미세먼지 확산
        air1();     // 2. 위쪽 공기청정기 작동
        air2();     // 3. 아래쪽 공기청정기 작동
    }

    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] > 0) sum += arr[i][j];
        }
    }

    cout << sum << "\n";
    return 0;
}
