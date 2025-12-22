#include <bits/stdc++.h>

using namespace std;

int n,m,mn=987654321;
vector<pair<int,int>> v;
int arr[55][55], brr[55][55], crr[55][55];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
vector<vector<int>> b;



void comb(int start, vector<int> bb){
	if(bb.size() == m){
		b.push_back(bb);
		return ;
	}
	for(int i=start+1; i<v.size(); i++){
		bb.push_back(i);
		comb(i, bb);
		bb.pop_back();
	}
}

void go(vector<int> b){
	memcpy(crr, brr, sizeof(brr));
	queue<pair<int,int>> q;
	for(int i=0; i<m; i++){
		int y = v[b[i]].first;
		int x = v[b[i]].second;
		q.push({y,x});
		crr[y][x] = 1;
	}
	while(q.size()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(crr[ny][nx] == -1) continue;
			if(crr[ny][nx] == 0){
				crr[ny][nx] = crr[y][x] + 1;
				q.push({ny,nx});
			}
		}
	}
	int ret = 0;
	bool flag = true;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(crr[i][j] == 0) flag = false;
			ret = max(ret, crr[i][j]);
		}
	}
	if(flag) mn = min(mn, ret);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 0 빈칸, 1 벽, 2 바이러스 
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2) v.push_back({i,j});
			if(arr[i][j] == 1) brr[i][j] = -1;
		}
	}
	
	vector<int> bb;
	comb(-1,bb); 
	
	for(auto a : b){
		go(a);
	}
	
	if(mn == 987654321) cout << -1 << "\n";
	else cout << mn-1 << "\n";
	
	return 0;
}