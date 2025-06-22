#include <bits/stdc++.h>

using namespace std;

int n;
int arr[505][505], dp[505][505];

void go(int idx){
	if(idx >= n){
		return ;
	}
	for(int i=1; i<=idx+1; i++){
		dp[idx+1][i] = max(dp[idx][i-1], dp[idx][i]) + arr[idx+1][i];
	}
	go(idx+1);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<i+1; j++){
			cin >> arr[i][j];
		}
	}
	
	dp[1][1] = arr[1][1];
	go(1);
	
	int mx = 0;
	for(int i=1; i<=n; i++){
		mx = max(dp[n][i], mx);
	}
	cout << mx << "\n";
	
	return 0;
}