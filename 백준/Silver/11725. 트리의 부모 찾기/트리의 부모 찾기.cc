#include <bits/stdc++.h>

using namespace std;

int n,a,b;
int visited[100004];
vector<int> adj[100004];
map<int,int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while(q.size()){
		int here = q.front();
		q.pop();
		for(auto next : adj[here]){
			if(visited[next]) continue;
			mp[next] = here;
			visited[next] = 1;
			q.push(next);
		}
	}
	
	for(int i=2; i<=n; i++){
		cout << mp[i] << "\n";
	}
	
	return 0;
}