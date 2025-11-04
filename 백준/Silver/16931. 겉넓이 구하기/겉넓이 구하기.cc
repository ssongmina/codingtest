#include <bits/stdc++.h>

using namespace std;

int n,m,cnt;
int arr[105][105];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> arr[i][j];
		}
	}
	cnt = 2*n*m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			for(int k=0; k<4; k++){
				int ny = i + dy[k];
				int nx = j + dx[k];
				int diff = arr[i][j] - arr[ny][nx];
				if(diff >= 0) cnt += diff;
			}
		}
	}
	cout << cnt << "\n";
	
	return 0;
}