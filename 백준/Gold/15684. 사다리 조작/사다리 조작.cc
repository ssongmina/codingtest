#include <bits/stdc++.h>
using namespace std;

int n, m, h, a, b, mn = 4;
int arr[35][15];
vector<pair<int,int>> pos;

bool check(){
	for(int i = 1; i <= n; i++){
		int x = i, y = 1;
		while(y <= h){
			if(arr[y][x]) x++;
			else if(x > 1 && arr[y][x-1]) x--;
			y++;
		}
		if(x != i) return false;
	}
	return true;
}

void dfs(int idx, int cnt){
	if(cnt >= mn) return;
	if(check()) {
		mn = cnt;
		return;
	}
	for(int i = idx; i < pos.size(); i++){
		int y = pos[i].first;
		int x = pos[i].second;
		if(arr[y][x] || arr[y][x-1] || arr[y][x+1]) continue;
		arr[y][x] = 1;
		dfs(i + 1, cnt + 1);
		arr[y][x] = 0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> h;

	for(int i = 0; i < m; i++){
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for(int i = 1; i <= h; i++){
		for(int j = 1; j < n; j++){
			if(!arr[i][j]) pos.push_back({i, j});
		}
	}

	dfs(0, 0);

	cout << (mn == 4 ? -1 : mn) << "\n";
	return 0;
}
