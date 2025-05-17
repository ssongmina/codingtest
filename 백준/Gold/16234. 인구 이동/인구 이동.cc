#include <bits/stdc++.h>

using namespace std;

int n,l,r,t;
bool flag;
vector<pair<int,int>> v;
int arr[55][55], visited[55][55];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void bfs(int y, int x){
	int ret = arr[y][x];
	queue<pair<int,int>> q;
	q.push({y,x});
	visited[y][x] = 1;
	v.push_back({y,x});
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(visited[ny][nx]) continue;
			if(l <= abs(arr[y][x] - arr[ny][nx]) && abs(arr[y][x] - arr[ny][nx]) <= r){
				v.push_back({ny,nx});
				q.push({ny,nx});
				visited[ny][nx] = 1;
				ret += arr[ny][nx];
			}
		}
	}
	
	if(v.size() > 1){
		flag = true;
		int people = ret / v.size();
		for(auto a : v){
			arr[a.first][a.second] = people;
		}
	}
	v.clear();
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> l >> r;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	while(true){
		memset(visited, 0, sizeof(visited));
		// 연결된 컴포넌트 찾기
		flag = false;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(visited[i][j] == 0){
					bfs(i,j);
				} 
			}
		}
		// 없으면 탈출
		if(!flag) break;

		t++; 
	}
	cout << t << "\n";
	
	return 0;
}