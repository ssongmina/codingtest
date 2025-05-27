#include <bits/stdc++.h>

using namespace std;

int n,m,ret=1,mx;
vector<int> v;
int arr[55][55], visited[55][55];
int dy[4] = {0,-1,0,1}, dx[4] = {-1,0,1,0};

int dfs(int y, int x){
	int cnt = 1;
	visited[y][x] = ret;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(arr[y][x] & (1<<i)) continue;
		if(visited[ny][nx]) continue;
		cnt += dfs(ny,nx);
		
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j]) continue;
			v.push_back(dfs(i,j));
			ret++;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int d=0; d<4; d++){
				int ny = i + dy[d];
				int nx = j + dx[d];
				if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if(visited[ny][nx] != visited[i][j]){
					int num = v[visited[i][j]-1] + v[visited[ny][nx]-1];
					mx = max(mx, num);
				}
			}
		}
	}
	
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	cout << v[v.size() - 1] << "\n";
	cout << mx << "\n";
	
	return 0;
}