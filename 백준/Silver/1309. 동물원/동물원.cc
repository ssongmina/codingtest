#include <bits/stdc++.h>

using namespace std;

int n;
int dp[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	dp[1] = 3;
	dp[2] = 7; 
	for(int i=3; i<=n; i++){
		dp[i] = (2*dp[i-1] + dp[i-2]) % 9901;
	}
	cout << dp[n] << "\n";
	
	
	return 0;
}