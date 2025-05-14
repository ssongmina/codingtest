#include <bits/stdc++.h>

using namespace std;

#define empty aaaa 
int n,m,mx;
int arr[10][10], visited[10][10];
vector<pair<int,int>> empty, virus;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1}; 

void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(arr[ny][nx] == 1 || visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		dfs(ny,nx);
	}
	return ;
}

int go(){  
	// 바이러스 뿌리기 
	for(auto v : virus){
		dfs(v.first, v.second);
	}
	// 안전 영역 count 
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j] == 0 && arr[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2) virus.push_back({i,j});
			if(arr[i][j] == 0) empty.push_back({i,j});
		}
	}
	
	for(int i=0; i<empty.size(); i++){
		for(int j=i+1; j<empty.size(); j++){
			for(int k=j+1; k<empty.size(); k++){
				fill(&visited[0][0], &visited[0][0]+10*10, 0);
				// 벽 세우기 
				arr[empty[i].first][empty[i].second] = 1;
				arr[empty[j].first][empty[j].second] = 1;
				arr[empty[k].first][empty[k].second] = 1;
				mx = max(go(), mx);
				// 원복하기 
				arr[empty[i].first][empty[i].second] = 0;
				arr[empty[j].first][empty[j].second] = 0;
				arr[empty[k].first][empty[k].second] = 0;
			}
		}
	}
	cout << mx << "\n";
	
	return 0;
}