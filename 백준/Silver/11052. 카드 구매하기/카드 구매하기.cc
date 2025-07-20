#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1005], arr[1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> dp[i];
		arr[i] = dp[i];
	}
	
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(j-i < 0) continue;
			dp[j] = max(dp[j], dp[j-i] + arr[i]); 

		}
	}
	
	cout << dp[n] << "\n";
	
	return 0;
}