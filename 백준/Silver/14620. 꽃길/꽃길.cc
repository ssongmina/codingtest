#include <bits/stdc++.h>

using namespace std;

int n, arr[15][15], visited[15][15], price=987654321;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

bool check(int y, int x){
	if(visited[y][x]) return false;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
		if(visited[ny][nx]) return false;
	}
	return true;
}

int setFlo(int y, int x){
	visited[y][x] = 1;
	
	int cnt = arr[y][x];
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		cnt += arr[ny][nx];
		visited[ny][nx] = 1;
	}
	return cnt;
}

void eraseFlo(int y, int x){
	visited[y][x] = 0;
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
	return ;
}

void go(int cnt, int ret){
	if(cnt == 3){
		price = min(price, ret);
		return ;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(check(i,j)){
				go(cnt+1, ret+setFlo(i,j));
				eraseFlo(i,j);
			}
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	
	go(0,0);
	
	cout << price << "\n";
	
	return 0;
}