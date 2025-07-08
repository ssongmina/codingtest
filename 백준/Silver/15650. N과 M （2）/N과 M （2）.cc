#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[15];

void dfs(int idx, int cnt){ // 현재 idx , 개수 
	if(cnt == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i=idx+1; i<=n; i++){
		arr[cnt] = i;
		dfs(i, cnt+1);
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	dfs(0, 0); 
	
	return 0;
}