#include <bits/stdc++.h>

using namespace std;

int n,k;
int visited[200005], cnt[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	if(n == k){
		cout << "0\n1\n";
		return 0;
	}
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;
	while(q.size()){
		int x = q.front();
		q.pop();
		for(int nx : {x-1,x+1,2*x}){
			if(nx < 0 || 200000 < nx) continue;
			if(!visited[nx]){
				visited[nx] = visited[x] + 1;
				cnt[nx] += cnt[x];
				q.push(nx);
			} 
			else if(visited[nx] == visited[x] + 1){
				cnt[nx] += cnt[x];
			}
			
		}
	}
	
	cout << visited[k]-1 << "\n";
	cout << cnt[k] << "\n";
	
	return 0;
}