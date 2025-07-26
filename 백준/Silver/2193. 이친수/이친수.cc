#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[100][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	dp[1][0] = 0, dp[1][1] = 1;
	dp[2][0] = 1, dp[2][1] = 0;
	dp[3][0] = 1, dp[3][1] = 1;
	for(int i=4; i<=n; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	cout << dp[n][0] + dp[n][1] << "\n";
	
	
	return 0;
}