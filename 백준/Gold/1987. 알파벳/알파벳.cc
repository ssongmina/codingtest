#include <bits/stdc++.h>

using namespace std;

int r,c,ret,mx;
string str;
int arr[25][25], visited[25][25];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void dfs(int y, int x, int num, int cnt){
	mx = max(mx, cnt);
	
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if(num & (1<<arr[ny][nx])) continue;
		dfs(ny, nx, num|(1<<arr[ny][nx]), cnt+1);
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;
	for(int i=0; i<r; i++){
		cin >> str;
		for(int j=0; j<c; j++){
			arr[i][j] = str[j] - 'A';
		}
	}
	
	ret = (1 << arr[0][0]);
	dfs(0,0,ret,1);

	cout << mx << "\n";
	
	return 0;
}