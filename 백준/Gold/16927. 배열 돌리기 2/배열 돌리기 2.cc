#include <bits/stdc++.h>

using namespace std;

int n,m,r,cnt,y,x;
int arr[305][305];

void go(int y, int x, int ys, int xs){
	vector<int> v;
	for(int i=x; i<x+xs; i++) v.push_back(arr[y][i]);
	for(int i=y+1; i<y+ys-1; i++) v.push_back(arr[i][x+xs-1]);
	for(int i=x+xs-1; i>=x; i--) v.push_back(arr[y+ys-1][i]);
	for(int i=y+ys-2; i>y; i--) v.push_back(arr[i][x]);
	
	rotate(v.begin(), v.begin()+r%v.size(), v.end());
	
	int cnt = 0;
	for(int i=x; i<x+xs; i++) arr[y][i] = v[cnt++];
	for(int i=y+1; i<y+ys-1; i++) arr[i][x+xs-1] = v[cnt++];
	for(int i=x+xs-1; i>=x; i--) arr[y+ys-1][i] = v[cnt++];
	for(int i=y+ys-2; i>y; i--) arr[i][x] = v[cnt++];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> r;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	
	cnt = min(n,m)/2;
	for(int i=0; i<cnt; i++){
		go(i,i, n-2*i, m-2*i);
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}