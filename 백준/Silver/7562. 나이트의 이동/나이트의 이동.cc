#include <bits/stdc++.h>

using namespace std;

int t,n,y,x,ty,tx;
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int visited[305][305];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> n;
		cin >> y >> x >> ty >> tx;
		memset(visited, 0, sizeof(visited));
		queue<pair<int,int>> q;
		q.push({y,x});
		visited[y][x] = 1;
		while(q.size()){
			tie(y,x) = q.front();
			q.pop();
			if(y == ty && x == tx) break;
			for(int i=0; i<8; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if(visited[ny][nx]) continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ny,nx});
			}
		}
		cout << visited[ty][tx] - 1 << "\n";
	}
	
	return 0;
}