#include <bits/stdc++.h>

using namespace std;

int n,k;
int dp[100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1]*i;
	}
	
	cout << dp[n] / (dp[n-k] * dp[k]) << "\n";
	
	return 0;
}