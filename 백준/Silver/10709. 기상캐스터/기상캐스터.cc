#include <bits/stdc++.h>

using namespace std;

int h,w;
string str;
int cloud[105][105], visited[105][105];

void bfs(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	visited[y][x] = 0;
	while(q.size()){
		tie(y,x) = q.front();
		q.pop();
		if(x+1 < w && cloud[y][x+1] == 0){
			visited[y][x+1] = visited[y][x] + 1;
			q.push({y,x+1});
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> h >> w;
	for(int i=0; i<h; i++){
		cin >> str;
		for(int j=0; j<w; j++){
			if(str[j] == 'c') cloud[i][j] = 0;
			else cloud[i][j] = -1;
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(j > 0 && cloud[i][j-1] != -1 && cloud[i][j] != 0){
				cloud[i][j] = cloud[i][j-1] + 1;
			}
		}
	}

	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout << cloud[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}