#include <bits/stdc++.h>

using namespace std;

int n,m,a,b;
bool flag = false;
vector<int> adj[2005];
int visited[2005];

void dfs(int here, int depth){   
	if(depth == 5){
		flag = true;
		return ;
	}
	visited[here] = 1;
	for(auto next : adj[here]){
		if(visited[next]) continue;
		dfs(next, depth+1);
		if(flag) return ;
	}
	visited[here] = 0;
	return ;
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
	
	for(int i=0; i<n; i++){
		memset(visited, 0, sizeof(visited));
		dfs(i, 1);
		if(flag) break;
	}
	
	cout << (flag ? 1 : 0) << "\n";
	
	return 0;
}