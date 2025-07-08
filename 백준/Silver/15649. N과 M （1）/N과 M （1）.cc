#include <bits/stdc++.h>

using namespace std;

int n,m;
int visited[15], arr[15];

void dfs(int k){
	if(k == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			visited[i] = 1;
			arr[k] = i;
			dfs(k+1);
			visited[i] = 0;
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	dfs(0);
	
	return 0;
}