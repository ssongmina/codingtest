#include <bits/stdc++.h>

using namespace std;

int n,m;
string str;
int arr[104][104], visited[104][104];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> str;
		for(int j=0; j<m; j++){
			arr[i][j] = str[j] - '0';
		}
	}
	
	visited[0][0] = 1;
	queue<pair<int,int>> q;
	q.push({0,0});
	while(q.size()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visited[ny][nx] || arr[ny][nx] == 0) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
		}
	}
	cout << visited[n-1][m-1] << "\n";
	
	return 0;
}