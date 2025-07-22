#include <bits/stdc++.h>

using namespace std;

int n,m,u,v;
vector<int> adj[1005];
int visited[1005];

void dfs(int here){
	visited[here] = 1;
	for(auto a : adj[here]){
		if(visited[a]) continue;
		dfs(a);
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 
	
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(visited[i]) continue;
		dfs(i);
		cnt++;
	}
	cout << cnt << "\n";
	
	return 0;
}