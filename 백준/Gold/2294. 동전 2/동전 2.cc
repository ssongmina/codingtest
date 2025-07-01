#include <bits/stdc++.h>

using namespace std;

int n,k,a;
int arr[105], dp[10005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	
	fill(dp, dp+10005, 987654321);
	dp[0] = 0;
	for(int i=0; i<n; i++){
		cin >> a;
		for(int j=a; j<=k; j++){
			dp[j] = min(dp[j], dp[j-a]+1);
		}
	}
	
	if(dp[k] == 987654321) cout << "-1\n";
	else cout << dp[k] << "\n";
	
	return 0;
}