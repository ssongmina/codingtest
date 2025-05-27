#include <bits/stdc++.h>

using namespace std;

int t,m,n,a,b;
int visited[1005];
vector<int> v[1005];

void go(int here){
	visited[here] = 1;
	for(auto next : v[here]){
		if(visited[next]) continue;
		go(next);
	}
	return ;
}

bool check(){
	for(int i=1; i<=n; i++){
		if(!visited[i]) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	while(t--){
		bool flag = true;
		memset(visited, 0, sizeof(visited));
		cin >> n >> m;
		for(int i=0; i<m; i++){
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		go(1);
		if(check() && m == n-1){
			cout << "tree\n";
		}
		else cout << "graph\n";
		

		for(int i=1; i<=n; i++){
			v[i].clear();
		}
	}

	
	
	return 0;
}