#include <bits/stdc++.h>

using namespace std;

int n,m,a,b,x,y;
vector<int> adj[105];
int visited[105];

int bfs(int here, int check){
	memset(visited, 0, sizeof(visited));
	visited[here] = 1;
	queue<int> q;
	q.push(here);
	while(q.size()){
		here = q.front();
		q.pop();
		if(here == check) break;
		for(auto there : adj[here]){
			if(visited[there]) continue;
			visited[there] = visited[here] + 1;
			q.push(there);
		}
	}
	return visited[check] - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> a >> b >> m;
	for(int i=0; i<m; i++){
		cin >> x >> y;
		adj[x].push_back(y); // x 부모, y 자식
		adj[y].push_back(x); 
	}
	
	cout << max(bfs(a,b), bfs(b,a)) << "\n"; 
	
	
	return 0;
}