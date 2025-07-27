#include <bits/stdc++.h>
#define y1 aaaa

using namespace std;

int n,y1,x1,y2,x2,y,x;
int visited[205][205];
int dy[6] = {-2,-2,0,0,2,2};
int dx[6] = {-1,1,-2,2,-1,1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> y1 >> x1 >> y2 >> x2;
	
	memset(visited, -1, sizeof(visited));
	
	queue<pair<int,int>> q;
	q.push({y1,x1});
	visited[y1][x1] = 1;
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		if(y == y2 && x == x2) break;
		for(int i=0; i<6; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(visited[ny][nx] != -1) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny,nx});
			
		}
	}
	

	cout << (visited[y2][x2] == -1 ? -1 : visited[y2][x2] - 1) << "\n";
	
	return 0;
}