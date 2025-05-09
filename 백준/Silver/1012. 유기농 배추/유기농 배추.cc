#include <bits/stdc++.h>

using namespace std;

int n,m,k,t,y,x,cnt;
int arr[55][55], visited[55][55];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(visited[ny][nx] || arr[ny][nx] == 0) continue;
		dfs(ny,nx);
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		fill(&arr[0][0], &arr[0][0] + 55*55, 0);
		fill(&visited[0][0], &visited[0][0] + 55*55, 0);
		for(int i=0; i<k; i++){
			cin >> y >> x;
			arr[y][x] = 1;
		}
		cnt = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j] && visited[i][j] == 0){
					cnt++;
					dfs(i,j);
				}
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}