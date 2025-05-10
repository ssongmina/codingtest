#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int m,n,k,y11,x1,y2,x2;
int arr[104][104], visited[104][104];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int dfs(int y, int x){
	visited[y][x] = 1;
	int ret = 1;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if(arr[ny][nx] || visited[ny][nx]) continue;
		ret += dfs(ny,nx);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m >> n >> k;
	while(k--){
		cin >> x1 >> y11 >> x2 >> y2;
		for(int i=y11; i<y2; i++){
			for(int j=x1; j<x2; j++){
				arr[i][j] = 1;
			}
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j] || visited[i][j]) continue;
			int ret = dfs(i,j);
			v.push_back(ret);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for(auto a : v) cout << a << " ";
	
	return 0;
}