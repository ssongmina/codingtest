#include <bits/stdc++.h>

using namespace std;

int n, y,x, ans;
int arr[20][20];
vector<int> dy[3] = {{0,1},{1,1},{0,1,1}};
vector<int> dx[3] = {{1,1},{0,1},{1,1,0}};
vector<int> nd[3] = {{0,2},{1,2},{0,1,2}};

void go(int y, int x, int dir){
	if(y == n-1 && x == n-1){
		ans++;
		return ;
	}
	if(dir == 0 || dir == 2){
		if(x+1 < n && arr[y][x+1] == 0)
			go(y,x+1,0);
	}
	if(dir == 1 || dir == 2){
		if(y+1 < n && arr[y+1][x] == 0)
			go(y+1,x,1);
	}
	
	if(x+1 < n && y+1 < n){
		if(arr[y][x+1] == 0 && arr[y+1][x] == 0 && arr[y+1][x+1] == 0)
			go(y+1,x+1,2);
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
	
	go(0,1,0);
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cout << visited[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	cout << ans << "\n";
	
	return 0;
}