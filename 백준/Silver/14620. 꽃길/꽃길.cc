#include <bits/stdc++.h>

using namespace std;

int n, mn=987654321;
int land[15][15], visited[15][15];
vector<vector<pair<int,int>>> seed;
vector<pair<int,int>> v, spot;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void combi(int idx, vector<pair<int,int>> spot){
	if(spot.size() == 3){
		seed.push_back(spot);
		return ;
	}
	for(int i=idx+1; i<v.size(); i++){
		spot.push_back(v[i]);
		combi(i, spot);
		spot.pop_back();
	}
	return ;
}

void check(vector<pair<int,int>> a){
	int sum = 0;
	memset(visited, 0, sizeof(visited));
	for(auto k : a){
		if(visited[k.first][k.second]) return ;
		visited[k.first][k.second] = 1;
		sum += land[k.first][k.second];
		for(int i=0; i<4; i++){
			int ny = k.first + dy[i];
			int nx = k.second + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) return ;
			if(visited[ny][nx]) return ;
			visited[ny][nx] = 1;
			sum += land[ny][nx];
		}
	}
	mn = min(sum, mn);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 입력 
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> land[i][j];
		}
	}
	// 씨앗 3개 심을 곳 정하기 

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			v.push_back({i,j});
		}
	}
	combi(-1, spot);

	// 최소 가격인지 확인
	for(auto a : seed){
		check(a);
	}
	 
	cout << mn << "\n";
	
	return 0;
}