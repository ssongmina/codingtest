#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, k;
int arr[25][25];
int dice[6] = {0, 0, 0, 0, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

void roll(int dir) {
    int temp;
    // 동쪽
    if (dir == 1) {
        temp = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    }
    // 서쪽
    else if (dir == 2) {
        temp = dice[0];
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
    // 북쪽
    else if (dir == 3) {
        temp = dice[0];
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    }
    // 남쪽
    else if (dir == 4) {
        temp = dice[0];
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

        roll(dir);
        if (arr[ny][nx] == 0)
            arr[ny][nx] = dice[1];
        else {
            dice[1] = arr[ny][nx];
            arr[ny][nx] = 0;
        }

        cout << dice[0] << "\n";
        y = ny;
        x = nx;
    }
}
