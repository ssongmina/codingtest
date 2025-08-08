#include <bits/stdc++.h>

using namespace std;

int n,k;
int visited[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	visited[n] = 1;
	queue<int> q;
	q.push(n);
	while(q.size()){
		int here = q.front();
		q.pop();
		if(here == k) break; 
		int there = 2*here;
		if(there >= 0 && 200000 >= there && !visited[there]){
			visited[there] = visited[here];
			q.push(there);
		} 
		for(int there : {here-1, here+1}){
			if(there < 0 || 200000 < there) continue;
			if(visited[there]) continue;
			visited[there] = visited[here] + 1;
			q.push(there);
		}
	}
	cout << visited[k] - 1 << "\n";
	
	return 0;
}