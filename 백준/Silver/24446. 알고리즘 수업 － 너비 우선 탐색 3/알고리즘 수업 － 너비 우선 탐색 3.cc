#include <bits/stdc++.h>

using namespace std;

int n,m,r,a,b;
vector<int> adj[100005];
int visited[100005];

void bfs(int here){
	queue<int> q;
	q.push(here);
	visited[here] = 1;
	while(q.size()){
		here = q.front();
		q.pop();
		for(auto there : adj[here]){
			if(visited[there]) continue;
			visited[there] = visited[here] + 1;
			q.push(there);
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> r;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bfs(r);
	for(int i=1; i<=n; i++) cout << visited[i] - 1 << "\n";
	
	
	return 0;
} 