#include <bits/stdc++.h>

using namespace std;

int n, dp[1000006];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=2; i<=n; i++){
		dp[i] = dp[i-1]+1;
		if(i % 2 == 0){
			dp[i] = min(dp[i], dp[i/2]+1);
		}
		if(i % 3 == 0){
			dp[i] = min(dp[i], dp[i/3]+1);
		}
	}
	
	cout << dp[n];
	
	return 0;
}