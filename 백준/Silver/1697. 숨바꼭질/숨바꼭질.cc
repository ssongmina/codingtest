#include <bits/stdc++.h>

using namespace std;

int n,k;
int visited[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while(q.size()){
		int x = q.front();
		q.pop();
		if(x == k) break;
		for(auto nx : {x-1, x+1, 2*x}){
			if(nx < 0 || nx > 100000) continue;
			if(visited[nx]) continue;
			visited[nx] = visited[x] + 1;
			q.push(nx);
		}
	}
	
	cout << visited[k] - 1 << "\n";
	
	return 0;
}