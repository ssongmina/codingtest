#include <bits/stdc++.h>

using namespace std;

int n,m,ret;
string str;
int arr[55][55], visited[55][55];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void bfs(int y, int x){
	memset(visited, 0, sizeof(visited));
	queue<pair<int,int>> q;
	q.push({y,x});
	visited[y][x] = 1;
	int cnt = 0;
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visited[ny][nx] || arr[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			cnt = max(cnt, visited[ny][nx]);
			q.push({ny,nx});
		}	
	}
	ret = max(ret, cnt);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<m; j++){
			if(str[j] == 'L') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == 1) bfs(i,j);
		}
	}
	
	cout << ret-1 << "\n";
	
	return 0;
}