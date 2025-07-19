#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int ret = -987654321;
int arr[15][15], visited[15][15];
vector<pair<int,int>> v, vv;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int check(vector<pair<int,int>> vv){
	memset(visited, 0, sizeof(visited));
	int sum = 0;
	for(auto a : vv){
		int y = a.first;
		int x = a.second;
		visited[y][x] = 1;
		sum += arr[y][x];
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visited[ny][nx]) return -987654321;
		}
	}
	return sum;
}

void go(int idx, vector<pair<int,int>> vv){
	if(vv.size() == k){
		ret = max(ret, check(vv));
		return ;
	}
	for(int i=idx; i<v.size(); i++){
		vv.push_back({v[i].first, v[i].second});
		go(i+1, vv);
		vv.pop_back();
		
		//go(i+1, vv);
	}
	return ;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
			v.push_back({i,j});
		}
	}
	
	go(0, vv);
	cout << ret << "\n";
	
	return 0;
}