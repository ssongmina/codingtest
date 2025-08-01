#include <bits/stdc++.h>

using namespace std;

int n,r,g,b;
string str;
int arr[105][105], visited[105][105], brr[105][105];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void dfs(int y, int x, int arr[105][105]){
	visited[y][x] = 1;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if(visited[ny][nx] || arr[y][x] != arr[ny][nx]) continue;
		visited[ny][nx] = 1;
		dfs(ny,nx,arr);
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<n; j++){
			if(str[j] == 'B') arr[i][j] = 3, brr[i][j] = 3;
			if(str[j] == 'R') arr[i][j] = 1, brr[i][j] = 1;
			if(str[j] == 'G') arr[i][j] = 2, brr[i][j] = 1;
		}
	}
	
	// 적록 색약 아닌 경우
	int cnt = 0;  
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				dfs(i,j,arr);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	
	// 적록 색약인 경우
	cnt = 0;
	memset(visited,0,sizeof(visited));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				dfs(i,j,brr);
				cnt++;
			}
		}
	} 
	cout << cnt << "\n";
	
	
	return 0;
}