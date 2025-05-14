#include <bits/stdc++.h>

using namespace std;

int n,m, cnt, num;
vector<pair<int,int>> v;
int arr[105][105], visited[105][105];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void dfs(int y, int x){
	visited[y][x] = 1;
	if(arr[y][x] == 1){
		v.push_back({y,x});
		return ;
	}
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(visited[ny][nx]) continue;
		dfs(ny,nx);
	}
	return ;
}

bool check(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j]) return false;
		}
	}
	return true;
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
	
	while(true){
		fill(&visited[0][0], &visited[0][0] + 105*105, 0);
		v.clear();
		dfs(0,0);
		for(auto a : v){
			arr[a.first][a.second] = 0;
		}
		num = v.size();
		cnt++;
		if(check()) break;
	}
	cout << cnt << "\n" << num << "\n";
	
	
	return 0;
}