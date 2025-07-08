#include <bits/stdc++.h>

using namespace std;

int n,m,arr[15], x ,visited[15];
vector<int> brr;

void dfs(int d, int cnt){
	if(cnt == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i=d+1; i<n; i++){	
		arr[cnt] = brr[i];
		dfs(i, cnt+1);
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
	dfs(-1,0);
	
	return 0;
}