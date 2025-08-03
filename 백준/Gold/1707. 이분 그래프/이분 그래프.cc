#include <bits/stdc++.h>

using namespace std;

bool g;
int t,v,e,a,b;
int visited[20005];
vector<int> adj[20005];

void bfs(int here, int color){
	queue<int> q;
	q.push(here);
	visited[here] = color;
	while(q.size()){
		int here = q.front();
		q.pop();
		for(auto there : adj[here]){
			if(visited[there] == 0){
				visited[there] = -visited[here];
				q.push(there);
			}
			else if(visited[there] + visited[here] != 0){
				g = false;
				return ;
			}
			
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> v >> e;
		for(int i=0; i<20005; i++){
			adj[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<e; i++){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		g = true;
		// 비연결 그래프일수도 있으니께 
		for(int i=1; i<=v; i++){
			if(visited[i] == 0)	
				bfs(i,1);
		}
		if(g) cout << "YES\n";
		else cout << "NO\n";
		
	}
	
	return 0;
}