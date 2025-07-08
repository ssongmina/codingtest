#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[15];

void dfs(int d){
	if(d == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i=1; i<=n; i++){
		arr[d] = i;
		dfs(d+1);
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