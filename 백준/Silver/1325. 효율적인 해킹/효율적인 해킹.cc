#include <bits/stdc++.h>

using namespace std;

int n,m,a,b,mx;
int visited[10005];
vector<int> v[10005], cnt[10005];

int go(int start){
	queue<int> q;
	q.push(start);
	int ret = 1;
	visited[start] = 1;
	while(q.size()){
		int x = q.front();
		q.pop();
		for(int here : v[x]){
			if(visited[here]) continue;
			q.push(here);
			visited[here] = 1;
			ret++;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	while(m--){
		cin >> a >> b;
		v[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++){
		memset(visited, 0, sizeof(visited));
		int ret = go(i);
		mx = max(mx, ret);
		cnt[ret].push_back(i);
	}
	
	for(auto a : cnt[mx]) cout << a << " ";
	
	return 0;
}