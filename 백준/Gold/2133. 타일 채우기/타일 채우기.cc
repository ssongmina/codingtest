#include <bits/stdc++.h>

using namespace std;

int n;
int dp[35];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	if(n%2==1){
		cout << 0 << "\n";
		return 0;
	}
	dp[0] = 1, dp[1] = 0, dp[2] = 3;
	for(int i=4; i<=n; i++){
		dp[i] += dp[i-2] * dp[2];
		for(int j=4; j<=i; j+=2){
			dp[i] += dp[i-j] * 2;
		}
	}
	cout << dp[n] << "\n";
	
	return 0;
}