#include <bits/stdc++.h>

using namespace std;

int n,m,mx;
int arr[505][505], visited[505][505];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void dfs(int depth, int y, int x, int cnt){
	if(depth == 4){
		mx = max(mx, cnt);
		return ;
	}
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		dfs(depth+1, ny, nx, cnt + arr[ny][nx]);
		visited[ny][nx] = 0;
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			visited[i][j] = 1;
			dfs(0,i,j,0);
			visited[i][j] = 0;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(0<=i && 0<=j && i+1<n && j+2<m){
				mx = max(mx, arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]);
				mx = max(mx, arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2]);
			}
			if(0<=i && 0<=j && i+2<n && j+1<m){
				mx = max(mx, arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j+1]);
				mx = max(mx, arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1]);
			}
			
		}
	}
	cout << mx << "\n";
	
	return 0;
}