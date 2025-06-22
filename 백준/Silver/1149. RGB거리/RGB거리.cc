#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1005][3], visited[1005][3];
int dir[3][2] = {{0,1},{0,2},{1,2}};

void go(int idx){
	if(idx > n){
		return ;
	}
	visited[idx][0] = min(visited[idx-1][1], visited[idx-1][2]) + arr[idx][0];
	visited[idx][1] = min(visited[idx-1][0], visited[idx-1][2]) + arr[idx][1];
	visited[idx][2] = min(visited[idx-1][0], visited[idx-1][1]) + arr[idx][2];
	go(idx+1);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	
	visited[0][0] = visited[0][1] = visited[0][2] = 0;
	go(1);
	
	cout << min(visited[n][0], min(visited[n][1], visited[n][2])) << "\n";
	
	
	return 0;
}