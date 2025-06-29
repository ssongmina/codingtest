#include <bits/stdc++.h>

using namespace std;

int n,m,ret;
string str;
char arr[55][55];
int dp[55][55], visited[55][55];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int go(int y, int x){
	if(y < 0 || x < 0 || y >= n || x >= m || arr[y][x] == 'H') return 0;
	if(visited[y][x]){
		cout << "-1\n";
		exit(0);
	}
	
	if(dp[y][x]) return dp[y][x];
	
	visited[y][x] = 1;
	int move = arr[y][x] - '0';
	for(int i=0; i<4; i++){
		int ny = y + dy[i] * move;
		int nx = x + dx[i] * move;
		dp[y][x] = max(dp[y][x], go(ny,nx) + 1);
	}
	visited[y][x] = 0;
	return dp[y][x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<m; j++){
			arr[i][j] = str[j];
		}
	}
	
	cout << go(0,0) << "\n";
	
	return 0;
}