#include <bits/stdc++.h>

using namespace std;

int n,x,y,d,g;
int arr[105][105], tmp[105][105];
int dx[4] = {1, 0, -1, 0};  // → ↑ ← ↓
int dy[4] = {0, -1, 0, 1};  // → ↑ ← ↓ (위쪽이 -1)


void go(int y, int x, int d, int g){
	vector<int> dirs;
	dirs.push_back(d);
	for(int i=0; i<g; i++){
		for(int j=dirs.size()-1; j>=0; j--){
			dirs.push_back((dirs[j]+1)%4);
		}
	}
	arr[y][x] = 1;
	for(int dir : dirs){
		x += dx[dir];
		y += dy[dir];
		arr[y][x] = 1;
	}
	
	return ;
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x >> y >> d >> g;
		go(y,x,d,g);
	}
	
	// 정사각형 수 count 
	int cnt = 0;
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1) cnt++;
		}
	} 
	
	cout << cnt << "\n"; 

	
	return 0;
}