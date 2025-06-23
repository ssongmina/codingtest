#include <bits/stdc++.h>

using namespace std;

int n,k,w[105],v[105];
int dp[105][100005]; 

void ddp(){
	for(int i=1; i<=k; i++){
		for(int j=1; j<=n; j++){
			if(w[j] > i) dp[j][i] = dp[j-1][i];
			else 
				dp[j][i] = max(dp[j-1][i-w[j]] + v[j], dp[j-1][i]);
		}
	}
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> w[i] >> v[i];
	}
	
	for(int i=0; i<=n; i++){
		dp[i][0] = 0;
	}
	for(int j=0; j<=k; j++){
		dp[0][j] = 0;
	}
	
	ddp();
	cout << dp[n][k] << "\n";

	return 0;
}