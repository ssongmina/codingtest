#include <bits/stdc++.h>

using namespace std;

int n,m,v,a,b;
vector<int> adj[1005];
int visited[1005];

void dfs(int here){
	cout << here << " ";
	visited[here] = 1;
	for(auto next : adj[here]){
		if(visited[next]) continue;
		dfs(next);
	}
	return ;
}

void bfs(int here){
	queue<int> q;
	q.push(here);
	visited[here] = 1;
	while(q.size()){
		int here = q.front();
		q.pop();
		cout << here << " ";
		for(int next : adj[here]){
			if(visited[next]) continue;
			q.push(next);
			visited[next] = 1;
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> v;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	
	memset(visited, 0, sizeof(visited));
	dfs(v);
	cout << "\n";
	
	memset(visited, 0, sizeof(visited));
	bfs(v);
	cout << "\n";
	
	return 0;
}