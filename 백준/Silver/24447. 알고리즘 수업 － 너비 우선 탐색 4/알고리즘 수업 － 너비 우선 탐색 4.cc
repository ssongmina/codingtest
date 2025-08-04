#include <bits/stdc++.h>

using namespace std;

long long n,m,r,a,b;
vector<long long> adj[100005];
long long visited[100005]; // 깊이
long long countt[100005]; // 방문 순서 

void bfs(int here){
	queue<int> q;
	q.push(here);
	visited[here] = 1;
	long long cnt = 1;
	countt[here] = cnt++;
	while(q.size()){
		here = q.front();
		q.pop();
		for(auto there : adj[here]){
			if(visited[there]) continue;
			visited[there] = visited[here] + 1;
			q.push(there);
			countt[there] = cnt++;
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
	for(int i=1; i<=n; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	
	bfs(r);
	long long ret = 0;
	for(int i=1; i<=n; i++){
		ret += (visited[i]-1) * countt[i];
	}
	cout << ret << "\n";
	
	
	return 0;
} 