#include <bits/stdc++.h>  // #2606 바이러스 

using namespace std;

int n,m,a,b;
vector<int> adj[105];
int visited[105];

int dfs(int here){
	visited[here] = 1;
	int cnt = 1;
	for(auto next : adj[here]){
		if(visited[next]) continue;
		cnt += dfs(next);
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	} 
	
	cout << dfs(1) - 1 << "\n";
	
	return 0;
}