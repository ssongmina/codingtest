#include <bits/stdc++.h>

using namespace std;

int n,m,r,a,b,cnt=1;
vector<int> adj[100005];
int visited[100005];

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
		sort(adj[i].rbegin(), adj[i].rend());
	}
	
	queue<int> q;
	q.push(r);
	visited[r] = cnt++;
	while(q.size()){
		int here = q.front();
		q.pop();
		for(auto there : adj[here]){
			if(visited[there]) continue;
			visited[there] = cnt++;
			q.push(there);
		}
	}
	for(int i=1; i<=n; i++){
		cout << visited[i] << "\n";
	}
	
	return 0;
}