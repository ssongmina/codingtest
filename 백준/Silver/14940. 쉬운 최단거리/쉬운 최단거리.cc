#include <bits/stdc++.h>

using namespace std;

int n,m,ty,tx,y,x;
int arr[1005][1005], visited[1005][1005];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2) ty = i, tx = j;
			if(arr[i][j] == 0) v.push_back({i,j});
		}
	}
	
	queue<pair<int,int>> q;
	q.push({ty, tx});
	memset(visited, -1, sizeof(visited));
	visited[ty][tx] = 1;
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(arr[ny][nx] == 2 || arr[ny][nx] == 0) continue;
			if(visited[ny][nx] != -1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny,nx});
		}
	}
	
	visited[ty][tx] = 0;
	for(auto a : v){
		visited[a.first][a.second] = 0;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j] == 0 || visited[i][j] == -1) cout << visited[i][j] << " ";
			else cout << visited[i][j] - 1 << " ";
		}
		cout << "\n";
	}
	
	return 0;
}