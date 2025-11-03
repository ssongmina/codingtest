#include <bits/stdc++.h>

using namespace std;

int n,m,y,x,d,cnt;
int arr[55][55], clean[55][55];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

bool checkAllDir(){
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(arr[ny][nx] == 0 && clean[ny][nx] == 0) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	cin >> y >> x >> d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	
	while(true){
		// 아직 청소하지 않은 경우 
		if(clean[y][x] == 0){
			clean[y][x] = 1;
			cnt++;
		}
		// 주변 4칸 중 청소되지 않은 빈칸이 있는 경우 
		else if(checkAllDir()){
			d  = (d+3)%4; // 반시계 회전 
			int ny = y + dy[d];
			int nx = x + dx[d];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(arr[ny][nx] == 0 && clean[ny][nx] == 0){
				y = ny, x = nx;
			}
		}
		// 주변 4칸 중 청소되지 않은 빈칸이 없는 경우
		else {
			int dd = (d+2)%4;
			int ny = y + dy[dd];
			int nx = x + dx[dd];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(arr[ny][nx] == 0) y = ny, x = nx;
			else break;
		}	
	}
	cout << cnt;
	
	return 0;
}