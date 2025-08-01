#include <bits/stdc++.h>

using namespace std;

int w,h;
int arr[55][55], visited[55][55];
int dx[8] = { 1,1,0,-1,-1,-1,0,1 }; 
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

void dfs(int y, int x){
	visited[y][x] = 1;
	for(int i=0; i<8; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
		if(!visited[ny][nx] && arr[ny][nx]){
			visited[ny][nx] = 1;
			dfs(ny,nx);
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while(true){
		cin >> w >> h;
		if(w == 0 && h == 0) return 0;
		
		memset(visited,0,sizeof(visited));
		memset(arr,0,sizeof(arr));
		
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> arr[i][j];
			}
		}
		
		int cnt = 0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(arr[i][j] && !visited[i][j]){
					dfs(i,j); 
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		
	}
	
	
	return 0;
}