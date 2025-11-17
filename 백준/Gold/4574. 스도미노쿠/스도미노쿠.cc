#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
bool usedDom[10][10];       // 도미노 사용 여부
bool rowChk[9][10];         // row에서 숫자 사용 여부
bool colChk[9][10];         // col에서 숫자 사용 여부
bool boxChk[9][10];         // box에서 숫자 사용 여부

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int boxIdx(int y, int x){
    return (y/3)*3 + (x/3);
}

bool isValid(int y, int x, int num){
    return !rowChk[y][num] &&
           !colChk[x][num] &&
           !boxChk[boxIdx(y,x)][num];
}

bool solve(int y, int x){
    if(y == 9) return true;

    int ny = y, nx = x+1;
    if(nx == 9) ny = y+1, nx = 0;

    if(arr[y][x] != 0){
        return solve(ny, nx);
    }

    // 빈 칸이면 도미노를 놓는다
    for(int dir=0; dir<4; dir++){
        int ty = y + dy[dir];
        int tx = x + dx[dir];
        if(ty < 0 || tx < 0 || ty >= 9 || tx >= 9) continue;
        if(arr[ty][tx] != 0) continue;

        for(int a=1; a<=9; a++){
            for(int b=1; b<=9; b++){
                if(a == b) continue;
                if(usedDom[a][b]) continue;

                if(isValid(y,x,a) && isValid(ty,tx,b)){
                    // 사용
                    usedDom[a][b] = usedDom[b][a] = true;
                    arr[y][x] = a;
                    arr[ty][tx] = b;
                    rowChk[y][a] = colChk[x][a] = boxChk[boxIdx(y,x)][a] = true;
                    rowChk[ty][b] = colChk[tx][b] = boxChk[boxIdx(ty,tx)][b] = true;

                    if(solve(ny, nx)) return true;

                    // 복구
                    usedDom[a][b] = usedDom[b][a] = false;
                    arr[y][x] = arr[ty][tx] = 0;
                    rowChk[y][a] = colChk[x][a] = boxChk[boxIdx(y,x)][a] = false;
                    rowChk[ty][b] = colChk[tx][b] = boxChk[boxIdx(ty,tx)][b] = false;
                }
            }
        }
    }
    return false;
}

pair<int,int> getPos(string s){
    int y = s[0] - 'A';
    int x = s[1] - '1';
    return {y, x};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int tc = 1;

    while(true){
        cin >> n;
        if(n == 0) break;

        // 초기화
        memset(arr, 0, sizeof(arr));
        memset(usedDom, 0, sizeof(usedDom));
        memset(rowChk, 0, sizeof(rowChk));
        memset(colChk, 0, sizeof(colChk));
        memset(boxChk, 0, sizeof(boxChk));

        cout << "Puzzle " << tc++ << "\n";

        // 주어진 도미노 입력
        for(int i=0; i<n; i++){
            int u, v;
            string lu, lv;
            cin >> u >> lu >> v >> lv;

            auto a = getPos(lu);
            auto b = getPos(lv);

            arr[a.first][a.second] = u;
            arr[b.first][b.second] = v;

            usedDom[u][v] = usedDom[v][u] = true;

            rowChk[a.first][u] = colChk[a.second][u] = boxChk[boxIdx(a.first,a.second)][u] = true;
            rowChk[b.first][v] = colChk[b.second][v] = boxChk[boxIdx(b.first,b.second)][v] = true;
        }

        // 1~9 수 하나씩 초기 위치 입력
        for(int num=1; num<=9; num++){
            string pos;
            cin >> pos;
            auto p = getPos(pos);

            arr[p.first][p.second] = num;
            rowChk[p.first][num] = colChk[p.second][num] = boxChk[boxIdx(p.first,p.second)][num] = true;
        }

        solve(0, 0);

        // 출력
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
