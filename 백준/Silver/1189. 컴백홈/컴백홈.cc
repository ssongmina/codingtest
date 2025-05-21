#include <bits/stdc++.h>

using namespace std;

int r,c,k,cnt;
char arr[8][8];
int visited[8][8];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void dfs(int y, int x, int ret){
	if(ret+1 == k){
		if(y == 0 && x == c-1) cnt++;
		return ;
	}

	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if(arr[ny][nx] == 'T' || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		dfs(ny,nx,ret+1);
		visited[ny][nx] = 0;
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c >> k;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> arr[i][j];
		}
	}
	
	visited[r-1][0] = 1;
	dfs(r-1,0,0);
	
	cout << cnt << "\n";
	
	return 0;
}