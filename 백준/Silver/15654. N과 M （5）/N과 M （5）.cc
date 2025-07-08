#include <bits/stdc++.h>

using namespace std;

int n,m,arr[15], x ,visited[15];
vector<int> brr;

void dfs(int d){
	if(d == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i=0; i<n; i++){
		if(!visited[i]){
			visited[i] = 1;
			arr[d] = brr[i];
			dfs(d+1);
			visited[i] = 0;
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		brr.push_back(x);
	}
	sort(brr.begin(), brr.end());
	dfs(0);
	
	return 0;
}