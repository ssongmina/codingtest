#include <bits/stdc++.h>

using namespace std;

#define move aaaa
string str;
int r,c,jy,jx,y,x;
queue<pair<int,int>> q;
char arr[1005][1005];
int red[1005][1005], move[1005][1005];
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;
	fill(&red[0][0], &red[0][0]+1005*1005, 987654321);
	for(int i=0; i<r; i++){
		cin >> str;
		for(int j=0; j<c; j++){
			arr[i][j] = str[j];
			if(arr[i][j] == 'J') jy = i, jx = j;
			if(arr[i][j] == 'F'){
				q.push({i,j});
				red[i][j] = 1;
			}
		}
	}
	
	// 불 이동
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if(arr[ny][nx] == '#' || red[ny][nx] != 987654321) continue;
			q.push({ny,nx});
			red[ny][nx] = red[y][x] + 1;
		}
	} 
	
	// 지훈 이동
	int ret = 0;
	move[jy][jx] = 1;
	q.push({jy,jx});
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		if(y == 0 || x == 0 || y == r-1 || x == c-1){
			ret = move[y][x];
			break;
		}
		for(int i=0; i<4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if(move[ny][nx] || arr[ny][nx] == '#') continue;
			if(red[ny][nx] <= move[y][x] + 1) continue;
			q.push({ny,nx});
			move[ny][nx] = move[y][x] + 1;
		}
	} 
	
	if(ret) cout << ret << "\n";
	else cout << "IMPOSSIBLE\n";
	
	return 0;
}