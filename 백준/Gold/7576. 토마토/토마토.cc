#include <bits/stdc++.h>

using namespace std;

int n,m,y,x, mx;
int arr[1005][1005], visited[1005][1005];
queue<pair<int,int>> q;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1){
				q.push({i,j});
				visited[i][j] = 1;
			}
		}
	}
	
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		mx = max(mx, visited[y][x]);
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(arr[ny][nx] == -1 || visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny,nx});
		} 
	}
	
	bool flag = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == -1) continue;
			if(visited[i][j] == 0) flag = false;
		}
	}
	
	if(flag) cout << mx-1 << "\n";
	else cout << "-1\n";
	
	
	return 0;
}