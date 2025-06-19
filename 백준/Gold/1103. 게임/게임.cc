#include <bits/stdc++.h>

using namespace std;

int n,m,ret;
string str;
int visited[55][55], board[55][55], dp[55][55];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int go(int y, int x){
	if(y < 0 || x < 0 || y >= n || x >= m || board[y][x] == 0) return 0;
	if(visited[y][x]){
		cout << "-1\n";
		exit(0);
	}
	if (dp[y][x]) return dp[y][x];

    visited[y][x] = true;
    int max_cnt = 0, step = board[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i] * step;
        int nx = x + dx[i] * step;
        max_cnt = max(max_cnt, go(ny, nx) + 1);
    }
    visited[y][x] = false;

    return dp[y][x] = max_cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<m; j++){
			if(str[j] == 'H') board[i][j] = 0;
			else board[i][j] = str[j] - '0';
		}
	}
	
	cout << go(0,0) << "\n";
	
	return 0;
} 