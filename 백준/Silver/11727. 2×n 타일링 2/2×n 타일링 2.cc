#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	dp[1] = 1, dp[2] = 3;
	for(int i=3; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2] * 2;
		dp[i] = dp[i] % 10007;
	}
	cout << dp[n] << "\n";
	
	
	return 0;
}