#include <bits/stdc++.h>
#define y1 aaaa

using namespace std;

int n,m,y1,y2,x1,x2;
int arr[1030][1030], psum[1030][1030];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> arr[i][j];
			psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + arr[i][j];
		}
	}
	for(int i=0; i<m; i++){
		cin >> y1 >> x1 >> y2 >> x2;
		cout << psum[y2][x2] - psum[y1-1][x2] - psum[y2][x1-1] + psum[y1-1][x1-1] << "\n";
	}
	
	return 0;
}